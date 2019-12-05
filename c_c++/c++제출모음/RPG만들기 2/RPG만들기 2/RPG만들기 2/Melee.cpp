#include "Melee.h"



Melee::Melee()
{
}

int Melee::Weaponablity(int AttakMethod)
{
	if (AttakMethod == ATTACKMETHOD_QUICKATTACK)
	{
	int Active = (rand() % 4);
		if (Active == SKILL_ACTIVE)
			return (m_iWeaponDemage * 2);
		else
			return m_iWeaponDemage;
	}
		return m_iWeaponDemage;
}
Melee::~Melee()
{
}
