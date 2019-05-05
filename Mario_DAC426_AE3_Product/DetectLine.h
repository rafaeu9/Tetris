#pragma once
#include <iostream> 
#include <stack> 

#include"Display.h"
#include"Coordinate.h"
#include"Game.h"


class DetectLine
{	
public:

	DetectLine();
	~DetectLine();
	
	void config(int inp_width, int inp_height);

	int check();

protected:

	Display m_Display;

	Coordinate CheckPos;

	int m_widt{ 0 };
	int m_height{0};

	int LineChar{0};
	int MaxLineChar{ m_widt };

	int LineEmpChar{ 0 };
	int TopLine{ 0 };

	std::stack <int> FullLines;

	int Points{ 0 };
};

