#include "Game.h"


using namespace std;

Game::Game()
{

	//Load_Map();
	m_Map.Load(Coordinate(0, 2), map_width, map_height);
	m_Map.Create();
	Load_Shapes();
			
}


Game::~Game()
{
}

void Game::Play_Game()
{

	do {
	
		//update the score on the screen
		m_Score.SDisplay();

		//chose a random shape
		Shapes Actual_Shape = m_Shapes[m_RandNumb.Create(0,m_Shapes.size() - 1)];
	
		//make it move
		Actual_Shape.Move();
		
		m_save_shapes.push_back(Actual_Shape);

		//detect if have filled lines
		DetectLine m_DetectLine(map_width, map_height);

		//update the amount of points
		m_Score.Add_Points(m_DetectLine.check());	

		
	} while (GameOver());

}


void Game::Load_Shapes()
{
	//store the 
	Coordinate Inp_Coordinates;
	
	//imput name
	string	Inp_Name;

	//input Color
	string	Inp_Color;

	char Inp_Char;

	//Detect if ended read the shape 
	bool shape_end;

	//save the shape of the piece
	std::vector<Coordinate> Shapechar;

	//save all the possible shapes of the piece
	std::vector<std::vector<Coordinate>> rotation;
	
	//save the text line
	string text_from_file;

	ifstream	input;

	//open the file
	input.open("Shapes.txt");

	//detect if is correctli opened
	if (input.bad())
		cout << "ERROR OPEN Shapes.txt";

	//read the file until the end
	while (!input.eof()){
		
		//reset the shape end detector
		shape_end = true;

		//reset the shapes holder
		rotation.clear();

		//get the text line from the text file
		getline(input, text_from_file);

		//convert it to stringstream
		stringstream ss{ text_from_file };
		
		//extrect the name and the Color
		ss >> Inp_Name >> Inp_Char, Inp_Color;

		//extrect the coordinats of every block of the posible shapes 
		while (shape_end)
		{
			while (!input.eof())
			{
				//get the line
				getline(input, text_from_file);

				//if the an = prepare to get another shape
				if (text_from_file == "=")
					break;
				//if is an - prepare to the next piece 
				else if (text_from_file == "-") {
				shape_end = false;
				break;
				}

				//convert it to stringstream
				stringstream ss{ text_from_file };

				//extrect the X and Y coordinate of the block
				ss >> Inp_Coordinates.X >> Inp_Coordinates.Y;

				//save them
				Shapechar.push_back(Inp_Coordinates);
			}

			//save the possible shapes
			rotation.push_back(Shapechar);

			//reset the shape holder
			Shapechar.clear();
		}

		//creat the piece with the saved information
		m_Shapes.push_back(Shapes(Inp_Name, rotation, Inp_Char, BACKGROUND_RED));
		
	 } 

	//close the file
	input.close();
}


bool Game::GameOver()
{
	
	Coordinate CheckPos;

	//detect if have any character close to the top wall
	for (int i = 1; i < map_width; i++)
	{		
		CheckPos.copy(i, 3);

		//if have any, end the game
		if (m_Display.ReadChar(CheckPos) != ' ')
			return false;		
	}
	return true;
}
