#include <iostream>
#include <string>
#include "KnightPlayer.h"

using namespace std;

KnightPlayer::KnightPlayer()
{
	setName("anonymous");
	setLevel(1);
	setExp(0);
	countPlayer++;
}
KnightPlayer::KnightPlayer(int level_input)
{
	setName("anonymous");
	setLevel(level_input);
	countPlayer++;
}
KnightPlayer::KnightPlayer(int level_input, string name_input)
{
	setName(name_input);
	setLevel(level_input);
	setMoney(0);
	countPlayer++;
}
KnightPlayer::KnightPlayer(const KnightPlayer& KnightPlayer_origin)
{
	setName(KnightPlayer_origin.getName());
	setLevel(KnightPlayer_origin.getLevel());
	setExp(KnightPlayer_origin.getExp());
	setMoney(KnightPlayer_origin.money);
	countPlayer++;
}
void KnightPlayer::setLevel(int level_input)
{
	level = level_input;
	setAttr(level);
	setExp(ceil(pow(10, log2(level_input))));
	if (getExp() == 1)
		setExp(0);
}
void KnightPlayer::setAttr(int level_input)
{
	attack = 40 + 10 * level_input;
	max_hp = 150 + 25 * level_input;
	setHP(max_hp);
	max_mp = 70 + 10 * level_input;
	setMP(max_mp);
	defense = 20 + 12 * level_input;
	max_exp = ceil(pow(10, log2(level_input + 1)));
	
	if (getExp() == 1)
		setExp(0);
}
void KnightPlayer::levelUp(void)
{
	setLevel(level + 1);
}
void KnightPlayer::heal(void) // increasing HP (level*10) points by decreasing MP (level*5) points
{
	setHP(getHP() + level * 10);
	setMP(getMP() - level * 5);
}
void KnightPlayer::specialSkill()
{
	heal();
}