#include "Display.h"



Display::Display()
{
	m_output = GetStdHandle(STD_OUTPUT_HANDLE);
	m_input = GetStdHandle(STD_INPUT_HANDLE);
	setup();
}


Display::~Display()
{
}


bool	Display::setup()
{
	// set the console mode - Windows 10 has new features that don't cooperate
	DWORD fdwMode = 0;
	GetConsoleMode(m_input, &fdwMode);

	// Enable window and mouse input events and 'ENABLE_EXTENDED_FLAGS' 
	// disable Quick Edit Mode and Insert Mode
	fdwMode |= ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS;
	fdwMode &= ~(ENABLE_QUICK_EDIT_MODE | ENABLE_INSERT_MODE);
	SetConsoleMode(m_input, fdwMode);
	GetConsoleMode(m_input, &fdwMode);

	// get the screen size
	CONSOLE_SCREEN_BUFFER_INFO info;
	if (!GetConsoleScreenBufferInfo(m_output, &info))
		return false;
	m_windowRect = info.srWindow;
	return true;
}

// Display any character
void	Display::WriteChar(Coordinate pos, char writeChar, WORD attribute )
{
	DWORD d;
	COORD wpos;
	wpos.X = pos.X;
	wpos.Y = pos.Y;

	WriteConsoleOutputAttribute(m_output, &attribute, 1, wpos, &d);
	WriteConsoleOutputCharacter(m_output, &writeChar, 1, wpos, &d);
}

// Display any menssage
void	Display::WriteMenssage(Coordinate pos, std::string& writemessange)
{
	DWORD d;
	COORD wpos;
	wpos.X = pos.X;
	wpos.Y = pos.Y;	
	WriteConsoleOutputCharacter(m_output, writemessange.c_str(), writemessange.length(), wpos, &d);
}

char Display::ReadChar(Coordinate pos)
{
	char kAnalized[1];

	_COORD CheckPos;

	CheckPos.X = pos.X;
	CheckPos.Y = pos.Y;

	// Number Of Characters Read
	DWORD NumberOfCharsRead = 0;
	ReadConsoleOutputCharacter(m_output, kAnalized, 1, CheckPos, &NumberOfCharsRead);	
	return kAnalized[0];
}

WORD Display::ReadAttribute(Coordinate pos)
{
	WORD AtAnalized;

	_COORD CheckPos;

	CheckPos.X = pos.X;
	CheckPos.Y = pos.Y;

	// Number Of Characters Read
	DWORD NumberOfCharsRead = 0;

	ReadConsoleOutputAttribute(m_output, &AtAnalized, 1, CheckPos, &NumberOfCharsRead);
	return AtAnalized;
}

/*
void	ConsoleWindow::fillScreen(char fillChar, WORD attribute)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(m_output, &info);

	DWORD dwBufferLen = info.dwSize.X * info.dwSize.Y;
	const COORD coordWriteStart = { 0, 0 };
	DWORD dwWritten;

	// set the colour attribute for all positions
	FillConsoleOutputAttribute(m_output, info.wAttributes, dwBufferLen, coordWriteStart, &dwWritten);
	// fill the character for all positions
	FillConsoleOutputCharacter(m_output, fillChar, dwBufferLen, coordWriteStart, &dwWritten);
	SetConsoleCursorPosition(m_output, coordWriteStart);
}
*/