#include "Block.h"



Block::Block()
{
 m_strWallShpae = "¢Ã";
 m_strTrapShape = "¢√";
m_strFoodShape = "°Ÿ";
 m_TrapPos = NULL;
 m_iTrapMAXCount = (WIDTH_DEFUALT * HEIGHT_DEFUALT) / 2;
 m_iFoodCount = 0; // ªË¡¶?
 m_iFoodClock = clock();
}

void Block::MapDraw(int Width, int Height)
{
	char buf[256];
	sprintf(buf, "mode con: cols=%d lines=%d", (Width * 2), Height + 10);
	system(buf);

	for (int y = 0; y <= Height; y++)
	{

		for (int x = 0; x < Width ; x++)
		{
			if (y == 0)
				MapDrawTool.DrawPoint(m_strTrapShape, x, y);
			else if (x == 0 || x == Width - 1)
				MapDrawTool.DrawPoint(m_strTrapShape, x, y);
			else if (y == Height)
				MapDrawTool.DrawPoint(m_strTrapShape, x, y);
		}
	}

}

void Block::TrapDraw(int Width, int Height)
{
	TrapRelease();
	m_iTrapCount = 0;
	m_TrapPos = new Trap_Pos *[m_iTrapMAXCount];
	for (int i = 0; i < m_iTrapMAXCount; i++)
	{
			m_TrapPos[i] = NULL;
	}



	for (int y = 1; y < Height; y++)
	{
		for (int x = 1; x < Width - 2; x++)
		{
			if ((rand() % TRAPDIFFICULT) == true)
			{
				m_TrapPos[m_iTrapCount] = new Trap_Pos;
				m_TrapPos[m_iTrapCount]->m_iTrapPosx = x;
				m_TrapPos[m_iTrapCount]->m_iTrapPosy = y;
				MapDrawTool.DrawPoint(m_strTrapShape, x, y);
				m_iTrapCount++;
			}
		}
	}
}

void Block::TrapRelease()
{
	if (m_TrapPos != NULL)
	{
		for (int i = 0; i < m_iTrapMAXCount; i++)
		{
			if (m_TrapPos[i] != NULL)
			{
				delete m_TrapPos[i];
				m_TrapPos[i] = NULL;
			}
			delete[] m_TrapPos;
		}
	}

}

bool Block::TrapCheak(int x, int y)
{
	for (int i = 0; i < m_iTrapCount; i++)
	{
		if (x == m_TrapPos[i]->m_iTrapPosx && y == m_TrapPos[i]->m_iTrapPosy)
			return false;
	}
	return true;

}

void Block::FoodCreate(int Width, int Height)
{
	m_iCurClock = clock();
	if (m_iFoodCount == 10)
		return;
	bool Flag = false;
	if (m_iCurClock - m_iFoodClock > 600)
	{
		while (Flag == false)
		{
			for (int y = 1; y < Height - 1; y++)
			{
				for (int x = 1; x < Width - 2; x++)
				{

					if ((rand() % FOODCREATEPROBABILIYH) == true && TrapCheak(x, y) == true)
					{
						Flag = true;
						m_FoodPos[m_iFoodCount] = new Food_Pos;
						m_FoodPos[m_iFoodCount]->m_iFoodPosx = x;
						m_FoodPos[m_iFoodCount]->m_iFoodPosy = y;
						m_iFoodCount++;
						MapDrawTool.DrawPoint(m_strFoodShape, x, y);
						m_iFoodClock = m_iCurClock;
						return;


					}
				}
			}
		}
	}

}

bool Block::FoodCheak(int x, int y)
{
	int tmp1;
	int tmp2;
	for (int i = 0; i < m_iFoodCount; i++)
	{
		if (m_FoodPos[i]->m_iFoodPosx == x && m_FoodPos[i]->m_iFoodPosy == y)
		{
			m_iFoodCount--;
			tmp1 =  m_FoodPos[m_iFoodCount]->m_iFoodPosx;
			tmp2 = m_FoodPos[m_iFoodCount]->m_iFoodPosy;
			m_FoodPos[i]->m_iFoodPosx = tmp1;
			m_FoodPos[i]->m_iFoodPosy = tmp2;
			delete m_FoodPos[m_iFoodCount];
			return true;
		}

	}
	return false;
}

void Block::FoodRelease()
{
		for (int i = 0; i < m_iFoodCount; i++)
		{
				delete m_FoodPos[i];
		}
		m_iFoodCount = 0;
}



Block::~Block()
{
	TrapRelease();
}
