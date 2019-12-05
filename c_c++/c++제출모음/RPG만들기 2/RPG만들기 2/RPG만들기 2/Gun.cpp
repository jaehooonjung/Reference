#include "Gun.h"



Gun::Gun()
{
}

int Gun::Weaponablity(int AttakMethod) 
{
	if (AttakMethod == ATTACKMETHOD_STRONGATTACK)
	{
		int Active = (rand() % 5);
		if (Active == SKILL_ACTIVE)
			return (m_iWeaponDemage * 2);
		else
			return m_iWeaponDemage;
	}
	return m_iWeaponDemage;
}

Gun::~Gun()
{
}
