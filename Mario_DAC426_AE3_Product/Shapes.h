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
	Shapes(std::string Inp_Name, std::vector<Coordinate> Inp_Format, WORD Color, char Inp_Character);
	~Shapes();

	void Move();

	
private:

	Coordinate		m_Coordinate;
	std::string		m_Name;
	std::vector<Coordinate> m_Format;
	WORD			m_Color;
	char			m_Character;
	Display			m_Display;
	int				Move_Speed{ 1 };

	void Colition();
	void ScreenDisplay();
	void ScreenDelete();
};

