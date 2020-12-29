//
// List.h
// Created by Dimka Novikov on 3.11.2020.

#ifndef _List_hpp_
#define _List_hpp_


#pragma once

//#include "./List.cpp"

#include <iostream>


// ФДТ Двусвязный список
template<typename ElementType>
class List final {
	
	// Итератор
	class Iterator final {
		
		friend class List<ElementType>;
		
	private:
		// индекс
		int index;
		// список
		List<ElementType> &list;
		
	public:
		// конструктор
		Iterator(List<ElementType> &list);
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
		// наличие след элемента
		bool hasNext() const;
		// наличие пред элемента
		bool hasPrevious() const;
		
	};
	
	
private:
	
	// струткура узла
	class Node final {
	public:
		ElementType value;
		Node *pPrevious;
		Node *pNext;
		
	public:
		Node(ElementType value = ElementType(), Node *pPrevious = nullptr, Node *pNext = nullptr) {
			this -> value = value;
			this -> pPrevious = pPrevious;
			this -> pNext = pNext;
		}
	};
	
	// Голова
	Node *headNode;
	// Хвост
	Node *tailNode;
	// Количество узлов
	int count;
	
	
public:
	// дефолтный конструктор листа
	List();
	// конструктор копирования
	List(const List &);
	// деструктор листа
	~List();
	
	// вставка в начало
	void insertHead(const ElementType &value);
	// вставка в конец
	void insertTail(const ElementType &value);
	
	// удаление головного элемента
	void removeHead();
	// удаление хвостового элемента
	void removeTail();
	
	// текущение значение в голове
	const ElementType &head() const;
	// текущее значение в хвосте
	const ElementType &tail() const;
	
	// Количество узлов
	int size() const;
	
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


// дефолтный конструктор листа
template<typename ElementType>
List<ElementType>::List() {
	// Изначально список пуст
	this -> headNode = this -> tailNode = nullptr;
	this -> count = 0;
}

// конструктор копирования
template<typename ElementType>
List<ElementType>::List(const List &list) {
	
	this -> headNode = this -> tailNode = nullptr;
	this -> count = 0;
	
	// голова списка откуда копируем
	Node *temporaryNode = list -> headNode;
	// пока не достигнут конец списка
	while (temporaryNode != 0) {
		// перебор данные
		this -> insertHead(temporaryNode -> value);
		temporaryNode = temporaryNode -> pNext;
	}
	
}


// деструктор листа
template<typename ElementType>
List<ElementType>::~List() {
	
	while (this -> count > 0)
		this -> removeTail();
	
}

// вставка головы
template<typename ElementType>
void List<ElementType>::insertHead(const ElementType &value) {
	
	// Новый элемент
	Node *temporaryNode = new Node();
	
	// Заполняем данные
	temporaryNode -> value = value;
	// Предыдущего нет
	temporaryNode -> pPrevious = nullptr;
	// Следующий - бывшая голова
	temporaryNode -> pNext = this -> headNode;
	
	// Если элементы есть?
	if (this -> headNode != nullptr)
		this -> headNode -> pPrevious = temporaryNode;
	
	// Если элемент первый, то он одновременно и голова и хвост
	if (this -> count == 0)
		this -> headNode = this -> tailNode = temporaryNode;
	else
		this -> headNode = temporaryNode; // иначе новый элемент - головной
	
	this -> count++;
	
}

// вставка хвоста
template<typename ElementType>
void List<ElementType>::insertTail(const ElementType &value) {
	
	// создание новго узла
	Node *temporaryNode = new Node();
	
	// запись значения
	temporaryNode -> value = value;
	// пред = хвосту
	temporaryNode -> pPrevious = this -> tailNode;
	// следующего нет
	temporaryNode -> pNext = nullptr;
	
	// Если элементы есть?
	if (this -> tailNode != nullptr)
		this -> tailNode -> pNext = temporaryNode;
	
	// Если элемент первый, то он одновременно и голова и хвост
	if(this -> count == 0)
		this -> headNode = this -> tailNode = temporaryNode;
	else
		this -> tailNode = temporaryNode; // иначе новый элемент - хвостовой
	
	this -> count++;
	
}


// удаление головного элемента
template<typename ElementType>
void List<ElementType>::removeHead() {
	
	if (this -> count == 0)
		throw std::range_error("list is empty");
	else if (this -> count == 1)
		this -> headNode = this -> tailNode = nullptr;
	else if (this -> count == 2) {
		this -> headNode = this -> tailNode;
	} else {
		
		Node *temporaryNode = new Node();
		
		// след нод за хедом - является хедом
		temporaryNode -> value = this -> headNode -> pNext -> value;
		temporaryNode -> pPrevious = nullptr;
		temporaryNode -> pNext = this -> headNode -> pNext;
		
		delete this -> headNode;
		
		this -> headNode = temporaryNode;
		
	}
	
	this -> count--;
	
}

// удаление хвостового элемента
template<typename ElementType>
void List<ElementType>::removeTail() {
	
	if (this -> count == 0)
		throw std::range_error("list is empty");
	else if (this -> count == 1)
		this -> headNode = this -> tailNode = nullptr;
	else if (this -> count == 2) {
		this -> headNode = this -> tailNode;
	} else {
		
		Node *temporaryNode = new Node();
		
		// след нод за хедом - является хедом
		temporaryNode -> value = this -> tailNode -> pPrevious -> value;
		temporaryNode -> pPrevious = this -> tailNode -> pPrevious;
		temporaryNode -> pNext = nullptr;
		
		delete this -> tailNode;
		
		this -> tailNode = temporaryNode;
		
	}
	
	this -> count--;
	
}


// головной жлемент
template<typename ElementType>
const ElementType &List<ElementType>::head() const {
	return this -> headNode -> value;
}

// хвостовой элемент
template<typename ElementType>
const ElementType &List<ElementType>::tail() const {
	return (this -> tailNode) -> value;
}

// количество узлов
template<typename ElementType>
int List<ElementType>::size() const {
	return this -> count;
}



// Итератор
template<typename ElementType>
List<ElementType>::Iterator::Iterator(List<ElementType> &list) : list(list) {
	this -> index = 0;
}

// текущий элемент
template<typename ElementType>
const ElementType &List<ElementType>::Iterator::get() const {
	
	Node *temporaryNode = new Node();
	temporaryNode = this -> list.headNode;
	
	int currentIndex = 0;
	
	while (currentIndex < this -> index) {
		temporaryNode = temporaryNode -> pNext;
		currentIndex++;
	}
	
	return temporaryNode -> value;
		
}

// устновить значение
template<typename ElementType>
void List<ElementType>::Iterator::set(const ElementType &value) {
	
	Node *temporaryNode = new Node();
	temporaryNode = this -> list.headNode;
	
	int currentIndex = 0;
	
	while (currentIndex < this -> index) {
		temporaryNode = temporaryNode -> pNext;
		currentIndex++;
	}
	
	temporaryNode -> value = value;
	
}

// добавление элемента в текущей позиции
template<typename ElementType>
void List<ElementType>::Iterator::insert(const ElementType &value) {
	
	if ((this -> list.count == 0) || (this -> list.count == 1))
		list.insertTail(value);
	else {
		
		Node *temporaryNode = new Node(value);
		
		Node *leftNode = new Node();
		leftNode = this -> list.headNode;
		
		Node *rightNode = new Node();
		
		int currentIndex = 0;
		
		while (currentIndex < this -> index - 1) {
			leftNode = leftNode -> pNext;
			currentIndex++;
		}
		
		this -> index = currentIndex + 1;
		
		rightNode = leftNode -> pNext -> pNext;
		
		leftNode -> pNext = temporaryNode;
		temporaryNode -> pPrevious = leftNode;
		
		temporaryNode -> pNext = rightNode;
		rightNode -> pPrevious = temporaryNode;
		
		this -> list.count++;
	
	}
	
}

// удаление по индексу
template<typename ElementType>
void List<ElementType>::Iterator::remove() {
	
	if (this -> list.count == 0)
		throw std::range_error("list is empty");
	else if (this -> list.count == 1) {
		this -> list.headNode = this -> list.tailNode = nullptr;
		this -> index = 0;
		this -> list.count--;
	} else if ((this -> list.count >= 2) && (this -> hasPrevious())) {
		this -> list.removeTail();
		this -> index = this -> list.count - 1;
	} else if ((this -> list.count >= 2) && (this -> hasNext()))
		this -> list.removeHead();
	else if ((this -> list.count > 2) && this -> hasNext() && this -> hasPrevious()) {
		
		Node *leftNode = new Node();
		leftNode = this -> list.headNode;
		
		Node *temporaryNode = new Node();
		
		Node *rightNode = new Node();
		
		int currentIndex = 0;
		
		while (currentIndex < this -> index - 1) {
			leftNode = leftNode -> pNext;
			currentIndex++;
		}
		
		rightNode = leftNode -> pNext -> pNext;
		
		temporaryNode = leftNode -> pNext;
		delete temporaryNode;
		
		leftNode -> pNext = rightNode;
		
		rightNode -> pPrevious = leftNode;
		
		this -> list.count--;
		
		this -> index++;
		
	}
	
}

// след элемент
template<typename ElementType>
void List<ElementType>::Iterator::next() {
	this -> index++;
}

// пред элемент
template<typename ElementType>
void List<ElementType>::Iterator::previous() {
	this -> index--;
}

// есть ли след
template<typename ElementType>
bool List<ElementType>::Iterator::hasNext() const {
	return (this -> index < this -> list.count);
}

// есть ли пред
template<typename ElementType>
bool List<ElementType>::Iterator::hasPrevious() const {
	return (this -> index > 0);
}



#endif