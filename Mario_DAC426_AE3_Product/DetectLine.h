#pragma once
#include <iostream> 
#include <stack> 

#include"Display.h"
#include"Coordinate.h"


class DetectLine
{	
public:

	DetectLine(int inp_width, int inp_height);
	~DetectLine();
		
	int Check();

protected:

	Display		m_Display;

	Coordinate  m_CheckPos;

	//area wher will scan
	int		m_Width{ 0 };
	int		m_Height{10};

	//count how many characters are in the line
	int		m_LineChar{0};

	//Max of character on the line
	int		m_MaxLineChar;

	//count how many empty spaces are in the line
	int		m_LineEmpChar{ 0 };

	//save the Y of the top line
	int		m_TopLine{ 0 };

	//save the Y of the full lines
	std::stack <int>  m_FullLines;

	//save the quantaty of full lines
	int		m_Points{ 0 };
};

