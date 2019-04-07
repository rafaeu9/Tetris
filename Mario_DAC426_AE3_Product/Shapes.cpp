#include "Shapes.h"



Shapes::Shapes(std::string Inp_Name, std::vector<Coordinate> Inp_Format, WORD Inp_Color, char Inp_Character)
	:m_Name{ Inp_Name }, m_Format{ Inp_Format }, m_Color{Inp_Color}, m_Character{Inp_Character}
{
}

Shapes::~Shapes()
{
}

void Shapes::Move()
{

	for (int i = 0 ; i == m_Format.size(); i++)
	{
				m_Display.WriteChar(m_Format[i], m_Character, m_Color);
	}

	
}
