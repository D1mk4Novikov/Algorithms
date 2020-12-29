//
// Array.h
// Created by Dimka Novikov on 3.11.2020.

#ifndef _Array_hpp_
#define _Array_hpp_


#pragma once

//#include "./Array.cpp"

#include <iostream>
#include <cstdlib>
//#include "malloc.h"

// АТД Динамический массив
template<typename ElementType>
class Array final {
	
	class Iterator final {
		
		friend class Array<ElementType>;
		
	private:
		// текущий индекс
		int index;
		// массив
		Array<ElementType> &array;
		
	public:
		// конструктор
		Iterator(Array<ElementType> &array);
		// получение значения массива в текущей позиции итератора
		const ElementType &get() const;
		// задание значения массива в текущей позиции итератора
		void set(const ElementType &value);
		// вставка значения в текущей позиции итератора(без сдвига указателя)
		void insert(const ElementType &value);
		// удаление без сдвига итератора (на позиции удаленного элементе)
		void remove();
		// перемещение итератора на 1 поз вправо
		void next();
		// перемещение итератора на 1 поз влево
		void previous();
		// перемещение итератора на элемент с заданным индексом
		void toIndex(int index);
		// наличие след элемента
		bool hasNext() const;
		// наличие пред элемента
		bool hasPrevious() const;
		
	};
	
	
private:
	// текущий размер чтобы не пересчитывать
	int currentSize;
	// количество элементов
	int count;
	// ссылка на массив
	ElementType *array;
	// приватная функция по выделению памяти под новый элемент массива
	void increaseSize();
	
public:
	// пустой конуструктор (размер 8 или 16) дефолтный
	Array();
	// конструктор с размерностью = capacity
	Array(int capacity);
	// леструктор класса с вызовом деструктора хранимых элементов при необходимости
	~Array();
	
	// вставка жлемента в конец массива
	void insert(const ElementType &value);
	// вставка элемента в позиции index с последующим сдвигом элементов вправо
	void insert(const ElementType &value, int index);
	// удаление элемента по индексу
	void remove(int index);
	// возвращает текущий размер (количество существующих элементов может быть выделено памяти больше но реально заполнен массив лишь частично, нужен каунтер)
	int size() const;
	// общее количество элементов массива
	int capacity();
	// оператор индексирования (поиндексная запись и чтение элемента массива)
	const ElementType &operator [] (int index) const;
	ElementType &operator [] (int index);
	
	// MARK: - Итератор
	// механизм копирования
	const Iterator iterator() const {
		Iterator iterator(*this);
		return iterator;
	}
	Iterator iterator() {
		Iterator iterator(*this);
		return iterator;
	}
	
};


// Дефолтный конструктор с дефолтным размером в 8 позиций для элементов
template<typename ElementType>
Array<ElementType>::Array() {
//	this -> array = new ElementType[8];
	this -> array = (ElementType *)std::malloc(8 * sizeof(ElementType));
//	this -> array = new ElementType[50];
//	this -> array = (ElementType *)malloc(8 * sizeof(ElementType));
	this -> count = 0;
	this -> currentSize = 8;
}

// кастомный конструтор
template <typename ElementType>
Array<ElementType>::Array(int capacity) {
//	this -> array = new ElementType[capacity];
	this -> array = (ElementType *)std::malloc(capacity * sizeof(ElementType));
	this -> count = 0;
	this -> currentSize = capacity;
}

// деструктор
template <typename ElementType>
Array<ElementType>::~Array() {
	delete this -> array;
}


// Функция увеличения размера массива
template<typename ElementType>
void Array<ElementType>::increaseSize() {
	
	ElementType *temporaryValue = NULL;
	
	if (this -> count == this -> currentSize) {
//		temporaryValue = new ElementType[this -> currentSize * 2];
		temporaryValue = (ElementType *)std::malloc(this -> currentSize * 2 * sizeof(ElementType));
		std::move(this -> array, this -> array + this -> count, temporaryValue);
	}
	
	delete this -> array;
	this -> array = temporaryValue;
	this -> currentSize *= 2;
}


// реализация метода вставки в конец
template<typename ElementType>
void Array<ElementType>::insert(const ElementType &value) {
	
	if (count == this -> currentSize)
		increaseSize();
	
	this -> array[this -> count] = value;
	this -> count++;
	
}

// вставка в массив на заданную позицию
template<typename ElementType>
void Array<ElementType>::insert(const ElementType &value, int index) {
	
	if (index > this -> count)
		throw std::out_of_range("insertion was out of range in array at index");
	
	if (count == this -> currentSize)
		increaseSize();
	
	std::copy(this -> array + index, this -> array + this -> count, this -> array + index + 1);
	this -> array[index] = value;
	this -> count++;
	
}

// удаление элемента
template<typename ElementType>
void Array<ElementType>::remove(int index) {
	
	if (index > this -> currentSize)
		throw std::out_of_range("removing was out of range in array at index");
	
	if (this -> count > 0) {
		std::copy(this -> array + index + 1, this -> array + this -> count, this -> array + index);
//		this -> array[this -> count - 1] = 0;
		this -> count--;
	}
	
}

// получение количества элементов
template<typename ElementType>
int Array<ElementType>::size() const {
	return this -> count;
}

// общее количество элементов 
template<typename ElementType>
int Array<ElementType>::capacity() {
	return this -> currentSize;
}

// доступ к элементу по индексу
template <typename ElementType>
ElementType &Array<ElementType>::operator [] (int index) {
	
	if ((index < 0) || (index >= this -> currentSize))
		throw std::out_of_range("out of range []");
	
	return this -> array[index];
	
}

template<typename ElementType>
const ElementType &Array<ElementType>::operator [] (int index) const {
	
	if ((index < 0) || (index >= this -> currentSize))
		throw std::out_of_range("out of range []");
	
	return this -> array[index];
	
}



template<typename ElementType>
Array<ElementType>::Iterator::Iterator(Array<ElementType> &array) : array(array) {
	this -> index = 0;
}

template<typename ElementType>
const ElementType &Array<ElementType>::Iterator::get() const {
	return this -> array[this -> index];
}

template<typename ElementType>
void Array<ElementType>::Iterator::set(const ElementType &value) {
	this -> array[this -> index] = value;
}

template<typename ElementType>
void Array<ElementType>::Iterator::insert(const ElementType &value) {
	this -> array.insert(value, this -> index);
}

template<typename ElementType>
void Array<ElementType>::Iterator::remove() {
	this -> array.remove(this -> index);
}

template<typename ElementType>
void Array<ElementType>::Iterator::next() {
	this -> index++;
}

template<typename ElementType>
void Array<ElementType>::Iterator::previous() {
	this -> index--;
}

template<typename ElementType>
void Array<ElementType>::Iterator::toIndex(int index) {
	this -> index = index;
}

template<typename ElementType>
bool Array<ElementType>::Iterator::hasNext() const {
	return this -> index < (this -> array.count - 1);
}

template<typename ElementType>
bool Array<ElementType>::Iterator::hasPrevious() const {
	return this -> index > 0;
}


#endif