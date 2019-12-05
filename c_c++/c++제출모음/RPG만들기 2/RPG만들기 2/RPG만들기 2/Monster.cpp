#include "Monster.h"



Monster::Monster()
{
}

int Monster::Attack()
{
	int AttackMethod;
	AttackMethod = (rand() % 3) + 49;
	return AttackMethod;
}




Monster::~Monster()
{
}
