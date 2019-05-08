#include "Map.h"



Map::Map()
{
}



Map::~Map()
{
}

void Map::Load(Coordinate inp_pos, int inp_width, int inp_height)
{
	m_pos.Add_Coordinate(inp_pos);
	m_width = inp_width;
	m_height = inp_height;
}

void Map::Create()
{

	//diplay the top wall of the map
	for (int i = 0; i < m_width; i++)
	{
		m_Display.WriteChar(Coordinate(i + m_pos.X, m_pos.Y), (char)178, WHITE_ON_BLACK);
	}

	//diplay the bottom wall of the map
	for (int i = 0; i < m_width; i++)
	{
		m_Display.WriteChar(Coordinate(i + m_pos.X, m_height + m_pos.Y), (char)178, WHITE_ON_BLACK);
	}

	//diplay the left wall of the map
	for (int i = 0; i < m_height; i++)
	{
		m_Display.WriteChar(Coordinate(m_pos.X, i + m_pos.Y), (char)178, WHITE_ON_BLACK);
	}

	//diplay the right wall of the map
	for (int i = 0; i < 1 + m_height; i++)
	{
		m_Display.WriteChar(Coordinate(m_width + m_pos.X,  i + m_pos.Y), (char)178, WHITE_ON_BLACK);
	}

}
