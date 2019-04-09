#include "Shapes.h"




Shapes::Shapes(std::string Inp_Name, std::vector<Coordinate> Inp_Format, WORD Inp_Color, char Inp_Character)
	:m_Name{ Inp_Name }, m_Format{ Inp_Format }, m_Color{Inp_Color}, m_Character{Inp_Character}
{
	m_Coordinate.Add(4, 4);
	for (int i = 0; i < m_Format.size(); i++)
	{
		m_Format[i].Add_Coordinate(m_Coordinate);
	}	
}

Shapes::~Shapes()
{
}

void Shapes::Move()
{

	

	while (true)
	{
		ScreenDisplay();
		
		Sleep(1000);
		

		for (int i = 0; i < m_Format.size(); i++)
		{
			m_Format[i].Y += Move_Speed;
		}

	
	}

	
}

void Shapes::ScreenDisplay()
{
	for (int i = 0; i < m_Format.size(); i++)
	{
		m_Display.WriteChar(m_Format[i], m_Character, m_Color);
	}
}

void Shapes::ScreenDelete()
{
	for (int i = 0; i < m_Format.size(); i++)
	{
		m_Display.WriteChar(m_Format[i],' ', WHITE_ON_BLACK);
	}
}
