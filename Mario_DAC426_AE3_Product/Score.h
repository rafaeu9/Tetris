#pragma once

#include <conio.h>

#include <sstream>
#include "Coordinate.h" 
#include "Display.h"

class Score
{
public:
	Score();
	~Score();

	void	SDisplay();

	void	Add_Points();
	int		GetPoints();

private:

	int		m_Points{ 0 };
	Coordinate m_Coordinate;
	Display m_Display;	

	
	

	

};

