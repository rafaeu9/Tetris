#include "Shapes.h"




Shapes::Shapes(std::string Inp_Name, std::vector<std::vector<Coordinate>> Inp_Format, char Inp_Char, WORD Inp_Color)
	:Name{ Inp_Name }, m_Rotation{ Inp_Format }, m_Color{ Inp_Color }, m_Char{ Inp_Char }
{
	// ajust position spawn
	m_Coordinate.Add(4, 4);

	//rotation it spawns
	m_Format = m_Rotation[0];
	
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
		if (DetectLimit(m_Coordinate.X, (m_Coordinate.Y + m_MoveSpeed)))
			m_Coordinate.Y += m_MoveSpeed;
		else
			move = false;
		

		//display on the screen
		ScreenDisplay(' ', m_Color);
		while (_kbhit()) _getch();
		Y = m_Coordinate.Y;

		//move the piece until it colide with somthing to create the prediction shape
		while (DetectLimit(m_Coordinate.X, (m_Coordinate.Y + m_MoveSpeed))){
		m_Coordinate.Y += m_MoveSpeed;		
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

	//fix piece on the map
	ScreenDisplay(m_Char, m_Color);

}

bool Shapes::DetectLimit(int CheckPosX, int CheckPosY)
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
void Shapes::ScreenDisplay(char Inp_Char, WORD Inp_Colour)
{

	for (int i = 0; i < m_Format.size(); i++)
	{
		Coordinate pos((m_Format[i].X + m_Coordinate.X), (m_Format[i].Y + m_Coordinate.Y));
		
		m_Display.WriteChar(pos, Inp_Char, Inp_Colour);
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

//Get user input
void Shapes::UserInput()
{
	char key{ '0' };
	
	//Get Input
	key = _getch();

	switch (key)
	{
	case 'd':

		// Move left	
		if (DetectLimit(m_Coordinate.X + m_MoveSpeed, m_Coordinate.Y ))
		m_Coordinate.X += m_MoveSpeed;

		break;
	case 'a':

		// Move right
		if (DetectLimit(m_Coordinate.X - m_MoveSpeed, m_Coordinate.Y))
		m_Coordinate.X -= m_MoveSpeed;

		break;
	case 's':

		// Move down
		if (DetectLimit(m_Coordinate.X, (m_Coordinate.Y + m_MoveSpeed)))
		m_Coordinate.Y += m_MoveSpeed;

		break;
	
	case ' ':
		//try rotate
		int s_rotation{ m_ActualRotation };
		m_ActualRotation++;
		if (m_ActualRotation == m_MaxRotation)
			m_ActualRotation = 0;

		m_Format = m_Rotation[m_ActualRotation];
		
		//detect if is possible
		if (!DetectLimit(m_Coordinate.X, m_Coordinate.Y)) {
			m_ActualRotation = s_rotation;
			m_Format = m_Rotation[m_ActualRotation];
		}				
		break;
	}
}