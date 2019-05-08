#pragma once
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include <iostream>
#include <random>

#include "Score.h"
#include "Display.h"
#include "Shapes.h"
#include "ConsoleAttributes.h"
#include "DetectLine.h"
#include "Map.h"
#include "RandomNumber.h"

class Game
{
public:
	Game();
	~Game();

	void Play_Game();

protected:

	Score		m_Score;
	
	Display		m_Display;

	Map m_Map;	

	RandomNumber m_RandNumb;			

	// Loded shapes
	std::vector<Shapes> m_Shapes;
	
	// Get Shapes from Shapes.txt
	void Load_Shapes();
	
	//check if the game is over
	bool GameOver();

	//Map width
	int map_width{ 11 };
	
	//Map height
	int map_height{ 21 };
	
	//Store loded shapes
	std::vector<Shapes> m_save_shapes;

	
};

