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

		cout << "ћеню:\n\n";

		cout << "1. ScanTable\n";
		cout << "2. SortTable\n"; 
		cout << "3. HashTable\n";
		cout << "4. TreeTable\n";
		cout << "5. BalanceTreeTable\n";

		cout << "\n0. ¬ыход\n" << endl;

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
				   cout << "Ёффективность вставки " << A.GetDataCount() << " записей = " << A.GetEff() << " (в среднем =  " << ((float)A.GetEff() / (float)A.GetDataCount()) << ")" << endl;

				   eff = A.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   A.Find(rec.key);
				   }
				   cout << "Ёффективность поиска =  " << ((float)(A.GetEff() - eff) / 100) << endl;

				   
				   eff = A.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   A.Delete(rec.key);
					   TMP.Delete(rec.key);
				   }
				   cout << "Ёффективность удалени€ = " << ((float)(A.GetEff() - eff) / 100) << endl << endl;
				   cout << "ScanTable после удалени€: (осталось " << A.GetDataCount() << " записей)" << endl;
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
				   cout << "Ёффективности:\n";
				   cout << "Ёффективность вставки " << B.GetDataCount() << " записей = " << B.GetEff() << " (в среднем =  " << ((float)B.GetEff() / (float)B.GetDataCount()) << ")" << endl;

				   eff = B.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   B.Find(rec.key);
				   }
				   cout << "Ёффективность поиска =  " << ((float)(B.GetEff() - eff) / 100) << endl;

				   eff = B.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   B.Delete(rec.key);
					   TMP.Delete(rec.key);
				   }
				   cout << "Ёффективность удалени€ = " << ((float)(B.GetEff() - eff) / 100) << endl << endl;
				   cout << "SortTable после удалени€: (осталось " << B.GetDataCount() << " записей)" << endl;
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
				   cout << "Ёффективности:\n";
				   cout << "Ёффективность вставки  " << C.GetDataCount() << " записей = " << C.GetEff() << " (в среднем  = " << ((float)C.GetEff() / (float)C.GetDataCount()) << ")" << endl;


				   eff = C.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   C.Find(rec.key);
				   }
				   cout << "Ёффективность поиска =  " << ((float)(C.GetEff() - eff) / 100) << endl;
   
					eff = C.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   C.Delete(rec.key);
					   TMP.Delete(rec.key);
				   }
				   cout << "Ёффективность удалени€ = " << ((float)(C.GetEff() - eff) / 100) << endl << endl;
				   cout << "HashTable после удалени€: (осталось " << C.GetDataCount() << " записей)" << endl;
				   C.Print();
				   cout<<endl;

				   int numer = 0;
				   while (numer != 3){
					   cout << "1. ¬ставить слово\n";
					   cout << "2. ”далить слово\n";
					   cout << "3. ¬ыход" << endl;
					   cin >> numer;
					   string str;

					   if (numer == 1)
					   while (str != "!"){
						   cout << "¬ставка " << "¬ведите слово:" << endl;
						   cin >> str;
						   cout << endl;
						   rec.key = str;
						   rec.val = 1;
						   eff = C.GetEff();
						   if (rec.key != "!"){
							   C.Insert(rec);
							   C.Print();
							   cout << endl << "Ёффективность = " << (C.GetEff() - eff) << endl;
						   }
					   }

					   str = "";
					   if (numer == 2)
					   while (str != "!"){
						   cout << "”даление " << "¬ведите слово:" << endl;
						   cin >> str;
						   cout << endl;
						   rec.key = str;
						   rec.val = 1;
						   eff = C.GetEff();
						   C.Delete(rec.key);
						   C.Print();
						   cout << endl << "Ёффективность = " << (C.GetEff() - eff) << endl;
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

				   cout << "Ёффективности:\n";
				   cout << "Ёффективность вставки  " << D.GetDataCount() << " записей = " << D.GetEff() << " (в среднем  = " << ((float)D.GetEff() / (float)D.GetDataCount()) << ")" << endl;

				   eff = D.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   D.Find(rec.key);
				   }
				   cout << "Ёффективность поиска =  " << ((float)(D.GetEff() - eff) / 100) << endl;

				   int numer = 0;
				   while (numer != 3){
					   cout << "1. ¬ставить слово\n";
					   cout << "2. ”далить слово\n";
					   cout << "3. ¬ыход" << endl;
					   cin >> numer;
					   string str;

					   if (numer == 1)
					   while (str != "!"){
						   cout << "¬ставка " << "¬ведите слово:" << endl;
						   cin >> str;
						   cout << endl;
						   rec.key = str;
						   rec.val = 1;
						   eff = D.GetEff();
						   if (rec.key != "!"){
							   D.Insert(rec);
							   D.PrintTree();
							   cout << endl << "Ёффективность = " << (D.GetEff() - eff) << endl;
						   }
					   }

					   str = "";
					   if (numer == 2)
					   while (str != "!"){
						   cout << "”даление " << "¬ведите слово:" << endl;
						   cin >> str;
						   cout << endl;
						   rec.key = str;
						   rec.val = 1;
						   eff = D.GetEff();
						   D.Delete(rec.key);
						   D.PrintTree();
						   cout << endl << "Ёффективность = " << (D.GetEff() - eff) << endl;
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

				   cout << "Ёффективности:\n";
				   cout << "Ёффективность вставки  " << E.GetDataCount() << " записей = " << E.GetEff() << " (в среднем  = " << ((float)E.GetEff() / (float)E.GetDataCount()) << ")" << endl;

				   eff = E.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   E.Find(rec.key);
				   }
				   cout << "Ёффективность поиска =  " << ((float)(E.GetEff() - eff) / 100) << endl;

				   /*eff = E.GetEff();
				   for (int i = 0; i < 100; i++)
				   {
					   rec = TMP.GetMas((rand() % TMP.GetDataCount()));
					   E.Delete(rec.key);
					   TMP.Delete(rec.key);
				   }
				   cout << "Ёффективность удалени€ = " << ((float)(E.GetEff() - eff) / 100) << endl << endl;
				   cout << "BalanceTreeTable после удалени€: (осталось " << E.GetDataCount() << " записей)" << endl;
				   E.PrintTree();*/

				   	
				   int numer = 0;
				   while (numer != 3){
					   cout << "1. ¬ставить слово\n";
					   cout << "2. ”далить слово\n";
					   cout << "3. ¬ыход" << endl;
					   cin >> numer;
					   string str;

					   if (numer == 1)
					   while (str != "!"){
						   cout << "¬ставка " << "¬ведите слово:" << endl;
						   cin >> str;
						   cout << endl;
						   rec.key = str;
						   rec.val = 1;
						   eff = E.GetEff();
						   if (rec.key != "!"){
							   E.Insert(rec);
							   E.PrintTree();
							   cout << endl << "Ёффективность = " << (E.GetEff() - eff) << endl;
						   }
					   }

					   str = "";
					   if (numer == 2)
					   while (str != "!"){
						   cout << "”даление " << "¬ведите слово:" << endl;
						   cin >> str;
						   cout << endl;
						   rec.key = str;
						   rec.val = 1;
						   eff = E.GetEff();
						   E.Delete(rec.key);
						   E.PrintTree();
						   cout << endl << "Ёффективность = " << (E.GetEff() - eff) << endl;
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

