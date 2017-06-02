#ifndef ZombieMonster_H
#define ZombieMonster_H

#include <iostream>
#include <string>
#include "GeneralPlayer.h"
#include "AbstractMonster.h"

using namespace std;

class GeneralPlayer;
class ZombieMonster : public AbstractMonster
{
public:
	ZombieMonster();
	ZombieMonster(string, int, int, int, int, int, int);
	~ZombieMonster();
	virtual void attackTo(GeneralPlayer*);

private:

protected:

};

#endif