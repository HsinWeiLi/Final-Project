#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include "GeneralPlayer.h"

using namespace std;

int GeneralPlayer::countPlayer = 0;

GeneralPlayer::GeneralPlayer() // default constructor: With level = 1, name = "anonymous"
{
	setName("anonymous");
	setLevel(1);
	setExp(0);
	setMoney(0);
	countPlayer++;
}
GeneralPlayer::GeneralPlayer(int level_input) // normal constructor: Initializes level of the player, name = "anonymous"
{
	setName("anonymous");
	setLevel(level_input);
	setMoney(0);
	countPlayer++;
}
GeneralPlayer::GeneralPlayer(int level_input, string name_input) // normal constructor: Initializes level and name of the player
{
	setName(name_input);
	setLevel(level_input);
	setMoney(0);
	countPlayer++;
}
GeneralPlayer::GeneralPlayer(const GeneralPlayer& GeneralPlayer_origin) // Copy constructor: Call setAttr() in setLevel() to set attributes
{
	setName(GeneralPlayer_origin.name);
	setLevel(GeneralPlayer_origin.level);
	setMoney(GeneralPlayer_origin.money);
	countPlayer++;
}
string GeneralPlayer::getName() const
{
	return name;
}
void GeneralPlayer::setName(string name_input)
{
	name = name_input;
}
int GeneralPlayer::getHP() const
{
	return hp;
}
void GeneralPlayer::setHP(int hp_input)
{
	if (hp_input < 0)
		hp = 0;
	else if (hp_input>max_hp)
		hp = max_hp;
	else
		hp = hp_input;
}
int GeneralPlayer::getMP() const
{
	return mp;
}
void GeneralPlayer::setMP(int mp_input)
{
	if (mp_input < 0)
		mp = 0;
	else if (mp_input>max_mp)
		mp = max_mp;
	else
		mp = mp_input;
}
int GeneralPlayer::getExp() const
{
	return exp;
}
void GeneralPlayer::setExp(int exp_input)
{
	if (exp_input < 0)
		exp = 0;
	else if (exp_input >= max_exp)
	{
		levelUp();
		exp = exp_input;
	}
	else
		exp = exp_input;
}
void GeneralPlayer::setLevel(int level_input) // need to call setAttr() inside
{
	level = level_input;
	setAttr(level);
	exp = ceil(pow(10, log2(level)));

	if (exp == 1)
		exp = 0;
}
int GeneralPlayer::getLevel(void) const
{
	return level;
}
void GeneralPlayer::setAttr(int level_input) // parameter is level
{

	attack = 20 + 5 * level_input;
	max_hp = 100 + 10 * level_input;
	hp = max_hp;
	max_mp = 40 + 5 * level_input;
	mp = max_mp;
	defense = 20 + 5 * level_input;
	max_exp = ceil(pow(10, log2(level_input + 1)));

	if (exp == 1)
		exp = 0;
}
void GeneralPlayer::levelUp(void) // level++
{
	level++;
	attack = 20 + 5 * level;
	max_hp = 100 + 10 * level;
	hp = max_hp;
	max_mp = 40 + 5 * level;
	mp = max_mp;
	defense = 20 + 5 * level;
	max_exp = ceil(pow(10, log2(level)));

	if (exp < max_exp)
		exp = max_exp;

	recoverHP();
	recoverMP();
}
void GeneralPlayer::increaseHP(int x)
{
	setHP(hp + x);
}
void GeneralPlayer::increaseMP(int x)
{
	setMP(mp + x);
}
void GeneralPlayer::increaseExp(int x)
{
	exp += x;
	if ((exp) > max_exp)
		levelUp();
}
void GeneralPlayer::recoverHP(void) // hp = max_hp
{
	hp = max_hp;
}
void GeneralPlayer::recoverMP(void) // mp = max_mp
{
	mp = max_mp;
}
int GeneralPlayer::getAttack(void) const
{
	return attack;
}
int GeneralPlayer::getDefense(void) const
{
	return defense;
}
int GeneralPlayer::getMaxHP(void) const
{
	return max_hp;
}
int GeneralPlayer::getMaxMP(void) const
{
	return max_mp;
}
int GeneralPlayer::getmaxExp(void) const
{
	return max_exp;
}
void GeneralPlayer::attackTo(AbstractMonster* Monster)
{
	int defense_monster = Monster -> getDefense();
	if (attack > defense_monster)
		Monster->setHP((Monster->getHP()) + (attack - defense_monster));
}
void GeneralPlayer::specialSkill()
{
}
void GeneralPlayer::setMoney(int money_input)
{
	money = money_input;
}
int GeneralPlayer::getMoney() const
{
	return money;
}
string GeneralPlayer::serialize() const
{
	string code;
	ofstream output(code, ios::out);
	output << "$name:" << name << "$level:" << level << "$hp:" << hp << "$mp:" << mp << "$exp:" << exp << "$max_hp:" << max_hp << "$max_mp:" << max_mp
		<< "$max_exp:" << max_exp << "$attack:" << attack << "$defense:" << defense << "$";
	
	return code;
}
void GeneralPlayer::unserialize(string code)
{
	ifstream data(code, ios::in);
	if (!data)
	{
		cerr << "File could not be opened!" << endl;
		exit(1);
	}
	string MonsterString;
	getline(data, MonsterString);
	stringstream PlayerCode(MonsterString);

	string nameString;
	getline(PlayerCode, nameString, '$');
	stringstream nameCode(nameString);
	nameCode >> name;

	string attackString;
	getline(PlayerCode, attackString, '$');
	stringstream attackCode(attackString);
	attackCode >> attack;

	string defenseString;
	getline(PlayerCode, defenseString, '$');
	stringstream defenseCode(defenseString);
	defenseCode >> defense;

	string expString;
	getline(PlayerCode, expString, '$');
	stringstream expCode(expString);
	expCode >> exp;

	string maxHPString;
	getline(PlayerCode, maxHPString, '$');
	stringstream maxHPcode(maxHPString);
	maxHPcode >> max_hp;

	string maxMPString;
	getline(PlayerCode, maxMPString, '$');
	stringstream maxMPCode(maxMPString);
	maxMPCode >> max_mp;

	string moneyString;
	getline(PlayerCode, moneyString, '$');
	stringstream moneyCode(moneyString);
	moneyCode >> money;

	string levelString;
	getline(PlayerCode, levelString, '$');
	stringstream levelCode(levelString);
	levelCode >> level;
}
bool GeneralPlayer::equipWeapon(WeaponItem* Weapon)
{
	if (weapon == NULL)
	{
		weapon = Weapon;
		return true;
	}
	else
		return false;
}
bool GeneralPlayer::equipArmor(ArmorItem* Armor)
{
	if (weapon == NULL)
	{
		armor = Armor;
		return true;
	}
	else
		return false;
}
/*void GeneralPlayer::useConsumable(ConsumableItem* Consumable)
{
	Consumable->use(this);
	Consumable = NULL;
}*/
// Put(add) an item into backpack
bool GeneralPlayer::putItem(Item* item) // The return value indicates this operation is successful or not
{
	if ((backpack_weight + item->weight) > backpack_weight_limit || getBackpackCurrentSlot() == backpack_slot_limit)
		return false;
	else
	{
		backpack[getBackpackCurrentSlot() + 1] = item;
		return true;
	}
}
// Take remove an item from backpack
Item* GeneralPlayer::takeItem(int index) // The parameter is the index of backpack
{
	backpack[index] = NULL;
	return backpack[index];
}
int GeneralPlayer::getBackpackWeight(void)
{
	return backpack_weight;
}
void GeneralPlayer::setBackpackWeightLimit(int backpack_weight_limit_input)
{
	backpack_weight_limit = backpack_weight_limit_input;
}
void GeneralPlayer::setBackpackSlotLimit(int backpack_slot_limit_input)
{
	backpack_slot_limit = backpack_slot_limit_input;
}
int GeneralPlayer::getBackpackCurrentSlot(void)
{
	int occupied_slot = 0;
	for (int i = 0; i < backpack_slot_limit; i++)
		if (backpack[i] != NULL)
			occupied_slot++;
	return occupied_slot;
}
void GeneralPlayer::showBackpack(void)
{
	for (int i = 0; i < backpack_slot_limit; i++)
	{
		if (backpack[i] != NULL)
			backpack[i]->showItem();
	}
}