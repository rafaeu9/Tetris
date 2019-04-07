#pragma once
#include "Score.h"
#include "Display.h"
#include "Shapes.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void Load_Map();
	void Load_Shapes();
private:

	Score Score;
	Display display;
	std::vector<Coordinate> Map;

	

};

