#include "Game.h"


using namespace std;

Game::Game()
{
	Load_Map();
	Score.SDisplay();
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

			Map.push_back(Coordinate(MapWalls.X, MapWalls.Y+2));

			
		}	
	input.close();
	   	
	for (size_t i = 0; i < Map.size(); i++)
	{
		display.WriteChar(Map[i], ' ', WHITE_ON_WHITE);

	}
	

}

void Game::Load_Shapes()
{
	string	name;
	WORD	color;
	char	character;
	std::vector<Coordinate> Shapechar;
	int length;
	Coordinate pos;

	ifstream	input;

	input.open("Shapes.txt");
	if (input.bad())
		cout << "ERROR OPEN Shapes.txt";

		string text_from_file;

		getline(input, text_from_file);

		stringstream ss{ text_from_file };



	while (!input.eof()) {

		

		ss >> name >> color >> character >> length;

		for (size_t i = 0; i < length; i++)
		{
			ss >> pos.X >> pos.Y;
			
			Shapechar.push_back(pos);			
		}
		

		
	}

	input.close();
}

void Game::ChooseShape()
{

}
