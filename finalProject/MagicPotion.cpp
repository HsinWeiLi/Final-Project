#include <iostream>
#include <string>
#include "MagicPotion.h"
#include "ConsumableItem.h"
#include "GeneralPlayer.h"

using namespace std;

MagicPotion::MagicPotion(int level_required_input, string name_input, string effects_input, string description_input,
	int weight_input, char type_input, int mp_increment_input)
	:ConsumableItem(level_required_input, name_input, effects_input, description_input, weight_input, type_input),
	mp_increment(mp_increment_input)
{

}
void MagicPotion::use(GeneralPlayer* user)
{
	user->increaseMP(mp_increment);
}