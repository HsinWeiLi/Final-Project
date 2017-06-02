#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

Item::Item(int level_required_input, string name_input, string effects_input, string description_input, int weight_input, char type_input)
	:level_required(level_required_input), name(name_input), effects(effects_input), description(description_input),
	weight(weight_input), type(type_input)
{
}
void Item::showItem(void)
{
	cout << "Name : " << name << endl
		<< "Description" << description << endl
		<< "Effects" << effects << endl;
}