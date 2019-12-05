#pragma once
#include"Mecro.h"
#include"MapDrawManager.h"
#include"Block.h"
#include"Snake.h"

#define SNAKESPEEDDEFUALT 250
#define SNAKESPEEDUPMAX 200
#define SNAKESPEEDUPLEVEL 30

class Game
{
private:
	int m_iWidth;
	int m_iHeight;
	MapDrawManager m_MapDrawTool;
	Block m_BlockManager;
	Snake m_SnakeManager;
public:
	void MainMenu();
	void GameStart();
	Game();
	~Game();
};

