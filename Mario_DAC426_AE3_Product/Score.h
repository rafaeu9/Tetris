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

	// Display Score on the Screen
	void	SDisplay();

	// Add a point in the score
	void	Add_Points(int inp_points);

	// Get the actual points
	int		GetPoints();

private:

	// Actual points
	int		m_Points{ 0 };

	// Position of the scor on the screen
	Coordinate m_Coordinate;

	// Display in the Screen
	Display m_Display;	
};

