#include "stdafx.h"
#include "SortTable.h"
#include "ScanTable.h"
#include "HashTable.h"
#include "TreeTable.h"
#include "BalTreeTable.h"
#include "Math.h"
#include "stdlib.h"
#include "time.h"

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	int number = 0;
	while (number != 7)
	{
		
		setlocale(LC_ALL, "Russian");

		cout << "����:\n\n";

		cout << "1. ScanTable\n";
		cout << "2. SortTable\n"; 
		cout << "3. HashTable\n";
		cout << "4. TreeTable\n";
		cout << "5. BalanceTreeTable\n";

		cout << "\n0. �����\n" << endl;

		cin >> number;

		switch (number)
		{
			case 1:
			{
				   TScanTable A(1000), TMP(1000);
				   int eff = 0;
				   TRecord rec;
				   TMP.Read("Text.txt");
				   A.Read("Text.txt");
				   eff = A.GetEff();

				   cout << "ScanTable:" << endl << endl;
				   A.Print();

				   cout << endl;
				   cout << "������������� ������� " << A.GetDataCount() << " ������� = " << A.GetEff() << " (� ������� =  " << ((float)A.GetEff() / (float)A.GetDataCount()) << ")" << endl;

				   eff = A.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   A.Find(rec.key);
				   }
				   cout << "������������� ������ =  " << ((float)(A.GetEff() - eff) / 100) << endl;

				   
				   eff = A.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   A.Delete(rec.key);
					   TMP.Delete(rec.key);
				   }
				   cout << "������������� �������� = " << ((float)(A.GetEff() - eff) / 100) << endl << endl;
				   cout << "ScanTable ����� ��������: (�������� " << A.GetDataCount() << " �������)" << endl;
				   A.Print();

				   cout << endl;
				   break;
			}
			case 2:
			{
				   TSortTable B(1000);
				   TScanTable TMP(1000);
				   int eff = 0;
				   TRecord rec;
				   TMP.Read("Text.txt");
				   B.Read("Text.txt");

				   cout << "SortTable:" << endl << endl;
				   B.Print();

				   cout << endl;
				   cout << "�������������:\n";
				   cout << "������������� ������� " << B.GetDataCount() << " ������� = " << B.GetEff() << " (� ������� =  " << ((float)B.GetEff() / (float)B.GetDataCount()) << ")" << endl;

				   eff = B.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   B.Find(rec.key);
				   }
				   cout << "������������� ������ =  " << ((float)(B.GetEff() - eff) / 100) << endl;

				   eff = B.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   B.Delete(rec.key);
					   TMP.Delete(rec.key);
				   }
				   cout << "������������� �������� = " << ((float)(B.GetEff() - eff) / 100) << endl << endl;
				   cout << "SortTable ����� ��������: (�������� " << B.GetDataCount() << " �������)" << endl;
				   B.Print();
				   cout << endl;
				   break;
			}
			case 3:
			{
				   TArrayHashTable C(1000,10);
				   TScanTable TMP(1000);
				   int eff = 0;
				   TRecord rec;
				   TMP.Read("Text.txt");
				   C.Read("Text.txt");

				   cout << "HashTable:" << endl << endl;
				   C.Print();

				   cout << endl;
				   cout << "�������������:\n";
				   cout << "������������� �������  " << C.GetDataCount() << " ������� = " << C.GetEff() << " (� �������  = " << ((float)C.GetEff() / (float)C.GetDataCount()) << ")" << endl;


				   eff = C.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   C.Find(rec.key);
				   }
				   cout << "������������� ������ =  " << ((float)(C.GetEff() - eff) / 100) << endl;
   
					eff = C.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   C.Delete(rec.key);
					   TMP.Delete(rec.key);
				   }
				   cout << "������������� �������� = " << ((float)(C.GetEff() - eff) / 100) << endl << endl;
				   cout << "HashTable ����� ��������: (�������� " << C.GetDataCount() << " �������)" << endl;
				   C.Print();
				   cout<<endl;

				   int numer = 0;
				   while (numer != 3){
					   cout << "1. �������� �����\n";
					   cout << "2. ������� �����\n";
					   cout << "3. �����" << endl;
					   cin >> numer;
					   string str;

					   if (numer == 1)
					   while (str != "!"){
						   cout << "������� " << "������� �����:" << endl;
						   cin >> str;
						   cout << endl;
						   rec.key = str;
						   rec.val = 1;
						   eff = C.GetEff();
						   if (rec.key != "!"){
							   C.Insert(rec);
							   C.Print();
							   cout << endl << "������������� = " << (C.GetEff() - eff) << endl;
						   }
					   }

					   str = "";
					   if (numer == 2)
					   while (str != "!"){
						   cout << "�������� " << "������� �����:" << endl;
						   cin >> str;
						   cout << endl;
						   rec.key = str;
						   rec.val = 1;
						   eff = C.GetEff();
						   C.Delete(rec.key);
						   C.Print();
						   cout << endl << "������������� = " << (C.GetEff() - eff) << endl;
					   }
				   }
					
				   cout << endl;
				   break;
		}
		case 4:{
				   TTreeTable D;
				   TScanTable TMP(1000);
				   int eff = 0;
				   TRecord rec;
				   TMP.Read("Text.txt");

				   D.Read("Text.txt");
				   cout << "TreeTable" << endl << endl;
				   D.PrintTree();

				   cout << "�������������:\n";
				   cout << "������������� �������  " << D.GetDataCount() << " ������� = " << D.GetEff() << " (� �������  = " << ((float)D.GetEff() / (float)D.GetDataCount()) << ")" << endl;

				   eff = D.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   D.Find(rec.key);
				   }
				   cout << "������������� ������ =  " << ((float)(D.GetEff() - eff) / 100) << endl;

				   int numer = 0;
				   while (numer != 3){
					   cout << "1. �������� �����\n";
					   cout << "2. ������� �����\n";
					   cout << "3. �����" << endl;
					   cin >> numer;
					   string str;

					   if (numer == 1)
					   while (str != "!"){
						   cout << "������� " << "������� �����:" << endl;
						   cin >> str;
						   cout << endl;
						   rec.key = str;
						   rec.val = 1;
						   eff = D.GetEff();
						   if (rec.key != "!"){
							   D.Insert(rec);
							   D.PrintTree();
							   cout << endl << "������������� = " << (D.GetEff() - eff) << endl;
						   }
					   }

					   str = "";
					   if (numer == 2)
					   while (str != "!"){
						   cout << "�������� " << "������� �����:" << endl;
						   cin >> str;
						   cout << endl;
						   rec.key = str;
						   rec.val = 1;
						   eff = D.GetEff();
						   D.Delete(rec.key);
						   D.PrintTree();
						   cout << endl << "������������� = " << (D.GetEff() - eff) << endl;
					   }
				   }

				   cout << endl;
				   break;
		}
		case 5:{
				   TBalTreeTable E;
				   TScanTable TMP(1000);

				   int eff = 0;
				   TRecord rec;
				   TMP.Read("Text.txt");

				   E.Read("Text.txt");
				   cout << "BalanceTreeTable" << endl << endl;
				   E.PrintTree();

				   cout << "�������������:\n";
				   cout << "������������� �������  " << E.GetDataCount() << " ������� = " << E.GetEff() << " (� �������  = " << ((float)E.GetEff() / (float)E.GetDataCount()) << ")" << endl;

				   eff = E.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   E.Find(rec.key);
				   }
				   cout << "������������� ������ =  " << ((float)(E.GetEff() - eff) / 100) << endl;

				   /*eff = E.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   E.Delete(rec.key);
					   TMP.Delete(rec.key);
				   }
				   cout << "������������� �������� = " << ((float)(E.GetEff() - eff) / 100) << endl << endl;
				   cout << "BalanceTreeTable ����� ��������: (�������� " << E.GetDataCount() << " �������)" << endl;
				   E.PrintTree();*/

				   	
				   int numer = 0;
				   while (numer != 3){
					   cout << "1. �������� �����\n";
					   cout << "2. ������� �����\n";
					   cout << "3. �����" << endl;
					   cin >> numer;
					   string str;

					   if (numer == 1)
					   while (str != "!"){
						   cout << "������� " << "������� �����:" << endl;
						   cin >> str;
						   cout << endl;
						   rec.key = str;
						   rec.val = 1;
						   eff = E.GetEff();
						   if (rec.key != "!"){
							   E.Insert(rec);
							   E.PrintTree();
							   cout << endl << "������������� = " << (E.GetEff() - eff) << endl;
						   }
					   }

					   str = "";
					   if (numer == 2)
					   while (str != "!"){
						   cout << "�������� " << "������� �����:" << endl;
						   cin >> str;
						   cout << endl;
						   rec.key = str;
						   rec.val = 1;
						   eff = E.GetEff();
						   E.Delete(rec.key);
						   E.PrintTree();
						   cout << endl << "������������� = " << (E.GetEff() - eff) << endl;
					   }
				   }			  
				   cout << endl;

				   break;
		}

		}
	}

		system("pause");
		return 0;
}

