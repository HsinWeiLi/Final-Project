#ifndef AbstractMonster_H
#define AbstractMonster_H

#include <iostream>
#include <string>

using namespace std;

class GeneralPlayer;
class AbstractMonster
{
public:
	AbstractMonster(string, int, int, int, int, int, int);
	~AbstractMonster();
	void setHP(int);
	int getHP() const;
	void setMP(int);
	int getMP() const;
	virtual void attackTo(GeneralPlayer*) = 0;
	int getDefense() const;
	int getcount() const;
	string serialize() const;
	void unserialize(string);
	
	string name;
	int attack;
	int defense;
	int exp;
	int max_hp;
	int max_mp;
	static int countMonster; // stores the number of alive monsters
	int money_monster;

private:
	int hp;
	int mp;

protected:

};

#endif
