//
// SortingAlgorithm.cpp
// Created by Dimka Novikov on 28.12.2020.


#include <iostream>
#include <array>
#include <tuple>


// компаратор
template<typename ElementType>
bool condition(const ElementType &firstElement, const ElementType &secondElement);


// сортировка вставками
template<typename ElementType, typename CompareFunction>
void insertionSort(ElementType *firstElement, ElementType *lastElement, CompareFunction condition) {
	
	auto iterator = firstElement;
	ElementType *j;
	ElementType key;
	
	while (iterator <= lastElement) {
		key = *iterator;
		j = (iterator - 1);
		while ((j >= firstElement) && condition(key, *j)) {
			*(j + 1) = *j;
			j--;
		}
		*(j + 1) = key;
		iterator++;
	}
	
}



// смена местами пары значений
template<typename ElementType>
void swapPairElements(ElementType *firstElement, ElementType *secondElement) {
	auto temporaryValue = *firstElement;
	*firstElement = *secondElement;
	*secondElement = temporaryValue;
}


// выбор опоного элемента как медиану
template<typename ElementType, typename CompareFunction>
ElementType findNSetMedianPivot(ElementType *firstElement, ElementType *lastElement, CompareFunction condition) {
	
	auto a = firstElement;
	auto b = (firstElement + ((lastElement - firstElement) / 2));
	auto c = lastElement;
	
	if ((condition(*a, *b) && condition(*b, *c)) || (condition(*c, *b) && condition(*b, *a))) {
		return *b;
	} else if ((condition(*b , *a) && condition(*a , *c)) || (condition(*c , *a) && condition(*a , *b))) {
		swapPairElements(a, b);
	} else {
		swapPairElements(b, c);
	}
	return *b;
}


// разбиение
template<typename ElementType, typename CompareFunction>
std::pair<ElementType *, ElementType *> partition(ElementType *firstElement, ElementType *lastElement, CompareFunction condition) {
	
	auto medianPivot = findNSetMedianPivot(firstElement, lastElement, condition);
	
	auto leftElement = firstElement;
	auto rightElement = lastElement;
	
	while (leftElement <= rightElement) {
		
		while (condition(*leftElement, medianPivot)) {
			leftElement++;
		}
		
		while (condition(medianPivot, *rightElement)) {
			rightElement--;
		}
		
		if (leftElement <= rightElement) {
			swapPairElements(leftElement, rightElement);
			leftElement++;
			rightElement--;
		}
		
	}
	
	return std::make_pair(leftElement, rightElement);
	
}


// квик сорт
template<typename ElementType, typename CompareFunction>
void quickSort(ElementType *firstElement, ElementType *lastElement, CompareFunction condition) {
	
	ElementType *rightStart;
	ElementType *leftEnd;
	
	while (firstElement <= lastElement) {
		
		std::tie(rightStart, leftEnd) = partition(firstElement, lastElement, condition);
		
		if ((leftEnd - firstElement) < (lastElement - rightStart)) {
		
			quickSort(firstElement, leftEnd, condition);
			firstElement = rightStart;
		
		} else {
			
			quickSort(rightStart, lastElement, condition);
			lastElement = leftEnd;
			
		}
		
	}
	
}


// выбор оптимального алгоритма (сортировка вставками максимально жффективна при размерности вектора в 15-16 элементов)
template<typename ElementType, typename CompareFunction>
void sort(ElementType *firstElement, ElementType *lastElement, CompareFunction condition) {
	
	// сортировка вставками при условии что vector.count <= 15
	if ((lastElement - firstElement) < 16) {
		
		insertionSort(firstElement, lastElement, condition);
		
	} else {
		
		quickSort(firstElement, lastElement, condition);
		
	}
	
};


template<typename ElementType, typename CompareFunction>
bool isSorted(ElementType *startElement, ElementType *lastElement, CompareFunction condition) {
	while (startElement < lastElement) {
		if (condition(*(startElement + 1), *startElement)) {
			return false;
		}
		startElement++;
	}
	return true;
}