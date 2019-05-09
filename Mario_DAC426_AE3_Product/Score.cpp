#include "Score.h"



Score::Score()
{
}


Score::~Score()
{
}

void Score::SDisplay()
{
	std::stringstream oss;
	oss << "Score: " << m_Points;

	std::string m_Message{ oss.str() };

	m_Display.WriteMenssage(m_Coordinate, m_Message);
}

void Score::AddPoints(int inp_points)
{
	m_Points += inp_points;
}

int Score::GetPoints()
{
	return m_Points;
}

void Score::Load()
{
	using namespace std;

	string	Inp_Name;

	int Inp_Score;

	string text_from_file;

	ifstream	input;

	//open the file
	input.open("Score.txt");

	//detect if is correctli opened
	if (input.bad())
		cout << "ERROR OPEN Score.txt";
	else		
		//Read the score List
		for (int i = 0; i < TopSize; i++)
		{
			if (input.eof())
				break;

			getline(input, text_from_file);

			stringstream ss{ text_from_file };

			//extrect the name and the Color
			ss >> Inp_Name >> Inp_Score;

			Top.push_back(Save(Inp_Name, Inp_Score));

			
		}		
	

}

void Score::Write(std::string Inp_Name)
{
	
	

	for (int i = 0; i < TopSize; i++)
	{
		if (Top[i].Score <= m_Points)
		{
			//delete last score
			if (Top.size() == TopSize)
			Top.pop_back();
			
			//write the new score
			auto it = Top.emplace(Top.begin() + i, Save(Inp_Name, m_Points));
			break;
		}
	}

	using namespace std;
	
	ofstream	output;

	//open the file
	output.open("Score.txt", ofstream::trunc);

	//detect if is correctli opened
	if (output.bad())
		cout << "ERROR OPEN Score.txt";
	else
	{
		//write the score list
		for (int i = 0; i < Top.size(); i++)
		{
			if (Top[i].Score < 0)
				break;

			if(i == Top.size()-1)
				output << Top[i].Name << ' ' << Top[i].Score;
			else
				output << Top[i].Name << ' ' << Top[i].Score << endl;
		}	
			
	}
}


