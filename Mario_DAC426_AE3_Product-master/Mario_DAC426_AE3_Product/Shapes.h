#pragma once
#include <iostream> 
#include <string>
#include <vector>
#include <Windows.h>
#include <time.h>


#include "Coordinate.h"
#include "Display.h"

using namespace std;

class Shapes
{
public:
	// Create a new shape (Name of the shape, format in coordinate of the shape, color, character)
	Shapes(std::string Inp_Name, std::vector<Coordinate> Inp_Format, WORD Color, char Inp_Character);	

	~Shapes();

	// Move shape
	void Move();

	bool detect_limit(int CheckPosX, int CheckPosY);

	// Display Shape on the Screen
	void ScreenDisplay();

	// Delete Shape from the Screen
	void ScreenDelete();

private:

	Coordinate		m_Coordinate;
	// Name of the shape
	std::string		m_Name;

	// Format of the shape
	std::vector<Coordinate> m_Format;

	std::vector<Coordinate> original_Format;

	// Color of the shape
	WORD			m_Color;

	// Character inside of the shape
	char			m_Character;

	Display			m_Display;
	
	// Movement speed of the shape
	int				Move_Speed{ 1 };

	int rotation{ 0 };
	int Rot_Ajust_X{ 0 };
	int Rot_Ajust_Y{ 0 };

	// Detect Colition
	void Colition();

	

	// Get input to move shape
	void UserInput();	

	HANDLE ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

};

