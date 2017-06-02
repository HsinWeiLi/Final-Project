#ifndef SwordWeapon_H
#define SwordWeapon_H
#include <iostream>
#include <string>
#include "WeaponItem.h"

using namespace std;

class SwordWeapon : public WeaponItem
{
public:
	SwordWeapon(int, string, string, string, int, char, int);
	// level-required, name, effects, description, weight, type, attack-increment
};
#endif