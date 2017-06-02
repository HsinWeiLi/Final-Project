#ifndef OrcPlayer_H
#define OrcPlayer_H

#include <iostream>
#include <string>
#include "GeneralPlayer.h"

using namespace std;

class OrcPlayer : public GeneralPlayer
{
public:
	OrcPlayer();
	OrcPlayer(int);
	OrcPlayer(int, string);
	OrcPlayer(const OrcPlayer&);
	void setLevel(int);
	virtual void setAttr(int);
	virtual void levelUp(void);
	virtual void specialSkill();

private:

};
#endif