#pragma once
#include"Mecro.h"
#include"MapDrawManager.h"
struct SnakeBody 
{
	int SnakeBodyPosx;
	int SnakeBodyPosy;
	SnakeBody*Next;
};


class Snake
{
private:
	int m_iSnakeHeadPosx;
	int m_iSnakeHeadPosy;
	int m_iSnakeBodyCount;
	int	m_iCurClock;
	int m_iSnakeClock;
	char m_chSnakeDirection;
	string m_strSnakeHeadShape;
	string m_strSnakeBodyShape;	
	SnakeBody *m_SnakeBodyPos;
	SnakeBody *m_SnakeBodyPosTmp;
	SnakeBody *m_SnakeBodyPosAdd;

	MapDrawManager m_MapDrawTool;
public:
	bool SnakeMove(int Width, int Height);
	void SnakeHeadPosChange(int x, int y);
	void SnakeGrowUp();
	bool SnakeBodyPosInput(int Width, int Height);
	void SnakeBodyPosChange(SnakeBody*SB,int x,int y);
	void SnakeDraw();
	void SnakeErase();
	bool SnakeEatMyself(); 
	void Relase();
	void SnakeRelase(SnakeBody*Node);
	Snake();
	inline int SnakeHeadPosxOutput()
	{
		return m_iSnakeHeadPosx;

	}
	inline int SnakeHeadPosyOutput()
	{
		return m_iSnakeHeadPosy;

	}

	~Snake();
};

