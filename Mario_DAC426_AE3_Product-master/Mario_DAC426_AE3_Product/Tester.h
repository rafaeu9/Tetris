#pragma once
#include <string>
#include <sstream>

class Tester
{
public:
	Tester();
	~Tester();
	int		test(const std::stringstream& sstreamToTest);
	int		test(const std::string& stringToTest);
	bool	isReadyToTest() { return ready; }

protected:
	bool	ready{ false };
	const int INTERNAL_ERROR{ -1 };
};

