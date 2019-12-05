#include "Snake.h"



Snake::Snake()
{
	m_strSnakeHeadShape = "⊙";
	m_strSnakeBodyShape = "○";
	m_SnakeBodyPos = NULL;
	m_iSnakeBodyCount = 0;
	m_chSnakeDirection = NULL;
	m_iSnakeClock = clock();
}

bool Snake::SnakeMove( int Width, int Height)
{
	char tmp;
	if (m_chSnakeDirection == NULL)
		m_chSnakeDirection = getch();
	if (kbhit())
	{
		tmp = getch();
		if (m_chSnakeDirection != tmp)
			m_chSnakeDirection = tmp;
	}
	SnakeErase();
	int Lastx = m_iSnakeHeadPosx;
	int Lasty = m_iSnakeHeadPosy;

	switch (m_chSnakeDirection)
	{
	case KEY_LEFT:
		if (m_iSnakeHeadPosx - 1 != 0)
			SnakeHeadPosChange(m_iSnakeHeadPosx - 1, m_iSnakeHeadPosy);
		else
			return false;
		break;
	case KEY_RIGHT:
		if (m_iSnakeHeadPosx + 1 != Width - 2)
			SnakeHeadPosChange(m_iSnakeHeadPosx + 1, m_iSnakeHeadPosy);
		else
			return false;
		break;
	case KEY_UP:
		if (m_iSnakeHeadPosy - 1 != 0)
			SnakeHeadPosChange(m_iSnakeHeadPosx, m_iSnakeHeadPosy - 1);
		else
			return false;
		break;
	case KEY_DOWN:
		if (m_iSnakeHeadPosy + 1 != Height)
			SnakeHeadPosChange(m_iSnakeHeadPosx, m_iSnakeHeadPosy + 1);
		else
			return false;
		break;
	}
	SnakeBodyPosChange(m_SnakeBodyPos,Lastx,Lasty);
	return true;
}


void Snake::SnakeHeadPosChange(int x, int y)
{
	m_iSnakeHeadPosx = x;
	m_iSnakeHeadPosy = y;
}

void Snake::SnakeGrowUp()
{
	m_iSnakeBodyCount++;
	if (m_iSnakeBodyCount == 1)
	{
		m_SnakeBodyPos = new SnakeBody;
		m_SnakeBodyPos->Next = NULL;
	}
	else
	{
		m_SnakeBodyPosTmp = m_SnakeBodyPos;
		while (m_SnakeBodyPosTmp->Next != NULL)
			m_SnakeBodyPosTmp = m_SnakeBodyPosTmp->Next;
		m_SnakeBodyPosAdd = new SnakeBody;
		m_SnakeBodyPosAdd->Next = NULL;
		m_SnakeBodyPosTmp->Next = m_SnakeBodyPosAdd;
	}
}

bool Snake::SnakeBodyPosInput(int Width, int Height)
{
	m_iSnakeClock = clock();
	while (1)
	{
		m_iCurClock = clock();
		if (m_iCurClock - m_iSnakeClock > 400)
		{
			if (SnakeMove(Width, Height) == false)//이동 코드
				return false;
			else
				return true;
		}
	}
}

void Snake::SnakeBodyPosChange(SnakeBody*SB, int x, int y)
{
	if (SB == NULL)
		return;
	else
	{
		int Lastx = SB->SnakeBodyPosx;
		int Lasty = SB->SnakeBodyPosy;
		SB->SnakeBodyPosx = x;
		SB->SnakeBodyPosy = y;
		SnakeBodyPosChange(SB->Next,Lastx,Lasty);
	}
}


void Snake::SnakeDraw()
{
		m_MapDrawTool.DrawPoint(m_strSnakeHeadShape, m_iSnakeHeadPosx, m_iSnakeHeadPosy);
		if (m_iSnakeBodyCount == 0)
			return;
		m_SnakeBodyPosTmp = m_SnakeBodyPos;
		while (m_SnakeBodyPosTmp != NULL)
		{
			m_MapDrawTool.DrawPoint(m_strSnakeBodyShape, m_SnakeBodyPosTmp->SnakeBodyPosx, m_SnakeBodyPosTmp->SnakeBodyPosy);
			m_SnakeBodyPosTmp = m_SnakeBodyPosTmp->Next;
		}

}

void Snake::SnakeErase()
{
	m_MapDrawTool.ErasePoint(m_iSnakeHeadPosx, m_iSnakeHeadPosy);
	if (m_iSnakeBodyCount == 0)
		return;
	m_SnakeBodyPosTmp = m_SnakeBodyPos;
	while (m_SnakeBodyPosTmp != NULL)
	{
		m_MapDrawTool.ErasePoint(m_SnakeBodyPosTmp->SnakeBodyPosx, m_SnakeBodyPosTmp->SnakeBodyPosy);
		m_SnakeBodyPosTmp = m_SnakeBodyPosTmp->Next;
	}
}


bool Snake::SnakeEatMyself()
{
	m_SnakeBodyPosTmp = m_SnakeBodyPos;
	while (m_SnakeBodyPosTmp != NULL)
	{
		if (m_SnakeBodyPosTmp->SnakeBodyPosx == m_iSnakeHeadPosx && m_SnakeBodyPosTmp->SnakeBodyPosy == m_iSnakeHeadPosy)
			return true;
		m_SnakeBodyPosTmp = m_SnakeBodyPosTmp->Next;
	}
	return false;
}

void Snake::Relase()
{
	SnakeRelase(m_SnakeBodyPos);
//	SnakeRelase(m_SnakeBodyPosTmp);
//	SnakeRelase(m_SnakeBodyPosAdd);

}

void Snake::SnakeRelase(SnakeBody*Node)
{
	if (Node == NULL)
		return;
	SnakeRelase(Node->Next);
	delete Node;
}

Snake::~Snake()
{
}
