#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "AbstractMonster.h"
#include "GeneralPlayer.h"

using namespace std;

int AbstractMonster::countMonster = 0;
AbstractMonster::AbstractMonster(string name_input, int attack_input, int defense_input, int exp_input, int max_hp_input, int max_mp_input, int money_input)
	:name(name_input), attack(attack_input), defense(defense_input), exp(exp_input), max_hp(max_hp_input), max_mp(max_mp_input), money_monster(money_input)
{
	countMonster++;
}
AbstractMonster::~AbstractMonster()
{
	countMonster--;
}
void AbstractMonster::setHP(int hp_input)
{
	if (hp_input < 0)
		hp = 0;
	else if (hp_input>max_hp)
		hp = max_hp;
	else
		hp = hp_input;
}
int AbstractMonster::getHP() const
{
	return hp;
}
void AbstractMonster::setMP(int mp_input)
{
	if (mp_input < 0)
		mp = 0;
	else if (mp_input>max_mp)
		mp = max_mp;
	else
		mp = mp_input;
}
int AbstractMonster::getMP() const
{
	return mp;
}
int AbstractMonster::getDefense() const
{
	return defense;
}
int AbstractMonster::getcount() const
{
	return countMonster;
}
string AbstractMonster::serialize() const
{
	string code;
	ofstream output(code, ios::out);
	output  << name << "$" << hp << "$" << mp << "$" << exp << "$" << max_hp << "$" << max_mp
		<< "$" << attack << "$" << defense << "$" << money_monster << "$";
	return code;
}
void AbstractMonster::unserialize(string code)
{
	ifstream data(code, ios::in);
	if (!data)
	{
		cerr << "File could not be opened!" << endl;
		exit(1);
	}
	string MonsterString;
	getline(data, MonsterString);
	stringstream MonsterCode(MonsterString);

	string nameString;
	getline(MonsterCode, nameString, '$');
	stringstream nameCode(nameString);
	nameCode >> name;

	string attackString;
	getline(MonsterCode, attackString, '$');
	stringstream attackCode(attackString);
	attackCode >> attack;

	string defenseString;
	getline(MonsterCode, defenseString, '$');
	stringstream defenseCode(defenseString);
	defenseCode >> defense;

	string expString;
	getline(MonsterCode, expString, '$');
	stringstream expCode(expString);
	expCode >> exp;

	string maxHPString;
	getline(MonsterCode, maxHPString, '$');
	stringstream maxHPcode(maxHPString);
	maxHPcode >> max_hp;

	string maxMPString;
	getline(MonsterCode, maxMPString, '$');
	stringstream maxMPCode(maxMPString);
	maxMPCode >> max_mp;

	string moneyString;
	getline(MonsterCode, moneyString, '$');
	stringstream moneyCode(moneyString);
	moneyCode >> money_monster;
}