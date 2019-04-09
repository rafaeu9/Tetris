#include "Game.h"


using namespace std;

Game::Game()
{
	Load_Map();
	Score.SDisplay();
	Load_Shapes();
	
	
	m_Shapes[0].Move();
}


Game::~Game()
{
}

void Game::Load_Map()
{
	Coordinate MapWalls;

	ifstream	input;

	input.open("Map.txt");
	if (input.bad())
		cout << "ERROR OPEN Map.txt";
		
	while (!input.eof()){
			

			string text_from_file;

			getline(input, text_from_file);

			stringstream ss{ text_from_file };

			ss >> MapWalls.X >> MapWalls.Y;

			m_Map.push_back(Coordinate(MapWalls.X, MapWalls.Y+2));

			
		}	
	input.close();
	   	
	for (size_t i = 0; i < m_Map.size(); i++)
	{
		display.WriteChar(m_Map[i], ' ', WHITE_ON_WHITE);

	}
	

}

void Game::Load_Shapes()
{
	int X{ 4 };
	int Y{ 5 };
	string	name;
	string	color;
	char	character;
	std::vector<Coordinate> Shapechar;
	int length;
	Coordinate pos;
	string text_from_file;

	ifstream	input;

	input.open("Shapes.txt");
	if (input.bad())
		cout << "ERROR OPEN Shapes.txt";





	while (!input.eof()){


		getline(input, text_from_file);

		stringstream ss{ text_from_file };
		
		ss >> name >> color >> character >> length;

	

		for (int i = 0; i < length; i++)
		{
			getline(input, text_from_file);

			stringstream ss{ text_from_file };

			ss >> X >> Y;

			Shapechar.push_back(Coordinate(X, Y));

			
		}

		
		m_Shapes.push_back(Shapes(name, Shapechar, color, character));
		
	 } 


	input.close();
}

void Game::Choose_Shape()
{

}
