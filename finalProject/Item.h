#ifndef Item_H
#define Item_H
#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
	Item(int, string, string, string, int, char);
	void showItem(void);
	
	const int level_required; // level limit of equip/use this item
	const string name; // the name of this item
	const string effects; // a short description of its effect
	const string description; // a short description of this item
	const int weight; // the weight of the item
	const char type; // Type of this item, ¡§w¡¨ for weapons, ¡§a¡¨ for armors, ¡§c¡¨ for consumables
};
#endif
