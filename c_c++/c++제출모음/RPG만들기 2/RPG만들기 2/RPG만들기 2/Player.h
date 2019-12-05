#pragma once
#include"Character.h"
#include"Weapon.h"
#include"Melee.h"
#include"Gun.h"
class Player : public Character
{
private:
	int m_iLevel;
	int m_iMaxExp;
	Weapon *m_PlayerWeapon;
public:
	void PlayerNameSet(int Width, int Height);
	void PlayerFileLoading(string Filename,int Width, int Height);
	void InfoShow(int Width, int Height);
	void LevelUp();
	void BattleWin(int GetGold, int GetExp);
	int Attack();
	bool WeaponGET(Weapon*WhatWeapon);
	int BattleDemagePhase(int AttakMethod);
	void PlayerSave(int FileNum);
	Player();
	~Player();
};

