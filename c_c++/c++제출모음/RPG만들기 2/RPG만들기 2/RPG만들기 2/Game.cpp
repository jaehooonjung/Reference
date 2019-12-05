#include "Game.h"



Game::Game()
{
	m_iWidth = 30;
	m_iHeight = 30;
	char buf[256];
	sprintf(buf, "mode con: cols=%d lines=%d", m_iWidth * 2, m_iHeight + 1);
	system(buf);
	srand((unsigned)time(NULL));
}

void Game::GameStartDisplay()
{
	while (1)
	{
		system("cls");
		m_MapDrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
		m_MapDrawManager.DrawMidText("★☆던전 RPG☆★", m_iWidth, m_iHeight*0.3f);
		m_MapDrawManager.DrawMidText("NEW GAME", m_iWidth, m_iHeight*0.5f);
		m_MapDrawManager.DrawMidText("LOAD GAME", m_iWidth, m_iHeight*0.6f);
		m_MapDrawManager.DrawMidText("GAME EXIT", m_iWidth, m_iHeight*0.7f);
		switch (m_MapDrawManager.MenuSelectCursor(3, m_iHeight*0.1f, (m_iWidth / 2) - 5, m_iHeight*0.5f))
		{
		case 1:
			m_PlayerManager.PlayerFileLoading("PlayerDefalut",m_iWidth, m_iHeight);
			m_PlayerManager.PlayerNameSet(m_iWidth, m_iHeight);
			m_MonsterBookManager.FileLoading("MonsterDefalut",m_iWidth, m_iHeight);
			NewGameDisplay();
			break;
		case 2:
		if(GameLoad() == true)
		NewGameDisplay();
			break;
		case 3:
			return;
		}

	}

}

void Game::NewGameDisplay()
{
	m_bGameStatus = true;
	while (m_bGameStatus == true)
	{
		system("cls");
		m_MapDrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
		m_MapDrawManager.DrawMidText("★☆MENU☆★", m_iWidth, m_iHeight*0.2f);
		m_MapDrawManager.DrawMidText("던전 입장", m_iWidth, m_iHeight*0.3f);
		m_MapDrawManager.DrawMidText("플레이어 정보", m_iWidth, m_iHeight*0.4f);
		m_MapDrawManager.DrawMidText("몬스터 도감", m_iWidth, m_iHeight*0.5f);
		m_MapDrawManager.DrawMidText("무기 상점", m_iWidth, m_iHeight*0.6f);
		m_MapDrawManager.DrawMidText("세이브", m_iWidth, m_iHeight*0.7f);
		m_MapDrawManager.DrawMidText("게임 종료", m_iWidth, m_iHeight*0.8f);
		switch (m_MapDrawManager.MenuSelectCursor(6, m_iHeight*0.1f, (m_iWidth / 2) - 5, m_iHeight*0.3f))
		{
		case 1:
			DungeonDisplay();
			break;
		case 2:
			system("cls");
			m_PlayerManager.InfoShow(m_iWidth, m_iHeight*0.5f);
			getch();
			break;
		case 3:
			system("cls");
			m_MapDrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
			m_MonsterBookManager.MonsterShowAll(m_iWidth);
			break;
		case 4:
			m_WeaponShopManager.WeaponShopMain(m_iWidth, m_iHeight, m_PlayerManager.GoldOutput(), &m_PlayerManager);
			break;
		case 5:
			Save();
			break;
		case 6:
			return;

		}

	}
}

void Game::DungeonDisplay()
{
	system("cls");
	m_MapDrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
	m_MapDrawManager.DrawMidText("※※던전 입구※※", m_iWidth, m_iHeight*0.1f);
	float ypos = 0.2;
	for (int i = 0; i < m_MonsterBookManager.MonsterNumOutput(); i++)
	{
		m_MapDrawManager.DrawMidText("지하 " + to_string(i+1) + "층 던전 : [" + m_MonsterBookManager.MonsterNameOutput(i) + "]", m_iWidth, m_iHeight*ypos);
		ypos += 0.1;
	}
	m_MapDrawManager.DrawMidText("돌아가기", m_iWidth, m_iHeight*ypos);
	BattleDisplay(m_MapDrawManager.MenuSelectCursor(m_MonsterBookManager.MonsterNumOutput()+1, m_iHeight*0.1f, (m_iWidth / 2) - 10, m_iHeight*0.2f)-1);
}

void Game::BattleDisplay(int i)
{
	if (i == m_MonsterBookManager.MonsterNumOutput())
		return;
	system("cls");
	m_MapDrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
	m_MapDrawManager.DrawMidText("1. 빠른공격  2. 강공격  3.가드", m_iWidth, (m_iHeight*0.3f + 1));
	m_MapDrawManager.DrawMidText("━━━━━━━━━━━━━━━━━━━━━━━━━", m_iWidth, m_iHeight*0.5f);
	m_MapDrawManager.DrawMidText("VS", m_iWidth, m_iHeight*0.5f);
	while (1)
	{
		m_MapDrawManager.EraseLine(m_iHeight*0.1f+1);
		m_MapDrawManager.EraseLine(m_iHeight*0.8f+1);
	m_PlayerManager.InfoShow(m_iWidth, m_iHeight*0.1f);
	m_MonsterBookManager.MonsterShow(i,m_iWidth, m_iHeight*0.8f);
	Battle(i);
	if (BattleCheck(i) == false)
		return;
	}
}

void Game::Battle(int i)
{
	string WinCheck;
	int PlayerAttackMethod = m_PlayerManager.Attack();
	int MonsterAttackMethod = m_MonsterBookManager.WhatMonsterAttack(i);
	if( (PlayerAttackMethod == ATTACKMETHOD_QUICKATTACK && MonsterAttackMethod == ATTACKMETHOD_STRONGATTACK)
		|| (PlayerAttackMethod == ATTACKMETHOD_STRONGATTACK && MonsterAttackMethod == ATTACKMETHOD_DEFENSE) )
	{
		m_MonsterBookManager.MonsterDemagePhase(i, m_PlayerManager.BattleDemagePhase(PlayerAttackMethod));
		WinCheck = "플레이어 공격성공";
	}
	else if ((MonsterAttackMethod == ATTACKMETHOD_QUICKATTACK && PlayerAttackMethod == ATTACKMETHOD_STRONGATTACK)
		|| (MonsterAttackMethod == ATTACKMETHOD_STRONGATTACK && PlayerAttackMethod == ATTACKMETHOD_DEFENSE))
	{
		m_PlayerManager.DemagePhase(m_MonsterBookManager.MonsterDemageOutput(i));
		WinCheck = "몬스터 공격성공";
	}
	else	
		WinCheck = "공격실패";
	TMI(PlayerAttackMethod, MonsterAttackMethod, WinCheck);
}

void Game::TMI(int Player, int Monster, string WinCheck)
{
	string TMIPlayer, TMIMonster, TMIWinCheck= WinCheck;
	if (Player == ATTACKMETHOD_QUICKATTACK)
		TMIPlayer = "플레이어 : 빠른공격";
	else if (Player == ATTACKMETHOD_STRONGATTACK)
		TMIPlayer = "플레이어 : 강공격";
	else if (Player == ATTACKMETHOD_DEFENSE)
		TMIPlayer = "플레이어 : 방어";

	if (Monster == ATTACKMETHOD_QUICKATTACK)
		TMIMonster = "몬스터 : 빠른공격";
	else if (Monster == ATTACKMETHOD_STRONGATTACK)
		TMIMonster = "몬스터 : 강공격";
	else if (Monster == ATTACKMETHOD_DEFENSE)
		TMIMonster = "몬스터 : 방어";

	m_MapDrawManager.EraseLine((m_iHeight*0.6f + 1));
	m_MapDrawManager.EraseLine((m_iHeight*0.6f + 2));
	m_MapDrawManager.DrawMidText(TMIPlayer +" " + TMIMonster, m_iWidth, (m_iHeight*0.6f+1));
	m_MapDrawManager.DrawMidText(TMIWinCheck, m_iWidth, (m_iHeight*0.6f + 2));

}

bool Game::BattleCheck(int i)
{
	if (m_PlayerManager.DeathCheck() == true) //플레이어 사망
	{
		m_bGameStatus = false;
		return false;
	}
	if (m_MonsterBookManager.MonsterDeathCheck(i) == true) // 플레이어 승리
	{
		m_PlayerManager.BattleWin(m_MonsterBookManager.MonsterGoldOutput(i), m_MonsterBookManager.MonsterExpOutput(i));;
		m_PlayerManager.LevelUp();
		return false;
	}

	return true;


}

bool Game::GameLoad()
{
	string FileNameTmp;
	int LoadFileName = FileCheck();
	if (LoadFileName == 6)
		return false; 
	FileNameTmp = { "MonsterFile" + to_string(LoadFileName)};
	m_MonsterBookManager.FileLoading(FileNameTmp, m_iWidth, m_iHeight);
	FileNameTmp = { "PlayerFile" + to_string(LoadFileName)};
	m_PlayerManager.PlayerFileLoading(FileNameTmp, m_iWidth, m_iHeight);
	system("cls");
	m_MapDrawManager.DrawMidText("로드완료", m_iWidth, m_iHeight*0.5f);
	getch();
	return true;
}

int Game::FileCheck()
{
	ofstream Save;
	ifstream Load;
	system("cls");
	m_MapDrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
	for (int i = 1; i <= 5; i++)
	{
		m_MapDrawManager.DrawMidText(to_string(i) + "번 슬롯 : 파일 여부 : ", m_iWidth, m_iHeight*0.1f*i);
		Load.open("PlayerFile" + to_string(i) + ".txt");
		if (Load.is_open())
		{
			Load.close();
			Load.open("MonsterFile" + to_string(i) + ".txt");
			if (Load.is_open())
				cout << "o";
			else
				cout << "x";
			Load.close();
		}
		else
			cout << "x";
	}
	m_MapDrawManager.DrawMidText("돌아가기", m_iWidth, m_iHeight*0.6f);
	return m_MapDrawManager.MenuSelectCursor(6, m_iHeight*0.1f, 7, m_iHeight*0.1f);


}

void Game::Save()
{
	int LoadFileName = FileCheck();
	string FileNameTmp;
	FileNameTmp = { "PlayerFile" + to_string(LoadFileName) + ".txt" };
	FileNameTmp = { "MonsterFile" + to_string(LoadFileName) + ".txt" };


	m_PlayerManager.PlayerSave(LoadFileName);
	m_MonsterBookManager.MonsterSave(LoadFileName);
}

Game::~Game()
{
}
