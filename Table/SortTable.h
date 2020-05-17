#pragma once

#include "ScanTable.h"

	/*Класс таблиц на упорядоченном массиве*/

class TSortTable:public TScanTable{
public:
	//
	// Конструктор
	//
	TSortTable (int _MaxSize = 1000):TScanTable(_MaxSize){}
	//
	// Конструктор из неупоядоченной таблицы
	//
	TSortTable(TScanTable& st){
		MaxSize = st.GetMaxSize();
		mas = new TRecord[MaxSize];
		for ( int i = 0; i < DataCount; i++){
			mas[i] = st.GetMas(i);
		}
		QSort();
	}

		/*Сортировка для перевода*/
	
	//
	// Вызов сортировки для всех записей в таблице
	//
	void QSort(){
		QSortRec(0, (DataCount - 1) );
	}
	//
	// Алгоритм быстрой сортировки(рекурсия)
	//
	void QSortRec(int lf, int rt){
		TKey x = mas[lf].key;
		int i = lf, j = rt;
		while ( i <= j){
			while ( mas[i].key < x ){
				Eff++;
				i++;
			}
			while ( mas[j].key > x){
				Eff++;
				j--;
			}
			if ( i <= j){
				TRecord tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;
				i++; 
				j--;
				Eff++;
			}
		}
		if ( j > lf){
			QSortRec(lf,j);
		}
		if ( i < rt){
			QSortRec(i,rt);
		}
	}
	
		/*Операции над записями*/

	//
	// Поик записи
	//
	virtual bool Find(TKey _key){
		int first = 0, last = (DataCount - 1), mid = 0;
		while(first <= last){
			Eff++;
			mid = (first + last) / 2;
			if (mas[mid].key == _key){
				Curr = mid;
				return true;
			}
			if (mas[mid].key < _key){
				first = (mid + 1);
			}
			else{
				last = (mid - 1);
			}
		}
		Curr = first;
		return false;
	}
	//
	// Вставка записи
	//
	virtual void Insert(TRecord rec){
		if(IsFull()) return;
		if(!Find(rec.key)){
			for(int i = (DataCount - 1); i >= Curr; i--){
				Eff++;
				mas[i+1] = mas[i];
			}
			mas[Curr] = rec;
			DataCount++;
		}
		else
		{
			mas[Curr].val++;
		}
	}
	//
	// Удаление записи
	//
	virtual void Delete(TKey _key){
		if(Find(_key)){
			for(int i = Curr; i < DataCount; i++){
				mas[i] = mas[i+1];
				Eff++;
			}
			DataCount--;
		}
	}
};