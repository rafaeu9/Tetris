#pragma once
class Coordinate
{
public:
	
	// Create a simpel Coordinate
	Coordinate();

	// Create a Coordinate (X, Y)
	Coordinate(int Inp_X, int Inp_Y);

	~Coordinate();

	// Add to the X and Y at the same time (X, Y)
	void Add(int inp_X, int inp_Y);

	// Add wiht anoder Coordinate
	void Add_Coordinate(Coordinate inp);

	int X{ 0 };
	int Y{ 0 };
};

