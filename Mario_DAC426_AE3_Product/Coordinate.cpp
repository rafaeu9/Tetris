#include "Coordinate.h"



Coordinate::Coordinate()
{
}

Coordinate::Coordinate(int Inp_X, int Inp_Y)
	:m_X{Inp_X}, m_Y{Inp_Y}
{
}


Coordinate::~Coordinate()
{
}

void Coordinate::Add_X(int Add)
{
	m_X += Add;
}

void Coordinate::Add_Y(int Add)
{
	m_Y += Add;
}

void Coordinate::Add(Coordinate Add)
{
	m_X += Add.X();
	m_Y += Add.Y();
}

int Coordinate::X()
{
	return m_X;
}

int Coordinate::Y()
{
	return m_Y;
}
