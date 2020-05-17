#pragma once

#include "Tables.h"
#include "Stack.h"

	/*Звено*/

class Node{
public:
	Node *pLeft, *pRight; // указатели налево и направо от текущей вершины дерева
	TRecord rec; // запись в текущем звене
	int balanse; // баланс вершины дерева
	//
	// Конструктор
	//
	Node(TRecord _rec){
		pLeft = NULL;
		pRight = NULL;
		rec = _rec;
		balanse = 0;
	}
};

	/*Таблицы, на основе бинарных деревьев*/

class TTreeTable :public TTable{
protected:
	Node* pRoot; // указатель на корень
	Node* pCurr; // указатель на текущее звено
	Node **pRes; // адрес указателя для вставки и удаления
	Stack <Node*> st; // стэк указателей на звенья
	int CurrPos; // позиция для итератора 
public:
	//
	// Конструктор
	//
	TTreeTable(){
		pRoot = NULL;
		pCurr = NULL;
		st.clear();
	}
	//
	// Деструктор
	//
	~TTreeTable(){
		DelSTree(pRoot);
	}
	//
	// Удалить поддерево(рекурсия)
	//
	void DelSTree(Node *p){
		if (p != NULL){
			DelSTree(p->pLeft);
			DelSTree(p->pRight);
			delete p;
		}
		return;
	}
	//
	// Получиь текущую запись
	//
	virtual TRecord GetCurr() const{
		return (pCurr->rec);
	}

		/*Проверки*/

	//
	// Проверка на полноту
	//
	virtual bool IsFull() const{
		return false;
	}
	
		/*Операции над записями*/
	
	//
	// Поиск
	//
	virtual bool  Find(TKey _key){
		Node *tmp = pRoot;
		pRes = &pRoot;
		while (tmp != NULL){
			Eff++;
			if ((tmp->rec.key) == _key)
				return true;
			else{
				if ((tmp->rec.key) < _key){
					pRes = &(tmp->pLeft);
					tmp = (tmp->pLeft);
				}
				else{
					pRes = &(tmp->pRight);
					tmp = (tmp->pRight);
				}
			}
		}
		return false;
	}
	//
	// Вставка
	//
	virtual void Insert(TRecord rec){
		//if (IsFull()) return;
		if (!Find(rec.key)){
			DataCount++;
			Node *tmp = new Node(rec);
			*pRes = tmp;
		}
		else{
			(*pRes)->rec.val++;
		}
	} 
	//
	// Удаление
	//
	virtual void Delete(TKey Key)
	{
		if(!Find(Key))
			return;
		else
		{
			Node* pNode=*pRes;
			Node* tmp=*pRes;
			Node* pMax=*pRes;
			if(tmp->pLeft==NULL)
			{
				Eff++;
				*pRes=tmp->pRight;
				delete tmp;
				return;
			}
			else
				if(tmp->pRight==NULL)
				{
					Eff++;
					*pRes=tmp->pLeft;
					delete tmp;
					return;
				}
				else
				{
					Eff++;
					pMax=pMax->pLeft;
					if(pMax->pRight==NULL)
						pNode=pMax->pLeft;
					else
					{
						while(pMax->pRight!=NULL)
						{
							Eff++;
							tmp=pMax;
							pMax=pMax->pRight;
						}
						pNode->rec=pMax->rec;
						tmp->pRight=pMax->pLeft;
					 }
				}
			delete pMax;
			DataCount--;
		}
	}

	//
	// Сброс на первую запись
	//
	virtual void Reset(){
		pCurr = pRoot;
		st.clear();
		CurrPos = 0;
		do{
			st.push(pCurr);
			pCurr = (pCurr->pLeft);
		} while (pCurr != NULL);
		pCurr = st.top();
	}
	//
	// Проверка на конец записей
	//
	virtual bool IsEnd(){
		return (CurrPos == DataCount);
	}
	//
	// Переход на следующую запись(звено)
	//
	virtual void GoNext(){
		st.pop();
		pCurr = (pCurr->pRight);
		while (pCurr != NULL){
			st.push(pCurr);
			pCurr = (pCurr->pLeft);
		}
		if (!st.empty()){
			pCurr = st.top();
		}
		CurrPos++;
	}
	
	void PrintTreeTable(Node *p, int lvl){
		if (p != NULL){
			PrintTreeTable((p->pRight), (lvl + 1));
			for (int i = 0; i < (2 * lvl); i++){
				cout << " ";
			}
			cout << p->rec.key << " - " << p->rec.val << endl;
			PrintTreeTable((p->pLeft), (lvl + 1));
		}
	}

	void PrintTree(){
		PrintTreeTable(this->pRoot, 0);
	}
};