#include "Player.h"



Player::Player()
{
	m_iStoneNum = 0;
	m_SP = NULL;
}

void Player::MapSizeSet(int Width, int Height)
{
	Release();
	m_iStoneNum = 0;
	m_iStoneMax = (Width * Height) >> 1;
	m_SP = new Stone_Pos*[m_iStoneMax];
	for (int i = 0; i < m_iStoneMax; i++)
		m_SP[i] = NULL;
}



void Player::Player_Name_Set(string name)
{
	m_strPlayerName = name;
}

void Player::Player_Stone_Shape_Set(string shape)
{
	m_strStoneShape = shape;

}

void Player::Player_Cursor_Shape_Set(string shape)
{
	m_strCursorShape = shape;
}

void Player::Player_Cursor_Pos_Set(int x, int y)
{
	m_iCursorPosX = x;
	m_iCursorPosY = y;
}

void Player::Stone_Place(int x, int y)
{
	if (m_SP[m_iStoneNum] != NULL)
	{
		cout << "할당 공간 인덱스 오류";
		system("pause");
	}
	m_SP[m_iStoneNum] = new Stone_Pos;
	m_SP[m_iStoneNum]->m_iStonePlacePosX = x;
	m_SP[m_iStoneNum]->m_iStonePlacePosY = y;
	Player_Stone_Shape_Set(m_strStoneShape);
	m_iStoneNum++;
}

bool Player::Player_Stone_Placed_Check(int x, int y)
{
	for (int i = 0; i < m_iStoneNum; i++)
	{
		if (m_SP[i]->m_iStonePlacePosX == x && m_SP[i]->m_iStonePlacePosY == y)
			return true;
	}
	return false;

		
}


void Player::Undo()
{
	if (m_iStoneNum - 1 == 0)
		return;

	m_iStoneNum--;
	delete m_SP[m_iStoneNum];
	m_SP[m_iStoneNum] = NULL;

}



void Player::Release()
{
	if (m_SP != NULL)
	{
	for (int i = 0; i < m_iStoneMax; i++)
	{
			if (m_SP[i] != NULL)
			{
				delete m_SP[i];
				m_SP[i] = NULL;
			}
		}
		delete[] m_SP;
	}
}

bool Player::Win_Check()
{
	if (m_iStoneNum < 5)
		return false;
	int Flag=0;

	for (int i = 0; i < m_iStoneNum; i++)
	{
		for (int j = 1; j < m_iStoneNum; j++)
		{
			if (m_SP[i]->m_iStonePlacePosY == m_SP[j]->m_iStonePlacePosY) // 가로 5개 확인
			{
				for (int z = 1; z < 5; z++)
				{
					if (m_SP[i]->m_iStonePlacePosX-(z*2) == m_SP[j]->m_iStonePlacePosX)
						Flag++;
					if (m_SP[i]->m_iStonePlacePosX + (z * 2) == m_SP[j]->m_iStonePlacePosX)
						Flag++;
				}
			}
		}
		if (Flag == 4)
			return true;
		else
			Flag = 0;

		for (int j = 1; j < m_iStoneNum; j++)
		{
			if (m_SP[i]->m_iStonePlacePosX == m_SP[j]->m_iStonePlacePosX) // 세로 5개 확인
			{
				for (int z = 1; z < 5; z++)
				{
					if (m_SP[i]->m_iStonePlacePosY - z == m_SP[j]->m_iStonePlacePosY)
						Flag++;
					if (m_SP[i]->m_iStonePlacePosY + z == m_SP[j]->m_iStonePlacePosY)
						Flag++;
				}
			}
		}
		if (Flag == 4)
			return true;
		else
			Flag = 0;

		for (int j = 1; j < m_iStoneNum; j++)
		{
				for (int z = 1; z < 5; z++)
				{
					if (m_SP[i]->m_iStonePlacePosX + (z * 2) == m_SP[j]->m_iStonePlacePosX && m_SP[i]->m_iStonePlacePosY-z == m_SP[j]->m_iStonePlacePosY)
						Flag++;

					if (m_SP[i]->m_iStonePlacePosX - (z * 2) == m_SP[j]->m_iStonePlacePosX && m_SP[i]->m_iStonePlacePosY + z == m_SP[j]->m_iStonePlacePosY)
						Flag++;
				}
			
		}
		if (Flag == 4)
			return true;
		else
			Flag = 0;

		for (int j = 1; j < m_iStoneNum; j++)
		{
			for (int z = 1; z < 5; z++)
			{
				if (m_SP[i]->m_iStonePlacePosX - (z * 2) == m_SP[j]->m_iStonePlacePosX && m_SP[i]->m_iStonePlacePosY - z == m_SP[j]->m_iStonePlacePosY)
					Flag++;

				if (m_SP[i]->m_iStonePlacePosX + (z * 2) == m_SP[j]->m_iStonePlacePosX && m_SP[i]->m_iStonePlacePosY + z == m_SP[j]->m_iStonePlacePosY)
					Flag++;
			}

		}
		if (Flag == 4)
			return true;
		else
			Flag = 0;

	}
	return false;
}



Player::~Player()
{
	Release();
}
