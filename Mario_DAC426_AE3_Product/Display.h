#pragma once

#include <Windows.h>
#include <conio.h>
#include <string>
#include "Coordinate.h"


class Display
{
public:
	Display();
	~Display();

	void		WriteChar(const Coordinate pos, char writeChar, WORD attribute);

	void		WriteMenssage(const Coordinate pos, std::string& writemessange);

private:

	HANDLE		m_input{ NULL };
	HANDLE		m_output{ NULL };
	SMALL_RECT	m_windowRect{ 0,0,0,0 };

	bool		setup();
	
};

