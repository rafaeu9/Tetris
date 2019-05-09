#pragma once
#include <string>
class Save
{
public:
	
	Save(std::string Inp_Name, int Inp_Score);
	~Save();

	std::string Name;
	int Score;
};

