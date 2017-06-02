#ifndef ArmorItem_H
#define ArmorItem_H
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class ArmorItem : public Item
{
public:
	ArmorItem(int, string, string, string, int, char, int);
	// level-required, name, effects, description, weight, type, defense-increment

	const int defense_increment;
};

#endif