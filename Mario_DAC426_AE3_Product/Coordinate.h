#pragma once
class Coordinate
{
public:
	
	Coordinate();

	Coordinate(int Inp_X, int Inp_Y);

	~Coordinate();

	void Add(int inp_X, int inp_Y);

	void Add_Coordinate(Coordinate inp);

	int X{ 0 };
	int Y{ 0 };
};

