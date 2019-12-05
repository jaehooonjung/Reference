#pragma once
#include"MapDraw.h"
#include "Character.h"
#include "Player.h"
#include "MonsterBook.h"
#include "WeaponShop.h"

enum FRISTATTACKER
{
	FRISTATTACKER_PLAYER = 1,
	FRISTATTACKER_MONSTER
};

class Game
{
private:
	int m_iWidth;
	int m_iHeight;
	bool m_bGameStatus;
	MapDraw m_MapDrawManager;
	Player m_PlayerManager;
	MonsterBook m_MonsterBookManager;
	WeaponShop m_WeaponShopManager;
public:
	void GameStartDisplay();
	void NewGameDisplay();
	void DungeonDisplay();
	void BattleDisplay(int i);
	void Battle(int i);
	void TMI(int Player, int Monster, string WinCheck);
	bool BattleCheck(int i);
	bool GameLoad();
	int FileCheck();
	void Save();

	Game();
	~Game();
};

