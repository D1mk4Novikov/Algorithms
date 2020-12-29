#include "gtest/gtest.h"
#include "../Array/Array.hpp"
#include "../List/List.hpp"
#include "../Wizard/Wizard.cpp"

#include <iostream>
#include <string>


// Array

TEST(ArrayCustomTest, CustomClassTest) {
		
	Array<Wizard> *array = new Array<Wizard>();
	
	EXPECT_TRUE(array -> size() == 0);
	EXPECT_TRUE(array -> capacity() == 8);
	
	auto it = array -> iterator();
	
//	for (auto temp = it; temp.hasNext(); temp.next())
	for (int i = 0; i < 50; i++)
		it.insert(Wizard());
	
//	it.insert(Wizard());
	
	
//	auto it = array -> iterator();
//	
//	 it.insert(Wizard("Mag 1", 10));
	
//	auto it = array -> iterator();
	
//	it.insert(Wizard("Wizard", 10));
	
	
//	EXPECT_TRUE(array.size() == 0);
	
//	array.insert(Wizard());
	
	
//	auto it = array -> iterator();
//	
//	for (auto temp = it; temp.hasNext(); temp.next())
//		std::cout << temp.get().name << "\t" << std::endl;
//	std::cout << std::endl;
//	
//	EXPECT_TRUE(it.get().mana == 1);
//	
//	array -> insert(Wizard("Wizard -1", 31), 0);
//	
//	EXPECT_TRUE(it.get().mana == 31);
//	
//	it.next();
//	
//	EXPECT_TRUE(it.get().mana == 0);
//	
//	it.remove();
//	
//	EXPECT_TRUE((array -> size()) == 50);
	
//	Array<Wizard> wizards(21);
//	
//	wizards.insert(Wizard("Hello", 123));
//	
//	EXPECT_TRUE(wizards.size() == 1);
//	EXPECT_TRUE(wizards.capacity() == 21);
	
}

TEST(ArrayTests, initTest) {
	Array<int> array;
	EXPECT_TRUE(array.size() == 0);
	EXPECT_TRUE(array.capacity() == 8);
	
	Array<int> array2(42);
	EXPECT_TRUE(array2.size() == 0);
	EXPECT_TRUE(array2.capacity() == 42);
}

TEST(ArrayTests, insertTest) {
	Array<int> array;
	array.insert(5);
	array.insert(5);
	array.insert(4 , 0);
	array.insert(15, 3);
	EXPECT_TRUE(array[0] == 4);
	EXPECT_TRUE(array[1] == 5);
	EXPECT_TRUE(array[3] == 15);
	EXPECT_TRUE(array.size() == 4);
	ASSERT_ANY_THROW(array.insert(125, 5));
}

TEST(ArrayTests, removeTest) {
	Array<int> array;
	array.insert(1);
	array.insert(2);
	array.insert(3, 0);
	array.remove(1);
	EXPECT_TRUE(array[0] == 3);
	EXPECT_TRUE(array[1] == 2);
	EXPECT_TRUE(array.size() == 2);
	ASSERT_ANY_THROW(array.insert(125, 5));
}

TEST(ArrayTests, test) {
	Array<int> array;
	for (int i = 0; i < 1110; ++i)
		array.insert(i);
	for (int i = 0; i < array.size(); ++i)
		array[i] *= 2;
	for (int i = 0; i < array.size(); ++i)
		EXPECT_TRUE(array[i] == i * 2);
}

TEST(ArrayTests, iteratorInitTest) {
	Array<int> array;
	for (int i = 0; i < 3; ++i)
		array.insert(i);
	auto it = array.iterator();
	EXPECT_TRUE(it.get() == 0);
	EXPECT_FALSE(it.hasPrevious());
	
}
TEST(ArrayTests, iteratorForwardMoveTest) {
	Array<int> array;
	for (int i = 0; i < 3; ++i)
		array.insert(i);
	auto it = array.iterator();
	it.next();
	EXPECT_TRUE(it.get() == 1);
	it.next();
	EXPECT_TRUE(it.get() == 2);
	EXPECT_FALSE(it.hasNext());
}
TEST(ArrayTests, iteratorBackMoveTest) {
	Array<int> array;
	for (int i = 0; i < 3; ++i)
		array.insert(i);
	auto it = array.iterator();
	it.toIndex(2);
	EXPECT_TRUE(it.get() == 2);
	it.previous();
	EXPECT_TRUE(it.get() == 1);
	it.previous();
	EXPECT_FALSE(it.hasPrevious());
}

TEST(ArrayTests, iteratorSetTest) {
	Array<int> array;
	for (int i = 0; i < 3; ++i)
		array.insert(i);
	auto it = array.iterator();
	it.set(5);
	EXPECT_TRUE(it.get() == 5);
	EXPECT_TRUE(array.size() == 3);
}

TEST(ArrayTests, iteratorInsertTest) {
	Array<int> array;
	for (int i = 0; i < 3; ++i)
		array.insert(i);
	auto it = array.iterator();
	it.insert(5);
	EXPECT_TRUE(it.get() == 5);
	EXPECT_TRUE(array.size() == 4);
}

TEST(ArrayTests, iteratorRemoveTest) {
	Array<int> array;
	for (int i = 0; i < 3; ++i)
		array.insert(i);
	auto it = array.iterator();
	it.remove();
	EXPECT_TRUE(it.get() == 1);
	EXPECT_TRUE(array.size() == 2);
}
TEST(ArrayTests, iteratorToIndexTest) {
	Array<int> array;
	for (int i = 0; i < 3; ++i)
		array.insert(i);
	auto it = array.iterator();
	it.toIndex(2);
	EXPECT_TRUE(it.get() == 2);
}



// Double Linked List

TEST(ListTests, initTest) {
	List<int> list;
	EXPECT_TRUE(list.size() == 0);
}

TEST(ListTests, insertHeadNTail) {
	List<int> list;
	list.insertHead(10);
	EXPECT_TRUE(list.head() == 10);
	list.insertHead(12);
	EXPECT_TRUE(list.head() == 12);
	list.insertTail(15);
	EXPECT_TRUE(list.tail() == 15);
	list.insertTail(1);
	EXPECT_TRUE(list.tail() == 1);
	EXPECT_FALSE(list.head() == 1);
}

TEST(ListTests, removeHeadNTail) {
	List<int> list;
	list.insertHead(10);
	list.insertHead(12);
	list.insertTail(15);
	list.insertTail(1);
	list.removeHead();
	EXPECT_TRUE(list.head() != 12);
	list.removeTail();
	EXPECT_TRUE(list.tail() != 1);
	list.removeTail();
	EXPECT_TRUE(list.head() == list.tail());
}

TEST(ListTests, test) {
	List<int> list;
	
	for (int i = 0; i < 10; i++)
		list.insertTail(i);
	int temporaryValue = 0;
	for (auto it = list.iterator(); it.hasNext(); it.next()) {
		EXPECT_TRUE(it.get() == temporaryValue);
		temporaryValue++;
	}
	
	List<int> list2;
	for (int i = 0; i < 10; i++)
		list2.insertHead(i);
	temporaryValue = 9;
	for (auto it = list2.iterator(); it.hasNext(); it.next()) {
		EXPECT_TRUE(it.get() == temporaryValue);
		temporaryValue--;
	}
}

TEST(ListTests, iteratorInitTest) {
	List<int> list;
	list.insertHead(10);
	list.insertHead(12);
	list.insertTail(15);
	list.insertTail(1);
	
	auto it = list.iterator();
	EXPECT_TRUE(it.get() == 12);
	EXPECT_FALSE(it.hasPrevious());
	it.next();
	EXPECT_TRUE(it.get() == 10);
	EXPECT_TRUE(it.hasNext());
}

TEST(ListTests, iteratorForwardMoveTest) {
	List<int> list;
	list.insertHead(10);
	list.insertHead(12);
	list.insertTail(15);
	list.insertTail(1);
	auto it = list.iterator();
	it.next();
	EXPECT_TRUE(it.get() == 10);
	it.next();
	EXPECT_TRUE(it.get() == 15);
	EXPECT_TRUE(it.hasPrevious());
	EXPECT_TRUE(it.hasNext());
	it.next();
	EXPECT_TRUE(it.get() == 1);
}

TEST(ListTests, iteratorBackMoveTest) {
	List<int> list;
	list.insertHead(10);
	list.insertHead(12);
	list.insertTail(15);
	list.insertTail(1);
	auto it = list.iterator();
	it.next();
	it.next();
	it.next();
	EXPECT_TRUE(it.get() == 1);
	it.previous();
	EXPECT_TRUE(it.get() == 15);
	EXPECT_TRUE(it.hasNext());
	EXPECT_TRUE(it.hasPrevious());
	it.previous();
	EXPECT_TRUE(it.get() == 10);
}

TEST(ListTests, iteratorSetTest) {
	List<int> list;
	list.insertHead(10);
	list.insertHead(12);
	list.insertTail(15);
	list.insertTail(1);
	auto it = list.iterator();
	it.next();
	it.next();
	it.set(255);
	EXPECT_TRUE(it.get() == 255);
	EXPECT_TRUE(list.size() == 4);
}

TEST(ListTests, iteratorInsertTest) {
	List<int> list;
	
	auto it = list.iterator();
	EXPECT_TRUE(list.size() == 0);
	it.insert(5);
	EXPECT_TRUE(list.head() == list.tail());
	EXPECT_TRUE(list.head() == 5);
	EXPECT_TRUE(list.size() == 1);
	EXPECT_TRUE(it.get() == 5);
	it.insert(10);
	EXPECT_TRUE(list.size() == 2);
	list.insertHead(21);
	EXPECT_TRUE(list.size() == 3);
}

TEST(ListTests, iteratorRemoveTest) {
	List<int> list;
	
	auto it = list.iterator();
	
	EXPECT_TRUE(list.size() == 0);
	it.insert(5);
	EXPECT_TRUE(list.head() == list.tail());
	EXPECT_TRUE(list.head() == 5);
	it.insert(10);
	EXPECT_TRUE(list.size() == 2);
	list.insertHead(21);
	list.insertTail(157);
	
	EXPECT_TRUE(list.size() == 4);
	
	it.remove();
	it.remove();
	
	EXPECT_TRUE(list.size() == 2);
	EXPECT_TRUE(it.get() == 5);
	
}




// запуск тестов
int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


// g++ -std=c++0x test.cpp -lgtest -lgtest_main -pthread -o test