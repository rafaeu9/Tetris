#include "Shapes.h"




Shapes::Shapes(std::string Inp_Name, std::vector<std::vector<Coordinate>> Inp_Format, WORD Inp_Color)
	:m_Name{ Inp_Name }, m_rotation{ Inp_Format }, m_Color{ Inp_Color }
{
	// ajust position spawn
	m_Coordinate.Add(4, 4);

	//rotation it spawns
	m_Format = m_rotation[0];
	
}
		


Shapes::~Shapes()
{
}


void Shapes::Move()
{
	bool move = true;
	int Y = m_Coordinate.Y;
	
	//move while it can
	while (move)
	{
		// Detect user input
		if (_kbhit())
			UserInput();


		//detect if can move
		if (detect_limit(m_Coordinate.X, (m_Coordinate.Y + Move_Speed)))
			m_Coordinate.Y += Move_Speed;
		else
			move = false;
		

		//display on the screen
		ScreenDisplay(' ', BACKGROUND_RED);
		while (_kbhit()) _getch();
		Y = m_Coordinate.Y;

		//move the piece until it colide with somthing to create the prediction shape
		while (detect_limit(m_Coordinate.X, (m_Coordinate.Y + Move_Speed))){
		m_Coordinate.Y += Move_Speed;		
		}
		ScreenDisplay(' ', WHITE_ON_WHITE);
		
		// Time the shape apear on the screen
		Sleep(500);		
		//delet pediction shape
		ScreenDelete();
		m_Coordinate.Y = Y;

		//delete the piece
		ScreenDelete();
	}	

	//fix pice on the map
	ScreenDisplay('#', BACKGROUND_RED);

}

bool Shapes::detect_limit(int CheckPosX, int CheckPosY)
{
	
	//Detect the coordinate of every parte of the piece to see if collides
	for (int i = 0; i < m_Format.size(); i++)
	{
		Coordinate pos((m_Format[i].X + CheckPosX), m_Format[i].Y + CheckPosY);
		

		if (m_Display.ReadChar(pos) != ' ')
			return false;
	}
	//return true whene don't colide
		return true;
		
}
// dispaly the shape on the screen
void Shapes::ScreenDisplay(char c, WORD co)
{

	for (int i = 0; i < m_Format.size(); i++)
	{
		Coordinate pos((m_Format[i].X + m_Coordinate.X), (m_Format[i].Y + m_Coordinate.Y));
		
		m_Display.WriteChar(pos, c, co);
	}
}
//delete shape on the screen
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
		//try rotate
		int s_rotation{ rotation };
		rotation++;
		if (rotation == max_rotion)
			rotation = 0;

		m_Format = m_rotation[rotation];
		
		//detect if is possible
		if (!detect_limit(m_Coordinate.X, m_Coordinate.Y)) {
			rotation = s_rotation;
			m_Format = m_rotation[rotation];
		}				
		break;
	}
}