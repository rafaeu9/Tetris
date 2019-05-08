#pragma once
#include "Display.h"

class Map
{
public:
	
	Map();
	~Map();

	void Load(Coordinate inp_pos, int inp_width, int inp_height);

	void Create();

protected:

	Display		m_Display;

	Coordinate m_pos;

	//Map width
	int m_width{ 0 };

	//Map height
	int m_height{ 0 };
};

