#include "DetectLine.h"



DetectLine::DetectLine()
{

}


DetectLine::~DetectLine()
{
}

void DetectLine::config(int inp_width, int inp_height)
{
	m_widt = inp_width - 1;
	m_height = inp_height - 1;
}

int DetectLine::check()
{

	for (int i = m_height; i == 4; i--)
	{

		for (int o = 1; o == m_widt; o++) 
		{
			CheckPos.copy(o, i);

			if (m_Display.ReadChar(CheckPos) != ' ')
				LineChar++;
			else
				LineEmpChar++;		
		}

		if (LineChar == MaxLineChar)
			FullLines.push(i);
		LineChar = 0;

		if (LineEmpChar == MaxLineChar)
			TopLine = i;
		LineEmpChar = 0;
	}
		
	Points = FullLines.size();

	while (!FullLines.empty())
	{

		for (int i = 1; i < m_widt; i++)
		{
			CheckPos.copy(i, FullLines.top());
			m_Display.WriteChar(CheckPos, ' ', WHITE_ON_BLACK);
		}

		for (int i = FullLines.top() - 1; i == TopLine + 1; i--)
		{
			for (int o = 1; o == m_widt; o++)
			{
				CheckPos.copy(o, i);
				char inp_Char = m_Display.ReadChar(CheckPos);
				if (inp_Char != ' ') {
					m_Display.WriteChar(Coordinate(CheckPos.X, CheckPos.Y + 1), inp_Char, m_Display.ReadAttribute(CheckPos));
					m_Display.WriteChar(CheckPos, ' ', WHITE_ON_BLACK);
				}
			}
		}
		FullLines.pop();
	}

	return Points;
}
