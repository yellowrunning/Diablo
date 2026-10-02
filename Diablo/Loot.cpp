#include <iostream>
#include <vector>
#include "Loot.h"

int main()
{
	std::vector<Loot> groundLoot;

	groundLoot.push_back(Loot("Health Potion", 50, 0, 0));
	groundLoot.push_back(Loot("Sword", 0, 5, 0));
	groundLoot.push_back(Loot("Armor", 0, 0, 3));

	for (const auto& item : groundLoot)
	{
		std::cout << "Item: " << item.Name()
			<< "  HP+" << item.Health()
			<< "  ATK+" << item.Attack()
			<< "  DEF+" << item.Defence() << '\n';
	}

	return 0;
}