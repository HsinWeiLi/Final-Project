#ifndef LifePotion_H
#define LifePotion_H
#include <iostream>
#include <string>
#include "ConsumableItem.h"
#include "GeneralPlayer.h"

using namespace std;

class LifePotion : public ConsumableItem
{
public:
	LifePotion(int, string, string, string, int, char, int);
	// level-required, name, effects, description, weight, type, hp_increment
	virtual void use(GeneralPlayer*);

	int hp_increment;
};
#endif