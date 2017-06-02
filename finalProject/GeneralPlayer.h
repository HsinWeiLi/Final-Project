#ifndef GeneralPlayer_H
#define	GeneralPlayer_H

#include <iostream>
#include <string>
#include "AbstractMonster.h"
#include "Battle.h"
#include "Item.h"
#include "WeaponItem.h"
#include "ArmorItem.h"
#include "ConsumableItem.h"

using namespace std;

class GeneralPlayer
{
public:
	GeneralPlayer(); // default constructor: With level = 1, name = "anonymous", hp = 100, mp = 50, exp = 0
	GeneralPlayer(int); // normal constructor: Initializes level of the player, name = "anonymous", (level, hp, mp, exp)
	GeneralPlayer(int, string); // normal constructor: Initializes level and name of the player
	GeneralPlayer(const GeneralPlayer&); // Copy constructor: Call setAttr() in setLevel() to set attributes

	string getName() const;
	void setName(string);
	int getHP() const;
	void setHP(int);
	int getMP() const;
	void setMP(int);
	int getExp() const;
	void setExp(int);
	void setLevel(int); // need to call setAttr() inside
	int getLevel(void) const;
	virtual void setAttr(int); // parameter is level
	virtual void levelUp(void); // level++
	void increaseHP(int);
	void increaseMP(int);
	void increaseExp(int);
	void recoverHP(void); // hp = max_hp;
	void recoverMP(void); // mp = max_mp;
	int getAttack(void) const;
	int getDefense(void) const;
	int getMaxHP(void) const;
	int getMaxMP(void) const;
	int getmaxExp(void) const;
	void attackTo(AbstractMonster*);
	virtual void specialSkill();
	void setMoney(int);
	int getMoney() const;
	string serialize() const;
	void unserialize(string);

	static int countPlayer; // stores the number of alive players

	bool equipWeapon(WeaponItem*);
	bool equipArmor(ArmorItem*);
	//void useConsumable(ConsumableItem*);
	bool putItem(Item*);
	Item* takeItem(int);

	int getBackpackWeight(void);
	void setBackpackWeightLimit(int);
	void setBackpackSlotLimit(int);
	int getBackpackCurrentSlot(void);
	void showBackpack(void);

private:
	string name; // Stores the name of the player
	int hp; // Stores the HP of the player, >= 0
	int mp; // Stores the MP of the player, >= 0
	int exp; // Stores the experience of the player, >= 0
			 // Will not reset to zero after level-up

protected:
	int level; // Stores the level of the player >= 1
	int attack; // stores attack of the player
	int defense; // stores defense of the player
	int max_hp; // stores max. HP of the player
	int max_mp; // stores max. MP of the player
	int max_exp; // stores needed exp. to level-up
	int money;

	Item** backpack; // A list/array of Item*s (pointers to "real" items) as the backpack of players
	WeaponItem* weapon;
	ArmorItem* armor;
	int backpack_weight; // current weight of player's backpack
	int backpack_weight_limit; // limit on weight of backpack
	int backpack_slot_limit; // limit on number of backpack's slots
	;
};
#endif