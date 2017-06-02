#include <iostream>
#include <string>
#include "ConsumableItem.h"
#include "Item.h"
#include "GeneralPlayer.h"

using namespace std;

ConsumableItem::ConsumableItem(int level_required_input, string name_input, string effects_input, string description_input,
	int weight_input, char type_input)
	:Item(level_required_input, name_input, effects_input, description_input, weight_input, type_input)
{

}