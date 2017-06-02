#include <iostream>
#include <string>
#include <time.h>
#include <random>
#include "ZombieMonster.h"
#include "GeneralPlayer.h"

using namespace std;

ZombieMonster::ZombieMonster()
	:AbstractMonster("Zombie", 50, 65, 17, 150, 30, 1000)
{
}
ZombieMonster::ZombieMonster(string name_input, int attack_input, int defense_input, int exp_input, int max_hp_input, int max_mp_input, int money_input)
	:AbstractMonster(name_input, attack_input, defense_input, exp_input, max_hp_input, max_mp_input, money_input)
{
}
ZombieMonster::~ZombieMonster()
{
	countMonster--;
}
void ZombieMonster::attackTo(GeneralPlayer* Player)
{
	int defense_Player = Player->getDefense();
	srand(time(NULL));
	int probability = rand() % 5;
	if (probability <= 3)
	{
		if (attack > defense_Player)
			Player->increaseHP(-(attack - defense_Player));
	}
	else if (probability == 4)
	{
		if (getMP() >= 10)
		{
			setMP(getMP() - 10);
			int superAttack = attack * 2;
			if (superAttack > defense_Player)
				Player->increaseHP(-(superAttack - defense_Player));
		}
	}
}