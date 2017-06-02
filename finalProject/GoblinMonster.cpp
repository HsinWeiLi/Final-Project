#include <iostream>
#include <string>
#include "AbstractMonster.h"
#include "GoblinMonster.h"
#include "GeneralPlayer.h"

using namespace std;

GoblinMonster::GoblinMonster()
	:AbstractMonster("Goblin", 60, 40, 12, 100, 50, 500)
{
}
GoblinMonster::GoblinMonster(string  name_input, int attack_input, int defense_input, int exp_input, int max_hp_input, int max_mp_input, int money_input)
	:AbstractMonster(name_input, attack_input, defense_input, exp_input, max_hp_input, max_mp_input, money_input)
{
}
GoblinMonster::~GoblinMonster()
{
	countMonster--;
}
void GoblinMonster::attackTo(GeneralPlayer* Player)
{
	int defense_Player = Player -> getDefense();
	if (attack > defense_Player)
		Player->increaseHP(-(attack - defense_Player));
}