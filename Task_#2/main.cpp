#include <iostream>
#include "Array/Array.hpp"
#include "List/List.hpp"
#include "Wizard/Wizard.cpp"


int main(int argc, char *argv[]) {
	
//	List<int> list;
	
//	list.insertHead(10);
//	list.insertHead(20);
//	
//	std::cout << list.head() << std::endl;
//	std::cout << list.tail() << std::endl;
//	
//	std::cout << list.size() << std::endl;
//	
//	list.insertTail(45);
//	list.insertTail(41);
//	
//	std::cout << list.head() << std::endl;
//	std::cout << list.tail() << std::endl;
//	
//	std::cout << list.size() << std::endl;
	
//	list.insertHead(10);
//	std::cout << list.head() << std::endl;
//	std::cout << list.size() << std::endl;
//	
//	list.insertTail(20);
//	std::cout << list.tail() << std::endl;
//	std::cout << list.size() << std::endl;
//	
//	std::cout << list.head() << std::endl;
//	std::cout << list.tail() << std::endl;
//	
//	list.removeHead();
//	std::cout << list.head() << std::endl;
//	std::cout << list.tail() << std::endl;
//	std::cout << list.size() << std::endl;
	
//	list.removeHead();
	
	// 41 20 5 10
	
//	list.insertTail(5);
//	list.insertTail(10);
//	list.insertHead(20);
//	list.insertHead(41);
//	std::cout << list.size() << std::endl;
//	std::cout << list.head() << std::endl;
//	std::cout << list.tail() << std::endl;
//	
//	// 20 5 10
//	
//	list.removeHead();
//	std::cout << list.size() << std::endl;
//	std::cout << list.head() << std::endl;
//	std::cout << list.tail() << std::endl;
//	
//	// 20 5
//	
//	list.removeTail();
//	std::cout << list.size() << std::endl;
//	std::cout << list.head() << std::endl;
//	std::cout << list.tail() << std::endl;
//	
//	auto it = list.iterator();
//	
//	std::cout << "---------------" << std::endl;
//	
//	printf("Has Next - %s\n", (it.hasNext() ? "Yes" : "No"));
//	printf("Has Previous - %s\n", (it.hasPrevious() ? "Yes" : "No"));
//	
//	
//	// 25, 20, 5
//	list.insertHead(25);
//	
////	it.next();
//	it.insert(10);
//	
//	std::cout << it.get() << std::endl;
//	it.next();
////	std::cout << it.get() << std::endl;
////	it.next();
//	std::cout << it.get() << std::endl;
//	it.set(10);
//	std::cout << "Setted value = " << it.get() << std::endl;
//	
//	std::cout << "List:" << std::endl;
//	for (auto temp = list.iterator(); temp.hasNext(); temp.next())
//		std::cout << it.get() << std::endl;
//	std::cout << std::endl;
	
	
	Array<Wizard> *array = new Array<Wizard>();
	
	std::cout << "Size: " << array -> size() << std::endl;
	std::cout << "Capacity: " << array -> capacity() << std::endl;
	
	
	auto it = array -> iterator();
	
	for (int i = 0; i < 50; i++)
		it.insert(Wizard("Wizard", 10));
	
	for (auto temp = array -> iterator(); temp.hasNext(); temp.next()) {
		std::cout << temp.get().name << std::endl;
		std::cout << temp.get().mana << std::endl;
	}
	
	std::cout << "Size: " << array -> size() << std::endl;
	std::cout << "Capacity: " << array -> capacity() << std::endl;
	
	
	return EXIT_SUCCESS;
	
}



// g++ -std=c++0x main.cpp -o main