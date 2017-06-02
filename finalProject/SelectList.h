#include <iostream>
#include <string>
#include "GeneralPlayer.h"
#include "Field.h"

using namespace std;

class GeneralPlayer;
class Field;
class SelectList
{
public:
	SelectList();
	void select_pause(GeneralPlayer*);
	int selectCheck(int, int);
};