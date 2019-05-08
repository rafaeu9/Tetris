#include "RandomNumber.h"



RandomNumber::RandomNumber()
{

}


RandomNumber::~RandomNumber()
{
}

//Creat a random number
int RandomNumber::Create(int low, int high)
{
	
	std::uniform_int_distribution<int> uid{ low,high };

	return uid(mt_rand);
}


