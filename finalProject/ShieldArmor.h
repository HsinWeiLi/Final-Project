#ifndef ShieldArmor_H
#define ShieldArmor_H
#include <iostream>
#include <string>
#include "ArmorItem.h"

using namespace std;

class ShieldArmor : public ArmorItem
{
public:
	ShieldArmor(int, string, string, string, int, char, int);
	// level-required, name, effects, description, weight, type, defense-increment
};
#endif