#pragma once
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include <iostream>

#include "Score.h"
#include "Display.h"
#include "Shapes.h"
#include "ConsoleAttributes.h"

class Game
{
public:
	Game();
	~Game();



private:

	Score		Score;
	Display		display;
	Shapes		CurrentShape;
	std::vector<Coordinate> Map;
	std::vector<Shapes> Shapes;
	
	
	
	void Load_Map();
	void Load_Shapes();

	void ChooseShape();

	

};

