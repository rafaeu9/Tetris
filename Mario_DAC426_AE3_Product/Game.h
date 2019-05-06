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

class Game
{
public:
	Game();
	~Game();

	void Play_Game();

protected:

	Score		m_Score;
	
	Display		m_Display;
	
	
	
		
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

	//Spawn a random shape
	int Random_Shape (int high);
	
	bool GameOver();

	


	//Map width
	int map_width{ 11 };
	
	//Map height
	const int map_height{ 21 };
	
	//Store loded shapes
	std::vector<Shapes> m_save_shapes;

	
};

