#include "Game.h"



Game::Game()
{
	m_iWidth = WIDTH_DEFUALT;
	m_iHeight = HEIGHT_DEFUALT;
}

void Game::MainMenu()
{
	srand((unsigned)time(NULL));
	int Select;
	while (1)
	{
		m_BlockManager.MapDraw(m_iWidth, m_iHeight);
		m_MapDrawTool.DrawMidText("※ ※ ※ 뱀 게임 ※ ※ ※", m_iWidth, m_iHeight*0.2f);
		m_MapDrawTool.DrawMidText("1. 게임 시작", m_iWidth, m_iHeight*0.3f);
		m_MapDrawTool.DrawMidText("2. 게임 종료", m_iWidth, m_iHeight*0.4f);
		m_MapDrawTool.DrawMidText("선택 : ", m_iWidth, m_iHeight*0.5f);
		cin >> Select;
		switch (Select)
		{
		case 1:
			GameStart();
			getch();
			break;
		case 2:
			return;
		}
	}

}





void Game::GameStart()
{ 
	char tmp, ch = NULL;
	int speedup = 0;
	system("cls");
	m_BlockManager.MapDraw(m_iWidth, m_iHeight);
	m_BlockManager.TrapDraw(m_iWidth, m_iHeight);
	m_SnakeManager.SnakeHeadPosChange(m_iWidth / 2, m_iHeight / 2);

	while (1)
	{
		m_SnakeManager.SnakeDraw();
		m_BlockManager.FoodCreate(m_iWidth, m_iHeight);

		if (m_BlockManager.FoodCheak(m_SnakeManager.SnakeHeadPosxOutput(), m_SnakeManager.SnakeHeadPosyOutput()) == true)
		{
			m_SnakeManager.SnakeGrowUp();
		}
		if (m_SnakeManager.SnakeBodyPosInput(m_iWidth,m_iHeight) == false)
			break;
		if (m_BlockManager.TrapCheak(m_SnakeManager.SnakeHeadPosxOutput(), m_SnakeManager.SnakeHeadPosyOutput()) == false)
			break;
		if (m_SnakeManager.SnakeEatMyself() == true)
			break;
	}
	m_MapDrawTool.DrawMidText("GAMEOVER", m_iWidth, m_iHeight / 2);
	m_BlockManager.FoodRelease();
	m_SnakeManager.Relase();
	//m_BlockManager.TrapRelease();
	return;
}

Game::~Game()
{
}
