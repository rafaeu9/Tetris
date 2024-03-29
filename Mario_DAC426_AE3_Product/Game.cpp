#include "Game.h"


using namespace std;

Game::Game()
{

	//Load_Map();
	
	m_Map.Load(Coordinate(0, 2), m_MapWidth, m_MapHeight);	
	
	LoadShapes();

	m_Score.Load();

			
}


Game::~Game()
{
}

void Game::PlayGame()
{
	
	 m_Map.Create();

	 //Map Keys Display
	 string m_Message;
	 m_Message = "Keys:";
	 m_Display.WriteMenssage(Coordinate(m_MapWidth + 2, 2), m_Message);
	 m_Message = "a: Left";
	 m_Display.WriteMenssage(Coordinate(m_MapWidth + 2, 3), m_Message);
	 m_Message = "d: Right";
	 m_Display.WriteMenssage(Coordinate(m_MapWidth + 2, 4), m_Message);
	 m_Message = "s: Down";
	 m_Display.WriteMenssage(Coordinate(m_MapWidth + 2, 5), m_Message);

	do {
	
		//update the score on the screen
		m_Score.SDisplay();

		//chose a random shape
		Shapes Actual_Shape = m_Shapes[m_RandNumb.Create(0,m_Shapes.size() - 1)];
	
		//make it move
		Actual_Shape.Move();		

		//detect if have filled lines
		DetectLine m_DetectLine(m_MapWidth, m_MapHeight);

		//update the amount of points
		m_Score.AddPoints(m_DetectLine.Check());	

		
	} while (GameOver());

	

}

void Game::Start()
{

	string m_Message;


	cout << "####### ####### ####### ######    ###    #####\n";
	cout << "   #    #          #    #     #    #    #     #\n";
	cout << "   #    #          #    #     #    #    #\n";
	cout << "   #    #####      #    ######     #     #####\n";
	cout << "   #    #          #    #   #      #          #\n";
	cout << "   #    #          #    #    #     #    #     #\n";
	cout << "   #    #######    #    #     #   ###    #####\n";
	cout << "\n Use a(<-) or d(->) to move and space to confirm\n";


	m_Message = "Top:";
	m_Display.WriteMenssage(Coordinate(50, 0), m_Message);

	for (int i = 0; i < m_Score.m_Top.size(); i++)
	{
		if (m_Score.m_Top[i].Score < 0)
			break;
		std::stringstream oss;
		oss << i+1 << ' ' << m_Score.m_Top[i].Name << ' ' << m_Score.m_Top[i].Score;


		m_Message = oss.str();
		m_Display.WriteMenssage(Coordinate(50, i+1), m_Message);
	}
	
	        
	int option{ 0 };
	char key;
	bool end = true;
	do
	{
		string m_Message;
			

		
		switch (option)
		{
		case 0:

			m_Message = "        Start(X)  Test Mode( )  Exit( )";
			m_Display.WriteMenssage(Coordinate(0, 10), m_Message);
			break;
		case 1:

			m_Message = "        Start( )  Test Mode(X)  Exit( )";
			m_Display.WriteMenssage(Coordinate(0, 10), m_Message);
			break;

		case 2:

			m_Message = "        Start( )  Test Mode( )  Exit(X)";
			m_Display.WriteMenssage(Coordinate(0, 10), m_Message);
			break;
		}
		
		while (_kbhit()) _getch();
		if (end)
			key = _getch();

		switch (key)
		{
		case 'a':

			if (option == 0)
				option = 2;
			else
				option--;

			break;
		case 'd':

			if (option == 2)
				option = 0;
			else
				option++;

			break;

		case ' ':

			end = false;

			break;
		}

	} while (end);

	m_Display.FillScreen(' ', WHITE_ON_BLACK);

	if (option == 0)
		PlayGame();
	else if (option == 1)
		TestMode("Testing.txt");

}

void Game::TestMode(const std::string& testlife)
{
	Tester tester;

	assert(tester.isReadyToTest());	

	//imput name
	string	Inp_Name;

	//input Color
	WORD	Inp_Color;

	//store the 
	Coordinate Inp_Coordinates;

	string Inp_Text;

	string text_from_file;

	ifstream	input;

	//open the file
	input.open(testlife);

	//detect if is correctli opened
	if (input.bad())
		cout << "ERROR OPEN " << testlife;
	else
	while (!input.eof()) {

		getline(input, text_from_file);

		m_Display.FillScreen(' ', WHITE_ON_BLACK);

		stringstream ss{ text_from_file };

		//extrect the name and the Color
		ss >> Inp_Name >> Inp_Coordinates.Y >> Inp_Coordinates.X >> Inp_Color >> Inp_Text;

		for (size_t i = 0; i < m_Shapes.size(); i++)
		{
			if (m_Shapes[i].Name == Inp_Name)
			{
				Shapes Actual_Shape = m_Shapes[i];
				Actual_Shape.m_Coordinate.CopyCoordinate(Inp_Coordinates);
				Actual_Shape.ScreenDisplay(Inp_Text[0], Inp_Color);
			}
		}
		
		if (Inp_Name == "TEXT")
			m_Display.WriteMenssage(Inp_Coordinates, Inp_Text, Inp_Color);

		int errors = tester.test(text_from_file);

		cout << "Errors: " << errors;
		
		_getch();
	}
	
	m_Display.FillScreen(' ', WHITE_ON_BLACK);

	Start();
}


void Game::LoadShapes()
{
	//store the 
	Coordinate Inp_Coordinates;
	
	//imput name
	string	Inp_Name;

	//input Color
	WORD	Inp_Color;

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
		ss >> Inp_Name >> Inp_Char >> Inp_Color;

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
		m_Shapes.push_back(Shapes(Inp_Name, rotation, Inp_Char, Inp_Color));
		
	 } 

	//close the file
	input.close();
}


bool Game::GameOver()
{
	

	Coordinate CheckPos;

	

	//detect if have any character close to the top wall
	for (int i = 1; i < m_MapWidth; i++)
	{		
		CheckPos.Copy(i, 3);

		//if have any, end the game
		if (m_Display.ReadChar(CheckPos) != ' ')
		{

			GameOverMenu();
			
			return false;
		}
	}
	return true;
}

void Game::GameOverMenu()
{

	bool save;

	string Inp_Name;

	m_Display.FillScreen(' ', WHITE_ON_BLACK);

	using namespace std;
	//Visual
	cout << " #####     #    #     # #######   ####### #     # ####### ######\n";
	cout << "#     #   # #   ##   ## #         #     # #     # #       #     #\n";
	cout << "#        #   #  # # # # #         #     # #     # #       #     #\n";
	cout << "#  #### #     # #  #  # #####     #     # #     # #####   ######\n";
	cout << "#     # ####### #     # #         #     #  #   #  #       #   #\n";
	cout << "#     # #     # #     # #         #     #   # #   #       #    #\n";
	cout << " #####  #     # #     # #######   #######    #    ####### #     #\n";
	cout << "\n       Use a(<-) or d(->) to move and space to confirm\n";
	cout << "\n             You want to save your score?\n";

	//User Input
	char key{ 'a' };
	bool end = true;
	do
	{
		string m_Message;

		switch (key)
		{
		case 'a':

			m_Message = "                      YES(X)  NO( )";
			m_Display.WriteMenssage(Coordinate(0, 11), m_Message);

			save = true;

			break;
		case 'd':

			m_Message = "                      YES( )  NO(X)";
			m_Display.WriteMenssage(Coordinate(0, 11), m_Message);

			save = false;

			break;

		case ' ':

			end = false;

			break;
		}


		while (_kbhit()) _getch();
		if (end)
			key = _getch();


	} while (end);

	//Get the name
	if (save)
	{
		m_Display.FillScreen(' ', WHITE_ON_BLACK);

		cout << "Name: ";

		cin >> Inp_Name;
		m_Score.Write(Inp_Name);
	}
}
