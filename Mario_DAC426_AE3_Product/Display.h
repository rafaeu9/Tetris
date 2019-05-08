#pragma once

#include <Windows.h>
#include <conio.h>
#include <string>

#include "Coordinate.h"
#include "ConsoleAttributes.h"


class Display
{
public:
	Display();
	~Display();

	// Display a character (Position in coordinate, Character, Color)
	void		WriteChar(Coordinate pos, char writeChar, WORD attribute = (WORD)WHITE_ON_WHITE);

	// Display a Menssage (Position in coordinate, Menssage)
	void		WriteMenssage(const Coordinate pos, std::string& writemessange, WORD attribute);
	void		WriteMenssage(const Coordinate pos, std::string& writemessange);

	//Get a character from the display
	char		ReadChar(Coordinate pos);

	//Get the Atribut from the display
	WORD		ReadAttribute(Coordinate pos);

	void		FillScreen(char fillChar, WORD attribute);

protected:

	HANDLE		m_input{ NULL };
	HANDLE		m_output{ NULL };
	SMALL_RECT	m_windowRect{ 0,0,0,0 };


	bool		setup();	
};

