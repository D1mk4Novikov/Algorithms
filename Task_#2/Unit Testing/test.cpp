#include "gtest/gtest.h"
#include "../Array/Array.hpp"

#include <iostream>



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




// запуск тестов
int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


// g++ -std=c++0x test.cpp -lgtest -lgtest_main -pthread -o test