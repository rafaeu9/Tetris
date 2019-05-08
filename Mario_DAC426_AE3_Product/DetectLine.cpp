#include "DetectLine.h"



DetectLine::DetectLine(int inp_width, int inp_height)
{
	m_widt = inp_width ;
	m_height = inp_height + 1;
	m_MaxLineChar = m_widt - 1;
}


DetectLine::~DetectLine()
{
}

int DetectLine::check()
{
	   
	//Check all lines from bottom to top
	for (int i = m_height; i > 3; i--)
	{
		//check all characters from left to right 
		for (int o = 1; o < m_widt; o++)
		{
			//ajust actual position 
			m_CheckPos.copy(o, i);

			//count empty or filled spaces 
			if (m_Display.ReadChar(m_CheckPos) != ' ')
				m_LineChar++;
			else
				m_LineEmpChar++;
		}

		//check if the line is filled
		if (m_LineChar == m_MaxLineChar)
			m_FullLines.push(i);
		
		//reset characters count
		m_LineChar = 0;

		//check if line is empty
		if (m_LineEmpChar == m_MaxLineChar) 
			m_TopLine = i;			
		
		//reset empty spaces count
		m_LineEmpChar = 0;
	}
	
	//save the amount of filled lines
	m_Points = m_FullLines.size();

	//delete filled lines and move the the characters from top too bottom
	while (!m_FullLines.empty())
	{
		//delete the line
		for (int i = 1; i < m_widt; i++)
		{
			m_CheckPos.copy(i, m_FullLines.top());
			m_Display.WriteChar(m_CheckPos, ' ', WHITE_ON_BLACK);
		}

		//vove the characters on the top of the line
		for (int i = m_FullLines.top() - 1; i > m_TopLine + 1; i--)
		{
			//move evry character une position down
			for (int o = 1; o < m_widt; o++)
			{
				m_CheckPos.copy(o, i);
				char inp_Char = m_Display.ReadChar(m_CheckPos);
				if (inp_Char != ' ') {
					m_Display.WriteChar(Coordinate(m_CheckPos.X, m_CheckPos.Y + 1), inp_Char, m_Display.ReadAttribute(m_CheckPos));
					m_Display.WriteChar(m_CheckPos, ' ', WHITE_ON_BLACK);
				}
			}
		}


		m_FullLines.pop();
	}

	//return the amount of filled lines
	return  m_Points;
}
