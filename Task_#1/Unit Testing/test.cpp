#include "gtest/gtest.h"
#include "../Sorting Algorithm/SortingAlgorithm.hpp"


TEST(Test_1, commonIntSortTest) {
	
	int array[] = {
		5, 5, 6, 7, 4, 6, 7, 1, 2, 3, 4
	};
	
	sort(array, (array + (sizeof(array) / sizeof(array[0]))), [](int a, int b) { return a < b; });
	
	EXPECT_TRUE(isSorted(array, (array + (sizeof(array) / sizeof(array[0]))), [](int a, int b) { return a < b; }));
	
}

TEST(Test_2, reverseIntSort) {
	
	int array[] = {
		55, 53, 52, 51, 49, 47, 44, 43, 42, 32, 31, 30, 25, 24, 23, 22, 15, 11, 4, 3, 2, 1, -5
	};
	
	quickSort(array, (array + (sizeof(array) / sizeof(array[0]))), [](int a, int b) { return a < b; });
	
	EXPECT_TRUE(isSorted(array, (array + (sizeof(array) / sizeof(array[0]))), [](int a, int b) { return a < b; }));
	
}

TEST(Test_3, repeatableIntSort) {
	
	int array[] = {
		4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5
	};
	
	quickSort(array, (array + (sizeof(array) / sizeof(array[0]))), [](int a, int b) { return a < b; });
	
	EXPECT_TRUE(isSorted(array, (array + (sizeof(array) / sizeof(array[0]))), [](int a, int b) { return a < b; }));
	
}

TEST(Test_4, FloatArraySortedByDescending) {
	
	float array[] = {
		.1f, .3f, .5f, .11f, 1.1f, 12.3f, 154.7f
	};
	
	quickSort(array, (array + (sizeof(array) / sizeof(array[0]))), [](float a, float b) { return a > b; });
	
	EXPECT_TRUE(isSorted(array, (array + (sizeof(array) / sizeof(array[0]))), [](float a, float b) { return a > b; }));
	
}


// запуск тестов
int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


// g++ -std=c++0x test.cpp -lgtest -lgtest_main -pthread -o test