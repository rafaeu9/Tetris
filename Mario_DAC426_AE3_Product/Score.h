#pragma once
#include <conio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Coordinate.h" 
#include "Display.h"
#include "Save.h"

class Score
{
public:
	Score();
	~Score();

	// Display Score on the Screen
	void	SDisplay();

	// Add a point in the score
	void	AddPoints(int inp_points);

	// Get the actual points
	int		GetPoints();

	void Load();

	void Write(std::string Inp_Name);

	std::vector<Save> Top;

protected:

	// Actual points
	int		m_Points{ 0 };

	// Position of the scor on the screen
	Coordinate m_Coordinate;

	// Display in the Screen
	Display m_Display;	

	

	int TopSize{ 10 };
};

