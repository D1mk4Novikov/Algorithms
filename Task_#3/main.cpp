#include <iostream>

#include "Dictionary/Dictionary.hpp"

#include <string>

using namespace std;
int main(int argc, char *argv[]) {
	
	Dictionary<std::string, int> npc;
	npc.put("health", 10);
	npc.put("armor", 20);
	npc.put("ammo", 5);
	printf("has prev ? - %s\n", (npc.iterator().hasPrev() ? "Yes" : "No"));
	for (auto it = npc.iterator(); it.hasNext(); it.next()) std::cout << it.key() << " " << it.get() << std::endl;
	
}