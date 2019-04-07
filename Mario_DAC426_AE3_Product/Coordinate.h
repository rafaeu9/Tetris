#pragma once
class Coordinate
{
public:
	Coordinate();

	Coordinate(int Inp_X, int Inp_Y);


	~Coordinate();

	void Add_X(int Add);
	void Add_Y(int Add);
	void Add(Coordinate Add);

	int X();
	int Y();

private:

	int m_X{ 0 };
	int m_Y{ 0 };

};

