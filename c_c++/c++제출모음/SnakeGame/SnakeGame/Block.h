#pragma once
#include "Mecro.h"
#include"MapDrawManager.h"

#define FOODCOUNTMAX 10
#define FOODCREATEPROBABILIYH 850

struct Trap_Pos
{
	int m_iTrapPosx;
	int m_iTrapPosy;
};

struct Food_Pos
{
	int m_iFoodPosx;
	int m_iFoodPosy;
};

class Block
{
private:
	int m_iTrapMAXCount;
	int m_iTrapCount;
	int m_iFoodCount;
	int m_iFoodClock;
	int	m_iCurClock;
	string m_strWallShpae;
	string m_strTrapShape;
	string m_strFoodShape;
	Trap_Pos**m_TrapPos;
	Food_Pos*m_FoodPos[FOODCOUNTMAX];
	MapDrawManager MapDrawTool;

public:
	void MapDraw(int Width, int Height);
	void TrapDraw(int Width, int Height);
	void TrapRelease();
	bool TrapCheak(int x, int y);
	void FoodCreate(int Width, int Height);
	bool FoodCheak(int x, int y);
	void FoodRelease();
	Block();
	~Block();
};

