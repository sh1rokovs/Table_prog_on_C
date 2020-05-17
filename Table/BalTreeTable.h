#pragma once

#include "TreeTable.h"

class TBalTreeTable : public TTreeTable
{
public:
	int InsBalTree(Node *&p, TRecord rec)
	{
		// ��� �-��� ���������� ��������� ������ � ������� ���������
		int res=0;
		Eff++;
		

		if(p==NULL)
		{
			p=new Node(rec);
			DataCount++;
			return 1;//��������� ��������� ������
		}
		else
			if(rec.key>p->rec.key)// rec.key>p->Rec.key
			{
				res=InsBalTree(p->pRight,rec); //���� ������ 1, �� ���� ����������� � ������ ����� ������ ������������
					//����� p. ��� ��������, ��� ����� ��������� ������������ ������ �����
				if(res==1)
					res=Rightbalanseance(p);
			}
			else
				if(rec.key<p->rec.key)//rec.key<p->Rec.key
				{
					res=InsBalTree(p->pLeft,rec); //���� ������ 1, �� ���� ����������� � ����� ����� ������ ������������
					//����� p. ��� ��������, ��� ����� ��������� ������������ ����� �����
					if(res==1)
						res=Leftbalanseance(p);
				}
				else//���� ����� �������
					return 0;
		return res;
	}

	void Insert(TRecord rec)
	{
		InsBalTree(pRoot, rec);
	}

	int Leftbalanseance(Node *&p)
	{
		if(p->balanse==1)//����� ������������ �� �����
		{
			p->balanse=0;
			return 0;
		}
		if(p->balanse==0)//�������� �� ����� �� ����, � �.�. ��������� �����, �� ����� ����� ������� �����
		{
			p->balanse=-1;
			return 1;
		}
		if(p->balanse==-1)//������� ��� �����
		{
			if(p->pLeft->balanse==-1)
			// 1�� ������
			{
				Node* tmp=p->pLeft;// ��������� �����
				p->pLeft=tmp->pRight;
				tmp->pRight=p;
				p->balanse=0;
				p=tmp;
				p->balanse=0;
				return 0;
			}
			//2�� ������
			else
			{
				Node* tmp1=p->pLeft;
				Node* tmp2=tmp1->pRight;
				tmp1->pRight=tmp2->pLeft;
				tmp2->pLeft=tmp1;
				p->pLeft=tmp2->pRight;
				tmp2->pRight=p;
				if(tmp2->balanse==-1)
					p->balanse=1;
				else
					p->balanse=0;
				if(tmp2->balanse==1)
					tmp1->balanse=-1;
				else
					tmp1->balanse=0;
				p=tmp2;
				p->balanse=0;
				return 0;
			}

		}
	}

	int Rightbalanseance(Node *&p)
	{
		if(p->balanse==-1)//����� ������������ �� �����
		{
			p->balanse=0;
			return 0;
		}
		if(p->balanse==0)//�������� �� ����� �� ����, � �.�. ��������� �����, �� ����� ����� ������� �����
		{
			p->balanse=1;
			return 1;
		}
		if(p->balanse==1)//������� ��� ������
		{
			if(p->pRight->balanse==1)
			// 1�� ������
			{
				Node* tmp=p->pRight;// ��������� �����
				p->pRight=tmp->pLeft;
				tmp->pLeft=p;
				p->balanse=0;
				p=tmp;
				p->balanse=0;
				return 0;
			}
			//2�� ������
			else
			{
				Node* tmp1=p->pRight;
				Node* tmp2=tmp1->pLeft;
				tmp1->pLeft=tmp2->pRight;
				tmp2->pRight=tmp1;
				p->pRight=tmp2->pLeft;
				tmp2->pLeft=p;
				if(tmp2->balanse==1)
					p->balanse=-1;
				else
					p->balanse=0;
				if(tmp2->balanse==-1)
					tmp1->balanse=1;
				else
					tmp1->balanse=0;
				p=tmp2;
				p->balanse=0;
				return 0;
			}
		}
	}

	int DelBalTree(Node *&p, TKey Key)
	{
		int res;

		if(p->rec.key<Key)
		{
			Eff++;
			res=DelBalTree(p->pRight,Key);
			if(res!=0)
				res=Leftbalanseance(p);
		}
		else
			if(p->rec.key>Key)
			{
				Eff++;
				res=DelBalTree(p->pLeft,Key);
				if(res!=0)
					res=Rightbalanseance(p);
			}
			else
			{
				if(p->rec.key == Key)
				{
					Node* tmp=p;
					if(p->pLeft==NULL)
					{
						Eff++;
						p=p->pRight;
						res=1;
					}
					else
						if(p->pRight==NULL)
						{
							Eff++;
							p=p->pLeft;
							res=1;
						}
						//����� ��� ��������� �� ����� ����
						else
						{
							Node* pMax=FindMax(p->pLeft);
							p->rec=pMax->rec;
							res=RemoveMax(p->pLeft);
							if(res)
								res=Leftbalanseance(p);
							tmp=pMax;
						}
						delete tmp;
						DataCount--;
				}
				return res;
		}
	}

	// �������� ����
	void Delete(TKey Key)
	{
		DelBalTree(pRoot, Key);
	}

	Node* FindMax(Node *p)
	{
		if(p->pRight!=NULL)
		{
			Eff++;
			return FindMax(p->pRight);
		}
		else
			return p;
	}

	// ��������� ��������
	int RemoveMax(Node* &p)
	{
		int res;
		if(p->pRight==NULL)
		{
			Eff++;
			p=p->pLeft; // ��������� �� ������ ��� �������
			res=1;
		}
		else
		{
			res=RemoveMax(p->pRight);
			if(res)// ���� � ������� ��������� ����������� ������
				res=Leftbalanseance(p);
		}
		return res;
	}
};
