#pragma once
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include <iostream>
#include <random>
#include <assert.h>

#include "Score.h"
#include "Display.h"
#include "Shapes.h"
#include "ConsoleAttributes.h"
#include "DetectLine.h"
#include "Map.h"
#include "RandomNumber.h"
#include "Tester.h"

class Game
{
public:
	Game();
	~Game();

	void PlayGame();

	void Start();

	void TestMode(const std::string& testlife);

protected:

	Score	m_Score;
	
	Display	m_Display;

	Map		m_Map;	

	RandomNumber m_RandNumb;		

	

	//Map width
	int		m_MapWidth{ 11 };

	//Map height
	int		m_MapHeight{ 21 };

	// Loded shapes
	std::vector<Shapes> m_Shapes;
	
	// Get Shapes from Shapes.txt
	void	LoadShapes();
	
	//check if the game is over
	bool	GameOver();
	
	void GameOverMenu();
};

