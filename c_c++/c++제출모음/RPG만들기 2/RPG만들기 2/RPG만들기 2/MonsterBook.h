#pragma once
#include"Monster.h"
class MonsterBook
{
private:
	int m_iMonsterNum;
	Monster*m_MonsterList;
	MapDraw m_MapDrawManager;
public:
	void FileLoading(string Filename,int Width, int Height);
	void MonsterShowAll(int Width);
	void MonsterShow(int Num, int Width, int Height);
	void MonsterDemagePhase(int i, int Demage);
	bool MonsterDeathCheck(int i);
	void MonsterSave(int FileNum);
	MonsterBook();
	inline int MonsterNumOutput()
	{
		return m_iMonsterNum;
	}
	inline string MonsterNameOutput(int Index)
	{
		return 	m_MonsterList[Index].NameOutput();
	}
	inline int WhatMonsterAttack(int Num)
	{
		return m_MonsterList[Num].Attack();
	}
	inline int MonsterDemageOutput(int i)
	{
		return 	m_MonsterList[i].DemageOutput();
	}
	inline int MonsterGoldOutput(int i)
	{
		return m_MonsterList[i].GoldOutput();
	}
	inline int MonsterExpOutput(int i)
	{
		return m_MonsterList[i].ExpOutput();
	}

	~MonsterBook();
};

