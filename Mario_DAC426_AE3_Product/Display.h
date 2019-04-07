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

	void		WriteChar(Coordinate pos, char writeChar, WORD attribute = (WORD)WHITE_ON_WHITE);

	void		WriteMenssage(const Coordinate pos, std::string& writemessange);

private:

	HANDLE		m_input{ NULL };
	HANDLE		m_output{ NULL };
	SMALL_RECT	m_windowRect{ 0,0,0,0 };

	bool		setup();
	
};

