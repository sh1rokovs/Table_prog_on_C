#pragma once

#include "ArrayTable.h"

	/*Класс таблиц на неупорядоченном массиве*/

class TScanTable:public TArrayTable{
public:
	//
	// Конструктор
	//
	TScanTable(int _MaxSize = 1000):TArrayTable(_MaxSize){}
	//
	// Деструктор
	//
	~TScanTable(){}

		/*Доступ к полям*/
	
	//
	// Вернуть максимальный размер массива
	//
	int GetMaxSize(){
		return MaxSize;
	}
	//
	// Вернуть запись массива на i позиции
	//
	TRecord GetMas(int i){
		if ((i >= 0) && (i < MaxSize)){
			return mas[i];
		}
	}
	
		/*Операции над записями*/

	//
	// Поиск записи
	//
	virtual bool Find(TKey _key){
		for(int i = 0; i < DataCount; i++){
			Eff++;
			if (mas[i].key == _key){
				Curr = i;
				return true;
			}
		}
		Curr = DataCount;
		return false;
	}
	//
	// Удаление записи
	//
	virtual void Delete(TKey _key){
		if (Find(_key)){
			DataCount--;
			Eff++;
			mas[Curr] = mas[DataCount];
		}
	}
	//
	// Вставка записи
	//
	virtual void Insert(TRecord rec){
		if(IsFull()) return;
		if(!Find(rec.key)){
			mas[Curr] = rec;
			//mas[Curr].key = rec.key;
			//mas[Curr].val = rec.val;
			DataCount++;
			Eff++;
		}
		else
		{
			mas[Curr].val++;
		}
	}
};