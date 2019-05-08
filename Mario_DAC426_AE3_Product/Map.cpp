#include "Map.h"



Map::Map()
{
}



Map::~Map()
{
}

void Map::Load(Coordinate inp_pos, int inp_width, int inp_height)
{
	m_Pos.AddCoordinate(inp_pos);
	m_Width = inp_width;
	m_Height = inp_height;
}

void Map::Create()
{

	//diplay the top wall of the map
	for (int i = 0; i < m_Width; i++)
	{
		m_Display.WriteChar(Coordinate(i + m_Pos.X, m_Pos.Y), (char)178, WHITE_ON_BLACK);
	}

	//diplay the bottom wall of the map
	for (int i = 0; i < m_Width; i++)
	{
		m_Display.WriteChar(Coordinate(i + m_Pos.X, m_Height + m_Pos.Y), (char)178, WHITE_ON_BLACK);
	}

	//diplay the left wall of the map
	for (int i = 0; i < m_Height; i++)
	{
		m_Display.WriteChar(Coordinate(m_Pos.X, i + m_Pos.Y), (char)178, WHITE_ON_BLACK);
	}

	//diplay the right wall of the map
	for (int i = 0; i < 1 + m_Height; i++)
	{
		m_Display.WriteChar(Coordinate(m_Width + m_Pos.X,  i + m_Pos.Y), (char)178, WHITE_ON_BLACK);
	}

}
