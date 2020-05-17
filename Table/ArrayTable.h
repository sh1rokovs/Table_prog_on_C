#pragma once

#include "Tables.h"


	/*Базовый класс для таблиц, реализованных на массиве*/

class TArrayTable:public TTable{
protected:
	TRecord *mas;	// Массив для хранения записей
	int MaxSize;	// Размер массива(выделено памяти)
	int Curr;		// Текущая позиция(индекс)
public:
	//
	// Конструктор
	//
	TArrayTable (int _MaxSize = 1000){
		MaxSize = _MaxSize;
		Curr = -1;
		mas = new TRecord[MaxSize];
	}
	//
	// Деструктор
	//
	~TArrayTable(){
		delete[] mas;
	}

		/*Проверки*/
	
	//
	// Проверка на полноту
	//
	virtual bool IsFull() const{
		return DataCount == MaxSize;
	}

		/*Доступ к полям*/
	
	//
	// Вернуть текущую запись
	//
	virtual TRecord GetCurr() const{
		if (Curr >= 0 && Curr < MaxSize)
			return mas[Curr];
	}

		/*Итератор*/
	
	//
	// Сброс на первую строку таблицы
	//
	virtual void Reset(){
		Curr = 0;
	}
	//
	// Проверка на конец таблицы
	//
	virtual bool IsEnd(){
		return DataCount == Curr;
	}
	//
	// Переход на следующую строку таблицы
	//
	virtual void GoNext(){
		Curr++;
	}
};