#include "Shapes.h"




Shapes::Shapes(std::string Inp_Name, std::vector<std::vector<Coordinate>> Inp_Format, WORD Inp_Color)
	:m_Name{ Inp_Name }, m_rotation{ Inp_Format }, m_Color{ Inp_Color }
{
	m_Coordinate.Add(4, 4);

	m_Format = m_rotation[0];

	for (int i = 0; i < m_rotation[0].size(); i++)
	{
		m_Format[i] = m_rotation[0][i];
	}

}
		


Shapes::~Shapes()
{
}


void Shapes::Move()
{
	bool move = true;
	int Y = m_Coordinate.Y;
	while (move)
	{
		

		if (detect_limit(m_Coordinate.X, (m_Coordinate.Y + Move_Speed)))
			m_Coordinate.Y += Move_Speed;
		else
			move = false;


		// Detect user input
		if (_kbhit())
			UserInput();

		ScreenDisplay(' ', BACKGROUND_RED);
		Y = m_Coordinate.Y;
		while (detect_limit(m_Coordinate.X, (m_Coordinate.Y + Move_Speed))){
		m_Coordinate.Y += Move_Speed;

		
		}
		ScreenDisplay(' ', WHITE_ON_WHITE);
		
		// Time the shape apear on the screen
		Sleep(500);		
		
		ScreenDelete();
		m_Coordinate.Y = Y;
		ScreenDelete();
	}	

	ScreenDisplay('#', BACKGROUND_RED);

}

bool Shapes::detect_limit(int CheckPosX, int CheckPosY)
{

	_COORD CheckPos;

	

	char kAnalized[1];	

	// Number Of Characters Read
	DWORD NumberOfCharsRead = 0;

	for (int i = 0; i < m_Format.size(); i++)
	{
		Coordinate pos((m_Format[i].X + CheckPosX), m_Format[i].Y + CheckPosY);

		CheckPos.X = pos.X;
		CheckPos.Y = pos.Y;

		ReadConsoleOutputCharacter(ConsoleOutput, kAnalized, 1, CheckPos, &NumberOfCharsRead);

		if (kAnalized[0] != ' ')
			return false;
	}
		return true;
		
}

void Shapes::ScreenDisplay(char c, WORD co)
{

	for (int i = 0; i < m_Format.size(); i++)
	{
		Coordinate pos((m_Format[i].X + m_Coordinate.X), (m_Format[i].Y + m_Coordinate.Y));
		
		m_Display.WriteChar(pos, c, co);
	}
}

void Shapes::ScreenDelete()
{
	for (int i = 0; i < m_Format.size(); i++)
	{
		Coordinate pos((m_Format[i].X + m_Coordinate.X), (m_Format[i].Y + m_Coordinate.Y));
		m_Display.WriteChar(pos,' ', WHITE_ON_BLACK);
	}
}

void Shapes::UserInput()
{
	char key{ '0' };
	
	//Get Input
	key = _getch();

	switch (key)
	{
	case 'd':

		// Move left	
		if (detect_limit(m_Coordinate.X + Move_Speed, m_Coordinate.Y ))
		m_Coordinate.X += Move_Speed;

		break;
	case 'a':

		// Move right
		if (detect_limit(m_Coordinate.X - Move_Speed, m_Coordinate.Y))
		m_Coordinate.X -= Move_Speed;

		break;
	case 's':

		// Move down
		if (detect_limit(m_Coordinate.X, (m_Coordinate.Y + Move_Speed)))
		m_Coordinate.Y += Move_Speed;

		break;
	
	case ' ':

		rotation++;
		if (rotation == max_rotion)
			rotation = 0;

		m_Format = m_rotation[rotation];
				
		break;
	}
}