#ifndef Field_H
#define Field_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Field
{
public:
	Field(int**, int, int, int, int, int, int); // (map_data, length, width, X, Y, vision_width, vision_height)
	Field(const char*, int, int, int, int); // (file_name, X, Y, vision_width, vision_height)
	
	bool move(char); // Move player to next position, the parameter is the direction
	// The same as move(char), move player to next position. But the direction is determined
	bool moveUp(void);
	bool moveDown(void);
	bool moveRight(void);
	bool moveLeft(void);
	// The return value indicates whether this move is legal or not

	// These methods get the information of the map
	int getCurrentPosition_x(void) const;
	int getCurrentPosition_y(void) const;
	int getVisionWidth(void) const;
	int getVisionHeight(void) const;
	string getMapName(void) const;
	int getMapSymbol(int, int);

	void setPosition(int, int); // Set the position of player (X, Y)
	void setMapSymbol(int, int, int); // Set the symbol on a specific position (Symbol, X, Y)
	void setVisionSize(int, int); // Set the size of vision, parameters are (width, height)
	void display(void) const; // Displaying the map

	int getMapLength(void) const;
	int getMapWidth(void) const;
	void setStartAndDestination(void);
	int getStart_x(void) const;
	int getStart_y(void) const;
	int getDestination_x(void) const;
	int getDestination_y(void) const;
	
	void do_map(void);

private:
	int** map_data; // The actual map data with symbols and items

	// Current position of player
	int current_position_x;
	int current_position_y;
	// This can be used to display the map (player is always on the center)

	string map_name;
	int vision_width;
	int vision_hieght;

	int map_length;
	int map_width;
	int start_x;
	int start_y;
	int destination_x;
	int destination_y;
};

#endif