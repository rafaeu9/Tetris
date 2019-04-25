#include "Score.h"



Score::Score()
{
}


Score::~Score()
{
}

void Score::SDisplay()
{
	std::stringstream oss;
	oss << "Score: " << m_Points;

	std::string m_Message{ oss.str() };

	m_Display.WriteMenssage(m_Coordinate, m_Message);
}

void Score::Add_Points()
{
	m_Points++;
}

int Score::GetPoints()
{
	return m_Points;
}
