#pragma once
#include"MapDraw.h"



class Character
{
protected:
	string m_strName;
	int m_iDemage;
	int m_iHp;
	int m_iMaxHp;
	int m_iGold;
	int m_iExp;
	MapDraw m_MapDrawManager;
public:
	void InfoSetUp(string Name, int Demage, int Hp, int MaxHp, int Gold, int Exp);
	virtual void InfoShow(int Width, int Height);
	virtual void DemagePhase(int Demage);
	virtual int Attack() = 0;
	virtual bool DeathCheck();
	Character();
	inline string NameOutput()
	{
		return m_strName;
	}
	int DemageOutput()
	{
		return m_iDemage;
	}
	inline int GoldOutput()
	{
		return m_iGold;
	}
	inline int ExpOutput()
	{
		return m_iExp;
	}
	inline int HpOutput()
	{
		return m_iHp;
	}
	inline int MaxHpOutput()
	{
		return m_iMaxHp;
	}
	
	~Character();
};

