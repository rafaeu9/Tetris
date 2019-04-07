#include "Game.h"


using namespace std;

Game::Game()
{
	Load_Map();
}


Game::~Game()
{
}

void Game::Load_Map()
{
	

	int X;
	int Y;
	
	ifstream input;

	
	input.open("Map.txt");
	if (input.bad())
		cout << "ERROR OPEN Map.txt";
		
	while (!input.eof()){
			

			string text_from_file;

			getline(input, text_from_file);

			stringstream ss{ text_from_file };

			ss >> X >> Y;			

			Map.push_back(Coordinate(X,Y+2));

			
		}	
	input.close();
	   	
	for (size_t i = 0; i < Map.size(); i++)
	{
		display.WriteChar(Map[i], ' ', BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_BLUE);

	}
	

}

void Game::Load_Shapes()
{
	string	name;
	string	color;
	char	character;

	int X;
	int Y;

	ifstream input;


	input.open("Shapes.txt");
	if (input.bad())
		cout << "ERROR OPEN Shapes.txt";

		string text_from_file;

		getline(input, text_from_file);

		stringstream ss{ text_from_file };



	while (!input.eof()) {

		ss >> X >> Y;

		Map.push_back(Coordinate(X, Y + 2));
	}

	input.close();
}
