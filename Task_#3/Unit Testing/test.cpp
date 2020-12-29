#include "gtest/gtest.h"
#include "../Dictionary/Dictionary.hpp"

TEST(DictionaryTest, initTest) {
	Dictionary<std::string, int> npc;
	EXPECT_TRUE(npc.size() == 0);
}

TEST(DictionaryTest, putTest) {
	Dictionary<std::string, int> npc;
	for(auto i = 0; i < 10; i++) {
		npc.put(std::to_string(i), i);
	}
	
	EXPECT_TRUE(npc.size() == 10);

}

TEST(DictionaryTest, containsTest) {
	Dictionary<std::string, int> npc;
	for (auto i = 0; i < 10; i++)
	{
		npc.put(std::to_string(i), i);
	}
	for (auto i = 0; i < 10; i++)
	{
		EXPECT_TRUE(npc.contains(std::to_string(i)));
	}
	EXPECT_TRUE(npc.size() == 10);

}

TEST(DictionaryTest, removeTest) {
	Dictionary<std::string, int> npc;
	for (auto i = 0; i < 10; i++)
	{
		npc.put(std::to_string(i), i);
	}
	for (auto i = 0; i < 5; i++)
	{
		npc.remove(std::to_string(i));
	}
	for (auto i = 0; i < 5; i++)
	{
		EXPECT_FALSE(npc.contains(std::to_string(i)));
	}
	for (auto i = 5; i < 10; i++)
	{
		EXPECT_TRUE(npc.contains(std::to_string(i)));
	}
	EXPECT_TRUE(npc.size() == 5);

}

TEST(DictionaryTest, operatorTest) {
	Dictionary<std::string, int> npc;
	for (auto i = 0; i < 100; i++) {
		npc[std::to_string(i)] = i;
	}
	for (auto i = 0; i < 100; i++) {
		EXPECT_TRUE(npc.contains(std::to_string(i)));
		EXPECT_TRUE(npc[std::to_string(i)] == i);
		
	}
	EXPECT_TRUE(npc.size() == 100);

}

TEST(DictionaryTest, IteratorForwardTest) {
	Dictionary<std::string, int> npc;
	for (auto i = 0; i < 100; i++)
	{
		npc[std::to_string(i)] = i;
	}
	auto i = 1;
	for (auto it = npc.iterator(); it.hasNext(); it.next())
	{
		EXPECT_TRUE(npc[it.key()] == it.get());
		i++;
		
	}
	EXPECT_TRUE(i == npc.size());

}

TEST(DictionaryTest, IteratorForwardBackwardTest) {
	Dictionary<std::string, int> npc;
	for (auto i = 0; i < 100; i++)
	{
		npc[std::to_string(i)] = i;
	}
	auto i = 1;
//	auto it = npc.iterator();
	for (auto it = npc.iterator(); it.hasNext(); it.next())
	{
		EXPECT_TRUE(npc[it.key()] == it.get());
	

	}
	for (auto it = npc.iterator(); it.hasPrev(); it.prev())
	{
		EXPECT_TRUE(npc[it.key()] == it.get());
		i++;

	}
	EXPECT_TRUE(i == npc.size());

}

TEST(DictionaryTest, IteratorSetTest) {
	Dictionary<std::string, int> npc;
	for (auto i = 0; i < 100; i++)
	{
		npc[std::to_string(i)] = i;
	}
	auto it = npc.iterator();
	for (auto it = npc.iterator(); it.hasNext(); it.next()) {
		it.set(42);
	}
	it.set(42);
	for (auto i = 0; i < 100; i++)
	{
		EXPECT_TRUE(npc[std::to_string(i)] == 42);
	}
}