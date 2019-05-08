#include "Coordinate.h"



Coordinate::Coordinate()
{
}

Coordinate::Coordinate(int Inp_X, int Inp_Y)
	:X{Inp_X}, Y{Inp_Y}
{
}


Coordinate::~Coordinate()
{
}

void Coordinate::Add(int inp_X, int inp_Y)
{
	X += inp_X;
	Y += inp_Y;
}

void Coordinate::Copy(int inp_X, int inp_Y)
{
	X = inp_X;
	Y = inp_Y;
}


void Coordinate::AddCoordinate(Coordinate inp)
{
	X += inp.X;
	Y += inp.Y;
}

void Coordinate::CopyCoordinate(Coordinate inp)
{
	X = inp.X;
	Y = inp.Y;
}
