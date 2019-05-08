#pragma once
#include <iostream> 
#include <string>
#include <vector>
#include <Windows.h>
#include <time.h>
#include <math.h> 


#include "Coordinate.h"
#include "Display.h"

using namespace std;

class Shapes
{
public:
	// Create a new shape (Name of the shape, format in coordinate of the shape, color, character)
	Shapes(std::string Inp_Name, std::vector<std::vector<Coordinate>> Inp_Format, char Inp_Char, WORD Color);

	~Shapes();

	// Move shape
	void Move();

private:

	Coordinate		m_Coordinate;
	// Name of the shape
	std::string		m_Name;

	// Format of the shape
	std::vector<Coordinate> m_Format;

	//Shape Character
	char m_Char;
	
	// Color of the shape
	WORD			m_Color;
	
	Display			m_Display;

	// Display Shape on the Screen
	void ScreenDisplay(char c, WORD co);

	// Delete Shape from the Screen
	void ScreenDelete();

	// Movement speed of the shape
	int			Move_Speed{ 1 };

	//actual rotation position 
	int rotation{ 0 };

	//Store of the rotation positions
	std::vector<std::vector<Coordinate>> m_rotation;

	//rotations possible
	int max_rotion = m_rotation.size();
	
	//Detect the current shape on the input position
	bool detect_limit(int CheckPosX, int CheckPosY);

	// Get input to move shape
	void UserInput();	
	

};

