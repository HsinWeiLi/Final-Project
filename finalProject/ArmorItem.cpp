#include <iostream>
#include <string>
#include "ArmorItem.h"
#include "Item.h"

using namespace std;

ArmorItem::ArmorItem(int level_required_input, string name_input, string effects_input, string description_input,
	int weight_input, char type_input, int defense_increment_input)
	:Item(level_required, name, effects, description, weight, type), defense_increment(defense_increment_input)
{

}