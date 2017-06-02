#pragma once
#ifndef MagicianPlayer_H
#define MagicianPlayer_H

#include <iostream>
#include <string>
#include "GeneralPlayer.h"

using namespace std;

class MagicianPlayer : public GeneralPlayer
{
public:
	MagicianPlayer();
	MagicianPlayer(int);
	MagicianPlayer(int, string);
	MagicianPlayer(const MagicianPlayer&);
	void setLevel(int);
	virtual void setAttr(int);
	virtual void levelUp(void);
	void pray(void); // increasing MP (level*10) points by decreasing HP (level*5) points
	virtual void specialSkill();

private:

};

#endif
