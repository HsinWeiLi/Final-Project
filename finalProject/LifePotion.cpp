#include <iostream>
#include <string>
#include "LifePotion.h"
#include "ConsumableItem.h"
#include "GeneralPlayer.h"

using namespace std;

// level-required, name, effects, description, weight, type, hp-increment
LifePotion::LifePotion(int level_required_input, string name_input, string effects_input, string description_input, 
	int weight_input, char type_input, int hp_increment_input)
	:ConsumableItem(level_required_input, name_input, effects_input, description_input, weight_input, type_input),
	hp_increment(hp_increment_input)
{

}
void LifePotion::use(GeneralPlayer* user)
{
	user->increaseHP(hp_increment);
}