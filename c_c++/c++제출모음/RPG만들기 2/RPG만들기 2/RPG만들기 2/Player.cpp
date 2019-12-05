#include "Player.h"



Player::Player()
{
	m_PlayerWeapon = NULL;
}

void Player::PlayerNameSet(int Width, int Height)
{
	system("cls");
	m_MapDrawManager.BoxDraw(0, 0, Width, Height);
	m_MapDrawManager.DrawMidText("Player 이름 입력 : ", Width, Height*0.5f);
	cin >> m_strName;
	
}

void Player::PlayerFileLoading(string Filename ,int Width, int Height)
{
	ofstream Save;
	ifstream Load;
	Load.open(Filename+".txt");
	if (!Load.is_open())
	{
		m_MapDrawManager.DrawMidText("플래이어 디폴트 파일이없거나 손상되었습니다. 프로그램을 종료합니다.", Width, Height*0.5f);
		system("pause");
		exit(1);
	}
	else
	{
		system("cls");
		m_MapDrawManager.BoxDraw(0, 0, Width, Height);
		Load >> m_strName;
		Load >> m_iLevel;
		Load >> m_iDemage;
		Load >> m_iHp;
		Load >> m_iMaxHp;
		Load >> m_iExp;
		Load >> m_iMaxExp;
		Load >> m_iGold;
		if (!Load.eof())
		{
			string WeaponType, WeaponName;
			int WeaponDemage, WeaponPirce;
			Load >> WeaponType;
			if (m_PlayerWeapon != NULL)
			{
				delete m_PlayerWeapon;
			}
				if (WeaponType == "melee")
					m_PlayerWeapon = new Melee;
				else if (WeaponType == "Gun")
					m_PlayerWeapon = new Gun;
				Load >> WeaponName;
				Load >> WeaponDemage;
				Load >> WeaponPirce;
				m_PlayerWeapon->WeaponInfoSetUp(WeaponType, WeaponName, WeaponDemage, WeaponPirce);
		}
		else
		{
			if (m_PlayerWeapon != NULL)
			{
				delete m_PlayerWeapon;
			}
		}
	}
	Load.close();
}


void Player::InfoShow(int Width, int Height)
{
	m_MapDrawManager.DrawMidText("=====" + m_strName + " (LV. " +to_string(m_iLevel)+ ") =====", Width, Height++);
	m_MapDrawManager.DrawMidText("공격력 = " + to_string(m_iDemage) + "\t생명력 = " + to_string(m_iHp) + "/" + to_string(m_iMaxHp), Width, Height++);
	m_MapDrawManager.DrawMidText("GOLD = " + to_string(m_iGold) + "EXP = " + to_string(m_iExp) + "/"  + to_string(m_iMaxExp), Width, Height++);
	if (m_PlayerWeapon != NULL)
		m_PlayerWeapon->WeaponInfoOutput(Width, Height++);
}

int Player::Attack()
{
	int AttackMethod ;
	while (1)
	{
		switch (AttackMethod = getch())
		{
		case ATTACKMETHOD_QUICKATTACK:
		case ATTACKMETHOD_STRONGATTACK:
		case ATTACKMETHOD_DEFENSE:
			return AttackMethod;
		}
	}
}

void Player::LevelUp()
{
	if (m_iExp < m_iMaxExp)
		return;
	else
	{
		while (m_iExp >= m_iMaxExp)
		{
			m_iExp -= m_iMaxExp;
			m_iLevel++;
			m_iDemage += m_iLevel * 2;
			m_iMaxHp += m_iLevel * 5;
			m_iMaxExp += m_iLevel * 5;
			m_iHp = m_iMaxHp;

		}
	}
}

void Player::BattleWin(int GetGold, int GetExp)
{
	m_iGold += GetGold;
	m_iExp += GetExp;
}

bool Player::WeaponGET(Weapon *WhatWeapon)
{
	if(m_iGold >= WhatWeapon->WeaponPriceOutput())
	{
		if (m_PlayerWeapon != NULL)
		{
			delete m_PlayerWeapon;
		}
		string WeaponType= WhatWeapon->WeaponTypeOutput(), WeaponName= WhatWeapon->WeaponNameOutput();
		int WeaponDemage = WhatWeapon->WeaponDemageOutput(), WeaponPirce = WhatWeapon->WeaponPriceOutput();
						if (WeaponType == "melee")
			m_PlayerWeapon = new Melee;
		else if (WeaponType == "Gun")
			m_PlayerWeapon = new Gun;
				m_PlayerWeapon->WeaponInfoSetUp(WeaponType, WeaponName, WeaponDemage, WeaponPirce);
		m_iGold -= WeaponPirce;
		return true;
	}
	return false;

}

int Player::BattleDemagePhase(int AttakMethod)
{
	if (m_PlayerWeapon != NULL)
	{
		return m_iDemage + m_PlayerWeapon->Weaponablity(AttakMethod);
	}
	else
		return m_iDemage;

}

void Player::PlayerSave(int FileNum)
{
	ofstream Save;
	ifstream Load;
	Save.open("PlayerFile" + to_string(FileNum) + ".txt");
	Load >> m_iHp;
	Load >> m_iMaxHp;
	Load >> m_iExp;
	Load >> m_iMaxExp;
	Load >> m_iGold;
	if (Save.is_open())
	{

		Save << m_strName;
		Save << " ";
		Save << m_iLevel;
		Save << " ";
		Save << m_iDemage;
		Save << " ";
		Save << m_iHp;
		Save << " ";
		Save << m_iMaxHp;
		Save << " ";
		Save << m_iExp;
		Save << " ";
		Save << m_iMaxExp;
		Save << " ";
		Save << m_iGold;
		if (m_PlayerWeapon != NULL)
		{
			Save << " ";
			Save << m_PlayerWeapon->WeaponTypeOutput();
			Save << " ";
			Save << m_PlayerWeapon->WeaponNameOutput();
			Save << " ";
			Save << m_PlayerWeapon->WeaponDemageOutput();
			Save << " ";
			Save << m_PlayerWeapon->WeaponPriceOutput();
		}
	}
			Save.close();
}

Player::~Player()
{
	if (m_PlayerWeapon != NULL)
	{
		delete m_PlayerWeapon;
		m_PlayerWeapon = NULL;
	}
}
