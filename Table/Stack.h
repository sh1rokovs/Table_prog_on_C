#pragma once

#include "stdafx.h"
#include <iostream>

using namespace std;

template <class T>

class Stack{
private:
	T *mas;// массив
	int maxsize;// максимальный размер
	int pos;// текущая позиция
public:
	//
	// Конструктор
	//
	Stack(int _maxsize=100){
		maxsize=_maxsize;
		mas=new T [maxsize];
		pos=-1;
	}
	//
	// Деструктор
	//
	~Stack(){
		delete[] mas;
	}
	//
	// Конструктор копирования
	//
	Stack(Stack& st){
		maxsize=st.maxsize;
		mas=new T [maxsize];
		for (int i=0;i<maxsize;i++)
			mas[i]=st.mas[i];
		pos=st.pos;
	}
	//
	// Оператор присваивания
	//
	Stack& operator = (const Stack& st){
		if(maxsize!=st.maxsize){ 
			maxsize=st.maxsize;
			delete [] mas;
			mas=new T [maxsize];
		}
		for (int i=0;i<maxsize;i++)
			mas[i]=st.mas[i];
			pos=st.pos;
	}
	//
	// Проверка на переполнение
	//
	int full(){
		if(pos==maxsize-1) return 1;
		return 0;
	}
	//
	// Проверка на пустоту
	//
	int empty(){
		return (pos==-1);
	}
	//
	// Добавить элемент в стэк
	//
	void push(T el){
		mas[pos+1]=el;// новый элемент кладем в стек
		pos++;//переводим позицию на новый элемент
	}
	//
	// Изъять элемент с вершины стэка
	//
	T pop(){
		return mas[pos--];//возвращаем значение на вершине стека и уменьшаем позицию
	}
	//
	// Посмотреть элемент на вершине стэка
	//
	T top(){
		return mas[pos];//возвращаем значение на вершине стека
	}
	//
	// Очистка стэка
	//
	void clear(){
		pos=-1;
	}
};