#include "Character.h"



Character::Character()
{
}

void Character::InfoSetUp(string Name, int Demage, int Hp, int MaxHp, int Gold, int Exp)
{
	m_strName = Name;
	m_iDemage = Demage;
	m_iHp = Hp;
	m_iMaxHp = MaxHp;
	m_iGold = Gold;
	m_iExp = Exp;
}

void Character::InfoShow(int Width, int Height)
{
	m_MapDrawManager.DrawMidText("=====" + m_strName + "=====", Width, Height++);
	m_MapDrawManager.DrawMidText("공격력 = " + to_string(m_iDemage) + "\t생명력 = " + to_string(m_iHp) + "/" + to_string(m_iMaxHp), Width, Height++);
	m_MapDrawManager.DrawMidText("GOLD = " + to_string(m_iGold) + "EXP = "  + to_string(m_iExp), Width, Height++);
}

void Character::DemagePhase(int Demage)
{
	m_iHp -= Demage;
}

bool Character::DeathCheck()
{
	if (m_iHp <= 0)
	{
		m_iHp = m_iMaxHp;
		return true;
	}
	else
		return false;
}




Character::~Character()
{
}
