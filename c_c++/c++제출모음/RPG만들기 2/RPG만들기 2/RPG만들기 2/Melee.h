#pragma once
#include "Weapon.h"
class Melee : public Weapon
{
public:
	int Weaponablity(int AttakMethod);
	Melee();
	~Melee();
};

