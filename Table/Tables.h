#pragma once

#include <string>
#include <iostream>
#include <fstream>


using namespace std;

//typedef int TKey;
typedef string TKey;
typedef int TValue;


	/*Структура для хранения записи*/

struct TRecord{
	TKey key;  //Ключ
	TValue val; // значение(число раз встречаемости ключей)
};


	/*Базовый класс для таблиц*/

class TTable{
protected:
	int DataCount;	  // число записей
	int Eff;          // эффективность
public:
	//
	// Конструктор
	//
	TTable () {
		Eff = 0;
		DataCount = 0;
	}
	//
	// Деструктор
	//
	~TTable() {}
		
		/*Доступ к полям*/

	//
	// Вернуть значение числа записей
	//
	int GetDataCount(){
		return DataCount;
	}
	//
	// Вернуть значение эффективности
	//
	int GetEff(){
		return Eff;
	}

	//
	// Вернуть текущую запись
	//
	virtual TRecord GetCurr() const = 0;

		/*Проверки*/

	//
	// Проверка на пустоту
	//
	bool IsEmpty(){
		return DataCount == 0;
	}
	//
	// Проверка на переполнение
	//
	virtual bool IsFull() const = 0;
	
		/*Операции над записями*/

	//
	// Поиск записи
	//
	virtual bool Find(TKey key) = 0;
	//
	// Вставка записи
	//
	virtual void Insert(TRecord rec) = 0;
	//
	// Удаление записи
	//
	virtual void Delete(TKey key) = 0;
	
		/*Итератор*/

	//
	// Переход на следующую строку таблицы
	//
	virtual void GoNext() = 0;
	//
	// Сброс на первую строку таблицы 
	//
	virtual void Reset() = 0;
	//
	// Проверка на конец таблицы
	//
	virtual bool IsEnd() = 0;
	
		/*Служебные функции*/
	
	//
	// Печать таблицы
	//
	void Print(){
		for (Reset(); !IsEnd(); GoNext())
		{
			cout << GetCurr().key << "  -  " << GetCurr().val << endl;
		}
	}
	//
	// Чтение из файла
	//
	void Read(char* pFileName)
	{
		string str = "";
		ifstream TxtFile(pFileName);

		if (!TxtFile.fail())
		{
			while (!TxtFile.eof()) str += TxtFile.get();
			TxtFile.close();
		}
		else cout << "File does not exist" << endl;

		for (int i = 0; i < str.length(); i++)
		{
			char tmp = str[i];
			if (((int)tmp >= 65) && ((int)tmp <= 90))
			{
				tmp += 32;
			}
			str[i] = tmp;
		}
		
		string tmp = "";
		TRecord rec;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				rec.key = tmp;
				rec.val = 1;
				Insert(rec);
				tmp = "";
			}
			else
			{
				tmp += str[i];
			}
		}
	}
};