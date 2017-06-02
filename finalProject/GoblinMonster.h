#ifndef GoblinMonster_H
#define GoblinMonster_H

#include <iostream>
#include <string>
#include "GeneralPlayer.h"
#include "AbstractMonster.h"

using namespace std;

class GeneralPlayer;
class GoblinMonster : public AbstractMonster
{
public:
	GoblinMonster();
	GoblinMonster(string, int, int, int, int, int, int);
	~GoblinMonster();
	virtual void attackTo(GeneralPlayer*);

};

#endif