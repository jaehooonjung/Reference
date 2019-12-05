#pragma once
#include"Mecro.h"
struct Stone_Pos 
{
	int m_iStonePlacePosX;
	int m_iStonePlacePosY;
};


class Player
{
private:
	string m_strStoneShape;
	string m_strCursorShape;
	string m_strPlayerName;
	int m_iStoneNum;
	int m_iCursorPosX;
	int m_iCursorPosY;
	int m_iStoneMax;

	Stone_Pos**m_SP;

public:
	void Player_Name_Set(string name);
	void Player_Stone_Shape_Set(string shape);
	void Player_Cursor_Shape_Set(string shape);
	void Player_Cursor_Pos_Set(int x, int y);
	void Stone_Place(int x, int y);
	bool Player_Stone_Placed_Check(int x ,int y);
	void MapSizeSet(int Width, int Height);
	void Undo();
	void Release();
	bool Win_Check();
	
	inline string Player_Name_Output()
	{
		return m_strPlayerName;
	}

	inline void Player_Cursor_Output()
	{
		cout<< m_strCursorShape;
	}

	inline void Player_Stone_Output()
	{
		cout << m_strStoneShape;
	}

	inline int Player_Cursor_x_Output()
	{
		return m_iCursorPosX;
	}

	inline int Player_Cursor_y_Output()
	{
		return m_iCursorPosY;
	}
	inline int Stone_Num_Output()
	{
		return m_iStoneNum;
	}

	//언두 좌표 밖으로 빼주는 함수?
	inline int Last_Stone_Pos_X()
	{
		return m_SP[m_iStoneNum - 1]->m_iStonePlacePosX;
	}

	inline int Last_Stone_Pos_Y()
	{
		return m_SP[m_iStoneNum - 1]->m_iStonePlacePosY;
	}

	inline int Stone_Pos_X(int num)
	{
		return m_SP[num]->m_iStonePlacePosX;
	}
	inline int Stone_Pos_Y(int num)
	{
		return m_SP[num]->m_iStonePlacePosY;
	}


	Player();
	~Player();
};

