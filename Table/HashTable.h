#pragma once

#include <string>
#include <iostream>
#include "Tables.h"

using namespace std;

class TArrayHashTable :public TTable{
private:
	TRecord* mas;
	int MaxSize;
	int Curr;
	int Step;
	int CurrPoss;
	
	int HashFunc(TKey _key)
	{
		int Sum = 0;
		for (int i = 0; i < _key.length(); i++)
			Sum+=(int)(_key[i])*(_key.length()-i);

		return (Sum % MaxSize);
	}
public:
	TArrayHashTable(int _MaxSize = 1000, int _Step = 10){
		MaxSize = _MaxSize;
		Step = _Step;
		mas = new TRecord[MaxSize];
		Curr = -1;
		CurrPoss = 0;
		for (int i = 0; i<MaxSize; i++)
			mas[i].key = "";
	}

	~TArrayHashTable(){
		delete[] mas;
	}

	virtual TRecord GetCurr() const{
		return mas[Curr];
	}

		/*Проверки*/

	//
	// Проверка на переполнение
	//
	virtual bool IsFull() const {
		return (DataCount == MaxSize);
	}

		/*Операции над записями*/

	//
	// Поиск записи
	//
	virtual bool Find(TKey key){
		int tmp = -1;
		Curr = HashFunc(key);
		for (int i = 0; i<MaxSize; i++){
			Eff++;
			if (mas[Curr].key == ""){
				if (tmp != -1)
					Curr = tmp;
				return false;
			}
			else{
				if ((mas[Curr].key == "***") && (tmp == -1))
					tmp = Curr;
				else{
					if (mas[Curr].key == key)
						return true;
				}
			}
			Curr = ((Curr + Step) % MaxSize);// Делаем шаг
		}
	}
	//
	// Вставка записи
	//
	virtual void Insert(TRecord rec){
		if (!IsFull()){
			if (!Find(rec.key)){
				Eff++;
				mas[Curr] = rec;
				DataCount++;
			}
		}
	}
	//
	// Удаление записи
	//
	virtual void Delete(TKey key){
		if (!IsEmpty()){
			if (Find(key)){
				Eff++;
				mas[Curr].key = "***";
				DataCount--;
			}
		}
	}

		/*Итератор*/

	//
	// Переход на следующую строку таблицы
	//
	virtual void GoNext(){
		CurrPoss++;
		int i = 0;
		for (i = (Curr + 1); i < MaxSize; i++){
			if (((mas[i].key) != "") && ((mas[i].key) != "***")){
				Curr = i;
				break;
			}
		}
			if (i == MaxSize)
				Curr = i;// Установить Curr в конец
	}
	//
	// Сброс на первую строку таблицы 
	//
	virtual void Reset(){
		CurrPoss = 0;
		for (int i = 0; i < MaxSize; i++){
			if (((mas[i].key) != "") && ((mas[i].key) != "***")){
				Curr = i;
				break;
			}
		}
	}
	//
	// Проверка на конец таблицы
	//
	virtual bool IsEnd(){
		//return (CurrPoss == DataCount);
		return Curr == MaxSize;
	}


	void PrintTMP(){
		for (int i = 0; i < MaxSize; i++)
			cout << mas[i].key << " - " << mas[i].val << endl;
	}
};
