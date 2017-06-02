#ifndef AxeWeapon_H
#define AxeWeapon_H
#include <iostream>
#include <string>
#include "WeaponItem.h"

using namespace std;

class AxeWeapon : public WeaponItem
{
public:
	AxeWeapon(int, string, string, string, int, char, int);
	// level-required, name, effects, description, weight, type, attack-increment
};
#endif