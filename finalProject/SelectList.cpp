#include <iostream>
#include <string>
#include "SelectList.h"
#include "GeneralPlayer.h"
#include "Field.h"

using namespace std;

SelectList::SelectList()
{
}
void SelectList::select_pause(GeneralPlayer* Player)
{
	cout << "---PAUSE---" << endl
		<< "1. Continue" << endl
		<< "2. View the backpack" << endl
		<< "3. Save the game and exit" << endl
		<< "4. Restart" << endl << "-";
	
	enum Select { Continue = 1, viewBackpack, SaveAndExit, Restart };
	int action;
	cin >> action;
	switch (action)
	{
	case Continue:
		break;
	case viewBackpack:
		cout << "---Backpack---" << endl;
		Player->showBackpack();
		break;
	case SaveAndExit:
		Player->serialize();
		break;
	case Restart:
		break;
	default:
		break;
	}
}
int SelectList::selectCheck(int min, int max)
{
	int action;
	cin >> action;
	while (action<min || action>max)
	{
		cout << "Error number!" << endl
			<< "Please input a number between " << min << " and " << max << endl << "-";
		cin >> action;
	}
	return action;
}