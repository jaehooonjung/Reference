#pragma once
#include "Weapon.h"

class Gun : public Weapon
{

public:
	int Weaponablity(int AttakMethod);
	Gun();
	~Gun();
};

