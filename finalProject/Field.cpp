#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Field.h"

using namespace std;

Field::Field(int**map_input, int length, int width, int X, int Y, int vision_width_input, int vision_height_input)
{
	map_data = new int*[length];
	for (int j = 0; j < length; j++)
		map_data[j] = new int [width];
	for (int j = 0; j < length; j++)
		for (int i = 0; i < width; i++)
			map_data[j][i] = map_input[j][i];

	setPosition(X, Y);
	setVisionSize(vision_width_input, vision_height_input);
	map_length = length;
	map_width = width;
	setStartAndDestination();
}
Field::Field(const char* file_name, int X, int Y, int vision_width_input, int vision_height_input)
{
	int width, length;
	string map_name;
	if (*file_name == '1')
		map_name = "1.txt";
	else if (*file_name == '2')
		map_name = "2.txt";
	else if (*file_name == '3')
		map_name = "3.txt";
	else if (*file_name == '4')
		map_name = "4.txt";
	else if (*file_name == '5')
		map_name = "5.txt";
	else
		map_name = "6.txt";

	ifstream data(map_name, ios::in);
	if (!data)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	}
	string info;
	getline(data, info);
	istringstream input(info);
	input >> width;
	input.get();
	input >> length;

	map_data = new int*[length];
	for (int j = 0; j < length; j++)
		map_data[j] = new int[width];

	int column = 0;
	int row;
	while (getline(data, info))
	{
		row = 0;
		for (int i = 0; i < info.length(); i++)
		{
			if (info[i] != ',')
			{
				int s;
				istringstream get(&info[i]);
				get >> s;
				if (s >= 10 && s < 100)
					i++;
				else if (s >= 100)
					i += 2;
				map_data[column][row] = s;
				row++;
			}
		}
		column++;
	}
	setPosition(X, Y);
	setVisionSize(vision_width_input, vision_height_input);
	map_length = length;
	map_width = width;
	setStartAndDestination();
}
bool Field::move(char direction)
{
	if (direction == 'U' || direction == 'u')
	{
		if (moveUp() == false)
			return false;
		else
		{
			current_position_y--;
			return true;
		}
	}
	else if (direction == 'D' || direction == 'd')
	{
		if (moveDown() == false)
			return false;
		else
		{
			current_position_y++;
			return true;
		}
	}
	else if (direction == 'R' || direction == 'r')
	{
		if (moveRight() == false)
			return false;
		else
		{
			current_position_x++;
			return true;
		}
	}
	else if (direction == 'L' || direction == 'l')
	{
		if (moveLeft() == false)
			return false;
		else
		{
			current_position_x--;
			return true;
		}
	}
	else return false;
}
bool Field::moveUp(void)
{
	if (map_data[current_position_y - 1][current_position_x] != 1)
		return true;
	else return false;
}
bool Field::moveDown(void)
{
	if (map_data[current_position_y + 1][current_position_x] != 1)
		return true;
	else return false;
}
bool Field::moveRight(void)
{
	if (map_data[current_position_y][current_position_x + 1] != 1)
		return true;
	else return false;
}
bool Field::moveLeft(void)
{
	if (map_data[current_position_y][current_position_x - 1] != 1)
		return true;
	else return false;
}
int Field::getCurrentPosition_x(void) const
{
	return current_position_x;
}
int Field::getCurrentPosition_y(void) const
{
	return current_position_y;
}
int Field::getVisionWidth(void) const
{
	return vision_width;
}
int Field::getVisionHeight(void) const
{
	return vision_hieght;
}
string Field::getMapName(void) const
{
	return map_name;
}
int Field::getMapSymbol(int x_input, int y_input)
{
	return map_data[y_input][x_input];
}
void Field::setPosition(int x_input, int y_input)
{
	current_position_x = x_input;
	current_position_y = y_input;
}
void Field::setMapSymbol(int symbol_input, int x_input, int y_input)
{
	map_data[y_input][x_input] = symbol_input;
}
void Field::setVisionSize(int width_input, int height_input)
{
	vision_width = width_input;
	vision_hieght = height_input;
}
void Field::display(void) const
{
	for (int j = 0; j < map_length; j++)
	{
		for (int i = 0; i < map_width; i++)
		{
			
			if (map_data[j][i] == 1) //wall
				cout << "¡½";
			else if (i == current_position_x && j == current_position_y) //player
				cout << " X";
			else if (map_data[j][i] == 200) //start
				cout << " S";
			else if (map_data[j][i] == 201) //destination
				cout << " D";
			else if (map_data[j][i] >= 202 || map_data[j][i] == 9) //bonus
				cout << "¡¸";
			else if (map_data[j][i] == 0) //the pace not taken
				cout << "  ";
		}
		cout << endl;
	}
}
int Field::getMapLength(void) const
{
	return map_length;
}
int Field::getMapWidth(void) const
{
	return map_width;
}
void Field::setStartAndDestination(void)
{
	for (int j = 0; j < map_length; j++)
		for (int i = 0; i < map_width; i++)
		{
			if (map_data[j][i] == 200)
			{
				start_x = i;
				start_y = j;
			}
			else if (map_data[j][i] == 201)
			{
				destination_x = i;
				destination_y = j;
			}
		}
}
int Field::getStart_x(void) const
{
	return start_x;
}
int Field::getStart_y(void) const
{
	return start_y;
}
int Field::getDestination_x(void) const
{
	return destination_x;
}
int Field::getDestination_y(void) const
{
	return destination_y;
}
void Field::do_map(void)
{
	char move_action;
	cout << "U(up)/ D(down)/ L(left)/ R(right)" << endl << "-";
	cin >> move_action;
	move(move_action);
	system("CLS");
	display();
}