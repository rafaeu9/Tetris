#include "Game.h"


using namespace std;

Game::Game()
{
	
	Load_Map();
	
	Score.SDisplay();

	Load_Shapes();		
	
	
}


Game::~Game()
{
}

void Game::Play_Game()
{
	while (true) {
	


		Shapes Actual_Shape = m_Shapes[Random_Shape(m_Shapes.size() - 1)];
	
		Actual_Shape.Move();
		
		m_save_shapes.push_back(Actual_Shape);

	}

}

void Game::Load_Map()
{
	//Coordinate MapWalls;
	//
	//ifstream	input;
	//
	//input.open("Map.txt");
	//if (input.bad())
	//	cout << "ERROR OPEN Map.txt";
	//	
	//while (!input.eof()){
	//		
	//
	//		string text_from_file;
	//
	//		getline(input, text_from_file);
	//
	//		stringstream ss{ text_from_file };
	//
	//		ss >> MapWalls.X >> MapWalls.Y;
	//
	//		m_Map.push_back(Coordinate(MapWalls.X, MapWalls.Y+2));
	//
	//		
	//	}	
	//input.close();
	//   	
	//for (size_t i = 0; i < m_Map.size(); i++)
	//{
	//	display.WriteChar(m_Map[i], '#', WHITE_ON_BLACK);
	//
	//}
		
	
	
	for (size_t i = 0; i < map_width; i++)
	{
		display.WriteChar(Coordinate(i, 2) , (char)178, WHITE_ON_BLACK);
	}
	
	for (size_t i = 0; i < map_width; i++)
	{
		display.WriteChar(Coordinate(i, map_height+2), (char)178, WHITE_ON_BLACK);
	}
	
	for (size_t i = 0; i < map_height; i++)
	{
		display.WriteChar(Coordinate(0, i+2), (char)178, WHITE_ON_BLACK);
	}
	
	for (size_t i = 0; i < map_height +1; i++)
	{
		display.WriteChar(Coordinate(map_width, i+2), (char)178, WHITE_ON_BLACK);
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
		
		Shapechar.clear();

		getline(input, text_from_file);

		stringstream ss{ text_from_file };
		
		ss >> name >> color >> character;

	

		while (!input.eof()) 
		{
			getline(input, text_from_file);

			if (text_from_file == "-")
				break;

			stringstream ss{ text_from_file };

			ss >> X >> Y;

			Shapechar.push_back(Coordinate(X, Y));

			
		}

		
		m_Shapes.push_back(Shapes(name, Shapechar, WHITE_ON_WHITE, character));
		
	 } 


	input.close();
}

void Game::Choose_Shape()
{

}

int Game::Random_Shape(int high)
{
	std::random_device rd;
	std::mt19937 mt_rand{ rd() };
	std::uniform_int_distribution<int> uid{ 0,high };

	return uid(mt_rand);
}
