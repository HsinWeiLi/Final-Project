#ifndef JWMonster_H
#define JWMonster_H

#include <iostream>
#include <string>
#include "AbstractMonster.h"
#include "GeneralPlayer.h"

using namespace std;

class GeneralPlayer;
class JWMonster : public AbstractMonster
{
public:
	JWMonster();
	JWMonster(string, int, int, int, int, int, int);
	~JWMonster();
	virtual void attackTo(GeneralPlayer*);

};

#endif