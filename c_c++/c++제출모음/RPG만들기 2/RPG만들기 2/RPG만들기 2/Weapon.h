#pragma once
#include"Mecro.h"
#include"MapDraw.h"

enum SKILLCHECK
{
	SKILL_FAIL,
	SKILL_ACTIVE
};


class Weapon
{
protected:
	MapDraw m_MapDrawManager;
	string m_strWeaponType;
	string m_strWeaponName;
	int m_iWeaponDemage;
	int m_iWeaponPrice;
public:
	void WeaponInfoSetUp(string WeaponType, string WeaponName, int WeaponDemage, int WeaponPrice);
	virtual void WeaponInfoOutput(int Width, int Height);
	virtual int Weaponablity(int AttakMethod) = 0; 
	Weapon();
	inline string WeaponTypeOutput()
	{
		return m_strWeaponType;
	}
	inline int WeaponPriceOutput()
	{
		return m_iWeaponPrice;
	}
	inline string WeaponNameOutput()
	{
		return m_strWeaponName;
	}
	inline int WeaponDemageOutput()
	{
		return m_iWeaponDemage;
	}


	~Weapon();
};


