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

protected:

	Score		Score;
	Display		display;
	
	
	std::vector<Coordinate> m_Map;
	std::vector<Shapes> m_Shapes;
	
	void Load_Map();
	void Load_Shapes();
	void Choose_Shape();
};

