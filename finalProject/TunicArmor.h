#ifndef TunicArmor_H
#define TunicArmor_H
#include <iostream>
#include <string>
#include "ArmorItem.h"

using namespace std;

class TunicArmor : public ArmorItem
{
public:
	TunicArmor(int, string, string, string, int, char, int);
	// level-required, name, effects, description, weight, type, defense-increment
};
#endif