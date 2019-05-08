#pragma once
#include <iostream>
#include <random>
class RandomNumber
{
public:
	RandomNumber();
	~RandomNumber();

	int Create(int low = 0,int high = 0);

protected:

	std::random_device rd;

	std::mt19937 mt_rand{ rd() };
};

