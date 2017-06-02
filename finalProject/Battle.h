#ifndef Battle_H
#define Battle_H

#include <iostream>
#include <string>
#include <stdio.h>
#include "GeneralPlayer.h"
#include "AbstractMonster.h"

using namespace std;


struct Character
{
	char type;
	bool alive;
	void* instance;
};
class Battle : public Character
{
public:
	Battle(GeneralPlayer**, AbstractMonster**, int, int, int);
	Battle(GeneralPlayer**, AbstractMonster**, int, int);

	bool nextActor(void);
	int getTurnCount(void) const; // get the current number of turn
	int getTurnLimit(void) const; // get the limit on number of turns, 0 or no limit
	int getPlayerCount(void) const; // get the current number of players
	int getPlayerCount(bool) const; // get the current number of players
	int getMonsterCount(void) const; // get the current number of monsters
	int getMonsterCount(bool) const; // get the current number of monsters

	Character getCurrentActor(void); // get the current actor within the action list
	Character* getPlayers(void); // get a full list of players, no matter dead of alive ones
	Character* getMonsters(void); // get a full list of monsters, no matter dead of alive ones

	void showPlayerInfo(GeneralPlayer*);
	void showMonsterInfo(AbstractMonster*);

	void fight(const int, const int);
	
private:
	int turnNumber; // the number of turn, should be initialized to 0 in constructor
	int turnLimit; // maximum number of turn, 0 for no limit
	Character* actionList; // an ordered action list, indicates the order of action
	int numberPlayer;
	int numberMonster;
	GeneralPlayer *tmp_player;
	AbstractMonster *tmp_monster;
};


#endif
