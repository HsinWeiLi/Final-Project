#include <iostream>
#include <string>
#include "OrcPlayer.h"

using namespace std;

OrcPlayer::OrcPlayer()
{
	setName("anonymous");
	setLevel(1);
	setExp(0);
	countPlayer++;
}
OrcPlayer::OrcPlayer(int level_input)
{
	setName("anonymous");
	setLevel(level_input);
	countPlayer++;
}
OrcPlayer::OrcPlayer(int level_input, string name_input)
{
	setName(name_input);
	setLevel(level_input);
	countPlayer++;
}
OrcPlayer::OrcPlayer(const OrcPlayer& OrcPlayer_origin)
{
	setName(OrcPlayer_origin.getName());
	setLevel(OrcPlayer_origin.getLevel());
	setExp(OrcPlayer_origin.getExp());
	countPlayer++;
}
void OrcPlayer::setLevel(int level_input)
{
	level = level_input;
	setAttr(level);
	setExp(ceil(pow(10, log2(level_input))));

	if (getExp() == 1)
		setExp(0);
}
void OrcPlayer::setAttr(int level_input)
{
	attack = 50 + 12 * level_input;
	max_hp = 200 + 20 * level_input;
	setHP(max_hp);
	max_mp = 50 + 5 * level_input;
	setMP(max_mp);
	defense = 30 + 10 * level_input;
	max_exp = ceil(pow(10, log2(level_input + 1)));
}
void OrcPlayer::levelUp(void)
{
	level++;
	setAttr(level);
	setHP(max_hp);
	setMP(max_mp);
	setExp(ceil(pow(10, log2(level))));
}
void OrcPlayer::specialSkill()
{

}