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


void Coordinate::Add_Coordinate(Coordinate inp)
{
	X += inp.X;
	Y += inp.Y;
}

