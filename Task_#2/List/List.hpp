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
		List<ElementType> *list;
		
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
	
	
private:
	
	// струткура узла
//	template<typename ElementType>
//	template<class ElementType>
	struct Node {
		ElementType value;
		ElementType *pNext;
		ElementType *pPrevious;
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
	
}

// вставка головы
template<typename ElementType>
void List<ElementType>::insertHead(const ElementType &value) {
	
	// Новый жлемент
	Node *temporaryNode = new Node;
	
	// Предыдущего нет
	temporaryNode -> pPrevious = nullptr;
	// Заполняем данные
	temporaryNode -> value = value;
	// Следующий - бывшая голова
	temporaryNode -> pNext = this -> headNode;
//	temp->next = Head;
	
	// Если элементы есть?
	if (this -> headNode != nullptr)
		headNode -> pPrevious = temporaryNode;
	
//	if(Head != 0)
//		Head->prev = temp;
	
	// Если элемент первый, то он одновременно и голова и хвост
	if (this -> count == 0)
		headNode = tailNode = temporaryNode;
	else
		headNode = temporaryNode; // иначе новый элемент - головной
//	if(Count == 0)
//		Head = Tail = temp;
//	else
		
//	Head = temp;
	
	this -> count++;
	
}

// вставка хвоста
template<typename ElementType>
void List<ElementType>::insertTail(const ElementType &value) {
	
}


// головной жлемент
template<typename ElementType>
const ElementType &List<ElementType>::head() const {
	return this -> headNode -> value;
}

// хвостовой элемент
template<typename ElementType>
const ElementType &List<ElementType>::tail() const {
	return this -> tailNode -> value;
}

// количество узлов
template<typename ElementType>
int List<ElementType>::size() const {
	return this -> count;
}









//template<typename ElementType>
//class List final {
//	
//private:
//	// узел
//	class Node final {
//	private:
//		Node *pNext;
//		Node *pPrevious;
//		ElementType value;
//		
//	public:
//		Node(ElementType value = ElementType(), Node *pNext = nullptr, Node *pPrevious = nullptr) {
//			this -> value = value;
//			this -> pNext = pNext;
//			this -> pPrevious = pPrevious;
//		}
//		~Node() {
//			
//		}
//	};
//	
//	// head
//	Node *headNode;
//	// tail
//	Node *tailNode;
//	// количество узлов
//	int count;
//	
//	
//public:
//	
//	// конструктор
//	List();
//	// деструктор
//	~List();
//	
//	// добавить узел в начало
//	void insertHead(const ElementType &value);
//	// добавить узел в конец
//	void insertTail(const ElementType &value);
//	// удалить первый узел
//	void removeHead();
//	// удалить последний узел
//	void removeTail();
//	// получить первый узел
//	const ElementType & head() const;
//	// получить последний узел
//	const ElementType & tail() const;
//	// получить количество узлов
//	int size() const;
//	
//	
//	
//};
//
//
//// конструктор
//template<typename ElementType>
//List<ElementType>::List() {
//	this -> headNode = nullptr;
//	this -> tailNode = nullptr;
//	this -> count = 0;
//}
//
//// деструктор
//template<typename ElementType>
//List<ElementType>::~List() {
//	
//}
//
//
//// добавить узел в начало
//template<typename ElementType>
//void List<ElementType>::insertHead(const ElementType &value) {
//	
//	if (this -> count == 0)
//		this -> headNode = new Node(value);
//	else {
//		
//	}
//	
//	this -> count++;
//	
//}
//
//// добавить узел в конец
//template<typename ElementType>
//void List<ElementType>::insertTail(const ElementType &value) {
//	
//	if (this -> count == 0)
//		
//		this -> headNode = new Node(value);
//	
//	else {
//		
//		Node *currentNode = this -> headNode;
//		
//		while (currentNode -> pNext != nullptr) 
//			currentNode = currentNode -> pNext;
//		
//		currentNode -> pNext = new Node(value);
////		currentNode -> pPrevious = this -> headNode
//		
//	}
//	
//	this -> count++;
//	
//}
//
//// удалить первый узел
//template<typename ElementType>
//void List<ElementType>::removeHead() {
//	if (this -> count == 0)
//		delete this -> headNode;
//}
//
//// удалить последний узел
//template<typename ElementType>
//void List<ElementType>::removeTail() {
//	
//}
//
//// получить первый узел
//template<typename ElementType>
//const ElementType & List<ElementType>::head() const {
//	
//}
//
//// получить последний узел
//template<typename ElementType>
//const ElementType & List<ElementType>::tail() const {
//	
//}
//
//// количество элементов в списке
//template<typename ElementType>
//int List<ElementType>::size() const {
//	return this -> count;
//}



#endif