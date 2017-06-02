#ifndef ConsumableItem_H
#define ConsumableItem_H
#include <iostream>
#include <string>
#include "Item.h"
#include "GeneralPlayer.h"

using namespace std;

class GeneralPlayer;
class ConsumableItem : public Item
{
public:
	ConsumableItem(int, string, string, string, int, char);
	// level-required, name, effects, description, weight, type

	virtual void use(GeneralPlayer*) = 0;
};
#endif