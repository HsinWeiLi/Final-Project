#include <iostream>
#include <string>
#include "WeaponItem.h"
#include "Item.h"

using namespace std;

WeaponItem::WeaponItem(int level_required_input, string name_input, string effects_input, string description_input,
	int weight_input, char type_input, int attack_increment_input)
	:Item(level_required_input, name_input, effects_input, description_input, weight_input, type_input),
	attack_increment(attack_increment_input)
{

}