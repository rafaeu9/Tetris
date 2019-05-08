#pragma once
#include <iostream> 
#include <string>
#include <vector>
#include <Windows.h>

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

	// Name of the shape
	std::string		Name;


	// Display Shape on the Screen
	void ScreenDisplay(char Inp_Char, WORD Inp_Colour);

	// Delete Shape from the Screen
	void ScreenDelete();

	Coordinate	m_Coordinate;

protected:

	

	Display		m_Display;

	//Shape Character
	char		m_Char;

	// Color of the shape
	WORD		m_Color;

	// Movement speed of the shape
	int			m_MoveSpeed{ 1 };

	//actual rotation position 
	int			m_ActualRotation{ 0 };

	// Format of the shape
	std::vector<Coordinate>	m_Format;

	//Store of the rotation positions
	std::vector<std::vector<Coordinate>> m_Rotation;

	//rotations possible
	int m_MaxRotation = m_Rotation.size();
		
	//Detect the current shape on the input position
	bool DetectLimit(int CheckPosX, int CheckPosY);

	// Get input to move shape
	void UserInput();	
};

