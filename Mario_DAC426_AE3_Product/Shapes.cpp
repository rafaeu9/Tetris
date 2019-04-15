#include "Shapes.h"




Shapes::Shapes(std::string Inp_Name, std::vector<Coordinate> Inp_Format, WORD Inp_Color, char Inp_Character)
	:m_Name{ Inp_Name }, m_Format{ Inp_Format }, m_Color{ Inp_Color }, m_Character{ Inp_Character }, original_Format{ Inp_Format }
{
	m_Coordinate.Add(4, 4);

	for (int i = 0; i < m_Format.size(); i++)
	{
		if  (m_Format[i].X > Rot_Ajust_X)
		Rot_Ajust_X = m_Format[i].X;

		if (m_Format[i].Y > Rot_Ajust_Y)
			Rot_Ajust_Y = m_Format[i].Y ;
	}

	
}

Shapes::~Shapes()
{
}

void Shapes::Move()
{
	while (true)
	{
		// Detect user input
		if (_kbhit())
			UserInput();

		ScreenDisplay();		
		// Time the shape apear on the screen
		Sleep(500);	
		
		ScreenDelete();
		
		m_Coordinate.Y += Move_Speed;
	}	
}

void Shapes::ScreenDisplay()
{
	
	

	for (int i = 0; i < m_Format.size(); i++)
	{
		Coordinate pos((m_Format[i].X + m_Coordinate.X), (m_Format[i].Y + m_Coordinate.Y));
		
		m_Display.WriteChar(pos, m_Character, m_Color);
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
		m_Coordinate.X += Move_Speed;

		break;
	case 'a':

		// Move right
		m_Coordinate.X -= Move_Speed;

		break;
	case 's':

		// Move down
		m_Coordinate.Y += Move_Speed;

		break;

	case ' ':
				
		int rad{ 0 };

		rotation++;

		// Rotate
		switch (rotation)
		{
		
		
		case 1:

			
			for (int i = 0; i < m_Format.size(); i++)
			{
				m_Format[i].X = -original_Format[i].Y;
				m_Format[i].X += Rot_Ajust_Y;
				m_Format[i].Y = original_Format[i].X;
				
			}			

			break;
		case 2:			

			for (int i = 0; i < m_Format.size(); i++)
			{
				m_Format[i].X = -original_Format[i].X;
				m_Format[i].X += Rot_Ajust_X;
				m_Format[i].Y = -original_Format[i].Y;
				m_Format[i].Y += Rot_Ajust_Y;
			}
			
			break;
		case 3:

			for (int i = 0; i < m_Format.size(); i++)
			{
				m_Format[i].X = original_Format[i].Y;
				
				m_Format[i].Y = -original_Format[i].X;
				m_Format[i].Y += Rot_Ajust_X;
			}

			break;
		case 4:

			for (int i = 0; i < m_Format.size(); i++)
			{
				m_Format[i].X = original_Format[i].X;
				m_Format[i].Y = original_Format[i].Y;
			}
			rotation = 0;
			
			break;			
		}		
		break;
	}
}