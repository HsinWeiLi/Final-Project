#include <iostream>
#include <string>
#include "TunicArmor.h"
#include "ArmorItem.h"

using namespace std;

TunicArmor::TunicArmor(int level_required_input, string name_input, string effects_input, string description_input,
	int weight_input, char type_input, int defense_increment_input)
	:ArmorItem(level_required_input, name_input, effects_input, description_input, weight_input, type_input, defense_increment_input)
{

}