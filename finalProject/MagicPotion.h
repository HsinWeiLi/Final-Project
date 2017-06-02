#ifndef MagicPotion_H
#define MagicPOtion_H
#include <iostream>
#include <string>
#include "ConsumableItem.h"
#include "GeneralPlayer.h"

using namespace std;

class GeneralPlayer;
class MagicPotion : public ConsumableItem
{
public:
	MagicPotion(int, string, string, string, int, char, int);
	// level-required, name, effects, description, weight, type, mp_increment
	virtual void use(GeneralPlayer*);

	int mp_increment;
};
#endif