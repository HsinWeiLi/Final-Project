#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "GeneralPlayer.h"
#include "KnightPlayer.h"
#include "MagicianPlayer.h"
#include "OrcPlayer.h"
#include "AbstractMonster.h"
#include "GoblinMonster.h"
#include "Battle.h"
#include "Field.h"
#include "Item.h"
#include "WeaponItem.h"
#include "ArmorItem.h"
#include "ConsumableItem.h"
#include "SelectList.h"

using namespace std;

int main()
{
	bool gameover = false;
	SelectList Select;
	cout << "Welcome to this GAME" << endl;
	cout << "---Select Action---" << endl
		<< "1. Start New Game" << endl
		<< "2. Continue the Last Game" << endl << "-";
	int action = Select.selectCheck(1, 2);
	system("CLS");

	GeneralPlayer **Players = new GeneralPlayer*[1];
	Players[0] = new GeneralPlayer;
	switch (action)
	{
	case 1:
		cout << "Welcome to the Start Villige" << endl << endl
			<< "You are going to start an adventure and to find the treasure from JWMonster" << endl << endl;
		system("PAUSE");
		cout << endl << "Now choose your career" << endl
			<< "There are 4 kinds of jobs:" << endl
			<< "1. General People" << endl
			<< "2. Knight" << endl
			<< "3. Magician" << endl
			<< "4. Orc" << endl << "-";
		int job = Select.selectCheck(1, 4);
		enum job{General = 1, Knight, Magician, Orc};
		if (job == General)
		{
			GeneralPlayer General(1);
			cout << "Input your name: ";
			string namePlayer;
			cin >> namePlayer;
			General.setName(namePlayer);
			system("CLS");
			cout << "---Player's Information---" << endl
				<< "Name: " << General.getName() << endl
				<< "Level: " << General.getLevel() << endl
				<< "HP: " << General.getHP() << "/" << General.getMaxHP() << endl
				<< "MP: " << General.getMP() << "/" << General.getMaxMP() << endl
				<< "Exp: " << General.getExp() << endl
				<< "Attack: " << General.getAttack() << endl
				<< "Defense: " << General.getDefense() << endl
				<< "Money: " << General.getMoney() << endl << endl;
			//GeneralPlayer *Players = new  GeneralPlayer[1];
			Players[0] = &General;
		}
		else if (job == Knight)
		{
			KnightPlayer Knight(1);
			cout << "Input your name: ";
			string namePlayer;
			cin >> namePlayer;
			Knight.setName(namePlayer);
			system("CLS");
			cout << "---Player's Information---" << endl
				<< "Name: " << Knight.getName() << endl
				<< "Level: " << Knight.getLevel() << endl
				<< "HP: " << Knight.getHP() << "/" << Knight.getMaxHP() << endl
				<< "MP: " << Knight.getMP() << "/" << Knight.getMaxMP() << endl
				<< "Exp: " << Knight.getExp() << endl
				<< "Attack: " << Knight.getAttack() << endl
				<< "Defense: " << Knight.getDefense() << endl
				<< "Money: " << Knight.getMoney() << endl << endl;
			//GeneralPlayer *Players = new  GeneralPlayer[1];
			Players[0] = &Knight;
		}
		else if (job == Magician)
		{
			MagicianPlayer Magician;
			cout << "Input your name: ";
			string namePlayer;
			cin >> namePlayer;
			Magician.setName(namePlayer);
			system("CLS");
			cout << "---Player's Information---" << endl
				<< "Name: " << Magician.getName() << endl
				<< "Level: " << Magician.getLevel() << endl
				<< "HP: " << Magician.getHP() << "/" << Magician.getMaxHP() << endl
				<< "MP: " << Magician.getMP() << "/" << Magician.getMaxMP() << endl
				<< "Exp: " << Magician.getExp() << endl
				<< "Attack: " << Magician.getAttack() << endl
				<< "Defense: " << Magician.getDefense() << endl
				<< "Money: " << Magician.getMoney() << endl << endl;
			//GeneralPlayer *Players = new  GeneralPlayer[1];
			Players[0] = &Magician;
		}
		else if (job == Orc)
		{
			OrcPlayer Orc;
			cout << "Input your name: ";
			string namePlayer;
			cin >> namePlayer;
			Orc.setName(namePlayer);
			system("CLS");
			cout << "---Player's Information---" << endl
				<< "Name: " << Orc.getName() << endl
				<< "Level: " << Orc.getLevel() << endl
				<< "HP: " << Orc.getHP() << "/" << Orc.getMaxHP() << endl
				<< "MP: " << Orc.getMP() << "/" << Orc.getMaxMP() << endl
				<< "Exp: " << Orc.getExp() << endl
				<< "Attack: " << Orc.getAttack() << endl
				<< "Defense: " << Orc.getDefense() << endl
				<< "Money: " << Orc.getMoney() << endl << endl;
			//GeneralPlayer *Players = new GeneralPlayer[1];
			Players[0] = &Orc;
		}
	}
	Select.select_pause(Players[0]);

	system("CLS");
	Field field1("1", 1, 1, 3, 3);
	field1.display();
	bool map1_finish = false;
	while (map1_finish == false)
	{
		field1.do_map();
		if (field1.getCurrentPosition_x() == field1.getDestination_x() && field1.getCurrentPosition_y() == field1.getDestination_y())
			map1_finish = true;
	}
	system("CLS");
	Field field2("2", 1, 1, 3, 3);
	field2.display();
	bool map2_finish = false;
	while (map2_finish == false)
	{
		field2.do_map();
		if (field2.getCurrentPosition_x() == field2.getDestination_x() && field2.getCurrentPosition_y() == field2.getDestination_y())
			map2_finish = true;
	}
	Field field3("3", 1, 1, 3, 3);
	field3.display();
	bool map3_finish = false;
	while (map3_finish == false)
	{
		field3.do_map();
		if (field3.getCurrentPosition_x() == field3.getDestination_x() && field3.getCurrentPosition_y() == field3.getDestination_y())
			map3_finish = true;
	}
	system("Pause");
	
	return 0;
}