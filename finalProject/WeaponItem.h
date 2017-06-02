#ifndef WeaponItem_H
#define WeaponItem_H
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class WeaponItem : public Item
{
public:
	WeaponItem(int, string, string, string, int, char, int);
	// level-required, name, effects, description, weight, type, attack-increment

	const int attack_increment;
};
#endif