#include <iostream>
#include <string>
#include "MagicianPlayer.h"

using namespace std;

MagicianPlayer::MagicianPlayer()
{
	setName("anonymous");
	setLevel(1);
	setExp(0);
	countPlayer++;
}
MagicianPlayer::MagicianPlayer(int level_input)
{
	setName("anonymous");
	setLevel(level_input);
	countPlayer++;
}
MagicianPlayer::MagicianPlayer(int level_input, string name_input)
{
	setName(name_input);
	setLevel(level_input);
	countPlayer++;
}
MagicianPlayer::MagicianPlayer(const MagicianPlayer& MagicianPlayer_origin)
{
	setName(MagicianPlayer_origin.getName());
	setLevel(MagicianPlayer_origin.getLevel());
	setMP(MagicianPlayer_origin.getMP());
	countPlayer++;
}
void MagicianPlayer::setLevel(int level_input)
{
	level = level_input;
	setAttr(level);
	setExp(ceil(pow(10, log2(level_input))));

	if (getExp() == 1)
		setExp(0);
}
void MagicianPlayer::setAttr(int level_input)
{
	attack = 30 + 8 * level_input;
	max_hp = 120 + 15 * level_input;
	setHP(max_hp);
	max_mp = 100 + 15 * level_input;
	setMP(max_mp);
	defense = 20 + 7 * level_input;
	max_exp = ceil(pow(10, log2(level_input + 1)));
}
void MagicianPlayer::levelUp(void)
{
	level++;
	setAttr(level);
	setHP(max_hp);
	setMP(max_mp);
	setExp(ceil(pow(10, log2(level))));
}
void MagicianPlayer::pray(void) // increasing MP (level*10) points by decreasing HP (level*5) points
{
	setMP(getMP() + level * 10);
	setHP(getHP() - level * 5);
}
void MagicianPlayer::specialSkill()
{
	pray();
}