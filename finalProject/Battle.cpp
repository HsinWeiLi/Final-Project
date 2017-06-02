#include <iostream>
#include <string>
#include <stdio.h>
#include "Battle.h"

using namespace std;

Battle::Battle(GeneralPlayer** Player, AbstractMonster** Monster, int numberPlayer_input, int numberMonster_input, int limit_input)
{
	turnNumber = 0;
	turnLimit = limit_input;
	numberPlayer = numberPlayer_input;
	numberMonster = numberMonster_input;

	actionList = new Character[numberPlayer_input + numberMonster_input];
	for (int i = 0; i < (numberPlayer_input + numberMonster_input); i++)
		actionList[i].alive = true; // all the characters are alive

	Player = new GeneralPlayer*[numberPlayer_input];
	for (int i = 0; i < numberPlayer_input; i++)
	{
		actionList[i].type = 'p';
		actionList[i].instance = static_cast<void*>(Player[i]);
	}
	Monster = new AbstractMonster*[numberMonster_input];
	for (int i = numberPlayer_input; i < (numberPlayer_input + numberMonster_input); i++)
	{
		actionList[i].type = 'm';
		actionList[i].instance = static_cast<void*>(Monster[i - numberPlayer_input]);
	}

	fight(numberMonster_input, numberPlayer_input);
}
Battle::Battle(GeneralPlayer** Player, AbstractMonster** Monster, int numberPlayer_input, int numberMonster_input)
{
	turnNumber = 0;
	turnLimit = 0;
	numberPlayer = numberMonster_input;
	numberMonster = numberMonster_input;

	actionList = new Character[numberPlayer_input + numberMonster_input];
	for (int i = 0; i < (numberPlayer_input + numberMonster_input); i++)
		actionList[i].alive = true; // all the characters are alive

	Player = new GeneralPlayer*[numberPlayer_input];
	for (int i = 0; i < numberPlayer_input; i++)
	{
		actionList[i].type = 'p';
		actionList[i].instance = static_cast<void*>(Player[i]);
	}
	Monster = new AbstractMonster*[numberMonster_input];
	for (int i = numberPlayer_input; i < (numberPlayer_input + numberMonster_input); i++)
	{
		actionList[i].type = 'm';
		actionList[i].instance = static_cast<void*>(Monster[i - numberPlayer_input]);
	}

	fight(numberPlayer_input, numberMonster_input);
}
bool Battle::nextActor(void) // move to next actor, if all character were done, n_turn++
{
	if (turnNumber == turnLimit)
		return true;
	else
	{
		turnNumber++;
		return false;
	}
}
int Battle::getTurnCount(void) const // get the current number of turn
{
	return turnNumber;
}
int Battle::getTurnLimit(void) const // get the limit on number of turns, 0 or no limit
{
	return turnLimit;
}
int Battle::getPlayerCount(void) const // get the current number of players
{
	return numberPlayer;
}
int Battle::getPlayerCount(bool alive_input) const // get the current number of players alive
{
	int player_alive = 0;
	for (int i = 0; i < numberPlayer; i++)
		if (actionList[i].alive == true)
			player_alive++;

	return player_alive;
}
int Battle::getMonsterCount(void) const // get the current number of monsters
{
	return numberMonster;
}
int Battle::getMonsterCount(bool alive_input) const // get the current number of monsters alive
{
	int monster_alive = 0;
	for (int i = 0; i < numberMonster; i++)
		if (actionList[i].alive == true)
			monster_alive++;

	return monster_alive;
}
Character Battle::getCurrentActor(void) // get the current actor within the action list
{
	GeneralPlayer* temp_player;
	AbstractMonster* temp_monster;
	if (actionList[turnNumber].type == 'p')
		temp_player = static_cast<GeneralPlayer*>(actionList[turnNumber].instance);
	else if (actionList[turnNumber].type == 'm')
		temp_monster = static_cast<AbstractMonster*>(actionList[turnNumber].instance);

	return actionList[turnNumber];
}
Character* Battle::getPlayers(void) // get a full list of players, no matter dead of alive ones
{
	Character* playerList = new Character[numberPlayer];
	for (int i = 0; i < numberPlayer; i++)
		playerList[i] = actionList[i];

	return playerList;
}
Character* Battle::getMonsters(void) // get a full list of monsters, no matter dead of alive ones
{
	Character* monsterList = new Character[numberMonster];
	for (int i = 0; i < numberMonster; i++)
		monsterList[i] = actionList[i + numberPlayer];

	return monsterList;
}
void Battle::fight(int number_player, int number_monster)
{
	bool check;
	if (nextActor() == 0)
		check = 0;
	else if (number_player > 0 && number_monster > 0)
		check = 1;
	else
		check = 0;
	if (turnLimit == 0) 
	{
		if (number_player > 0 && number_monster > 0)
			check = 1;
		else
			check = 0;
	}
	while (check)
	{
		cout << "---BATTLE---" << endl << endl <<  "START "  << endl << "Turn: " << getTurnCount() << endl;
		cout << "The number of players is: " << getPlayerCount() << endl
			<< "The number of monsters is: " << getMonsterCount() << endl << endl;

		for (int i = 0; i < number_player; i++) {
			cout << "Round:" << getTurnCount();
			if (actionList[i].alive == true) 
			{
				tmp_player = static_cast<GeneralPlayer*>(actionList[i].instance);
				for (int j = number_player; j < number_player + number_monster; j++)
				{
					if (actionList[j].alive == true) {
						tmp_monster = static_cast<AbstractMonster*>(actionList[j].instance);

						cout << "Players' Information :" << endl;
						showPlayerInfo(tmp_player);
						cout << endl << endl;

						cout << "Monsters' Information: " << endl;
						showMonsterInfo(tmp_monster);
						cout << endl << endl;

						cout << "---Action---" << endl
							<< "1. Attack!!!" << endl
							<< "2. PASS" << endl
							<< "3. Do something Special" << endl
							<< "4. RUN!!!" << endl;
						enum action { attack = 1, pass, specialSkill, run };
						int action;
						cin >> action;
						if (action == attack)
						{
							tmp_player->attackTo(tmp_monster);
							cout << tmp_player->getName() << " attack to " << tmp_monster->name << endl << endl;
						}
						else if (action == pass)
						{
							cout << tmp_player->getName() << " want to pass" << endl << endl;
							break;
						}
						else if (action == specialSkill) 
						{
							cout << tmp_player->getName() << "want to do something special" << endl << endl;
							tmp_player->specialSkill();
						}
						else if (action == run) 
							break;
						
						cout << "Players' information" << endl;
						showPlayerInfo(tmp_player);
						cout << endl << endl << "Monsters' information  :" << endl;
						showMonsterInfo(tmp_monster);
						cout << endl << endl;

						if (tmp_monster->getHP() <= 0)
						{
							cout << tmp_player->getName() << " kill " << tmp_monster->name << " successfully!!!" << endl << endl;
							actionList[j].alive = false;
							number_monster--;
						}
						break;
					}
				}
			}
		}
		system("pause");

		for (int i = numberPlayer; i< numberPlayer + number_monster; i++)
		{
			if (actionList[i].alive == true) {
				tmp_monster = static_cast<AbstractMonster*>(actionList[i].instance);
				for (int j = 0; j < number_player; j++)
				{
					if (actionList[i].alive == true) {
						tmp_player = static_cast<GeneralPlayer*>(actionList[i].instance);

						cout << "Players' Information :" << endl;
						showPlayerInfo(tmp_player);
						cout << endl << endl;

						cout << "Monsters' Information: " << endl;
						showMonsterInfo(tmp_monster);
						cout << endl << endl;

						tmp_monster->attackTo(tmp_player);
						cout << endl;
						cout << tmp_monster->name << " attack to " << tmp_player->getName() << endl;

						cout << "Players' information" << endl;
						showPlayerInfo(tmp_player);
						cout << endl << endl << "Monsters' information  :" << endl;
						showMonsterInfo(tmp_monster);
						cout << endl << endl;

						if (tmp_player->getHP() <= 0) {
							cout << endl;
							cout << tmp_monster->name << " kill " << tmp_player->getName() << endl << endl;
							actionList[j].alive = false;
							number_player--;
						}
						break;
					}
				}
			}
		}
		turnNumber++;

		if (turnLimit == 0) {//回合結束的確認
			if (number_player > 0 && number_monster > 0)
				check = 1;
			else
				check = 0;
		}
		else
		{
			if (nextActor() == 0)
				check = 0;
			else if (number_player > 0 && number_monster > 0) 
				check = 1;
			else
				check = 0;
		}
		system("PAUSE");
		system("CLS");
	}
	if (number_player == 0)
		cout << "Players lose the battle" << endl;
	else if (number_monster == 0)
		cout << "Monsters lose." << endl;
	else
		cout << "END" << endl;
	system("pause");
}
void Battle::showPlayerInfo(GeneralPlayer* Player)
{
	cout << "Name : " << Player->getName() << endl
		<< "Level : " << Player->getLevel() << endl
		<< "HP : " << Player->getHP() << "/" << Player->getMaxHP() << endl
		<< "MP : " << Player->getMP() << "/" << Player->getMaxMP() << endl
		<< "Attack : " << Player->getAttack() << endl
		<< "Defense : " << Player->getDefense() << endl
		<< "Exp : " << Player->getExp() << endl
		<< "Money : " << Player->getMoney() << endl << endl;
}
void Battle::showMonsterInfo(AbstractMonster* Monster)
{
	cout << "Name : " << Monster->name << endl
		<< "HP : " << Monster->getHP() << endl
		<< "MP : " << Monster->getMP() << endl
		<< "Attack : " << Monster->attack << endl
		<< "Defense : " << Monster->getDefense() << endl
		<< "Exp : " << Monster->exp << endl
		<< "Money : " << Monster->money_monster << endl << endl;
}