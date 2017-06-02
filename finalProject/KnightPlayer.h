#ifndef KnightPlayer_H
#define KnightPlayer_H

#include <iostream>
#include <string>
#include "GeneralPlayer.h"

using namespace std;

class KnightPlayer : public GeneralPlayer
{
public:
	KnightPlayer();
	KnightPlayer(int);
	KnightPlayer(int, string);
	KnightPlayer(const KnightPlayer&);
	void setLevel(int);
	virtual void setAttr(int);
	virtual void levelUp(void);
	void heal(void); // increasing HP (level*10) points by decreasing MP (level*5) points
	virtual void specialSkill();

private:

};

#endif
