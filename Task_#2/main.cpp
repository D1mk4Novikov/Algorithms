#include <iostream>
#include "List/List.hpp"


int main(int argc, char *argv[]) {
	
	List<int> list;
	
	list.insertHead(10);
	
	return EXIT_SUCCESS;
	
}



// g++ -std=c++0x main.cpp -o main