#include "Game.h"


using namespace std;

Game::Game()
{

	Load_Map();

	Load_Shapes();
			
}


Game::~Game()
{
}

void Game::Play_Game()
{

	do {
	
		m_Score.SDisplay();

		Shapes Actual_Shape = m_Shapes[Random_Shape(m_Shapes.size() - 1)];
	
		Actual_Shape.Move();
		
		m_save_shapes.push_back(Actual_Shape);

		DetectLine m_DetectLine(map_width, map_height);

		m_Score.Add_Points(m_DetectLine.check());	

		
	} while (GameOver());

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
		
	
	
	for (int i = 0; i < map_width; i++)
	{
		m_Display.WriteChar(Coordinate(i, 2) , (char)178, WHITE_ON_BLACK);
	}
	
	for (int i = 0; i < map_width; i++)
	{
		m_Display.WriteChar(Coordinate(i, map_height+2), (char)178, WHITE_ON_BLACK);
	}
	
	for (int i = 0; i < map_height; i++)
	{
		m_Display.WriteChar(Coordinate(0, i+2), (char)178, WHITE_ON_BLACK);
	}
	
	for (int i = 0; i < 1+map_height; i++)
	{
		m_Display.WriteChar(Coordinate(map_width, 2+i), (char)178, WHITE_ON_BLACK);
	}


}

void Game::Load_Shapes()
{
	int X{ 0 };
	int Y{ 0 };
	string	name;
	string	color;
	bool shape_end;
	std::vector<Coordinate> Shapechar;
	std::vector<std::vector<Coordinate>> rotation;
	Coordinate pos;
	string text_from_file;

	ifstream	input;

	input.open("Shapes.txt");
	if (input.bad())
		cout << "ERROR OPEN Shapes.txt";





	while (!input.eof()){
		
		shape_end = true;

		rotation.clear();

		getline(input, text_from_file);

		stringstream ss{ text_from_file };
		
		ss >> name >> color;

	

		while (shape_end)
		{
			while (!input.eof())
			{
				getline(input, text_from_file);

				if (text_from_file == "=")
					break;
				else if (text_from_file == "-") {
				shape_end = false;
				break;
				}
				stringstream ss{ text_from_file };

				ss >> X >> Y;

				Shapechar.push_back(Coordinate(X, Y));
			}
			rotation.push_back(Shapechar);
			Shapechar.clear();
		}

		
		m_Shapes.push_back(Shapes(name, rotation, WHITE_ON_WHITE));
		
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

bool Game::GameOver()
{
	Coordinate CheckPos;
	for (int i = 1; i < map_width; i++)
	{
		
		CheckPos.copy(i, 3);
		if (m_Display.ReadChar(CheckPos) != ' ')
			return false;		
	}
	return true;
}
