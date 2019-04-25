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

class Game
{
public:
	Game();
	~Game();

	void Play_Game();

protected:

	Score		Score;
	Display		display;
	
	// Format of the Map
	std::vector<Coordinate> m_Map;

	// Loded shapes
	std::vector<Shapes> m_Shapes;
	
	// Get Map from Map.txt and display 
	void Load_Map();

	// Get Shapes from Shapes.txt
	void Load_Shapes();

	// Choose a random Shape
	void Choose_Shape();

	int Random_Shape (int high);
	
	int map_width{ 11 };

	const int map_height{ 21 };
	

	std::vector<Shapes> m_save_shapes;
};

