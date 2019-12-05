#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"Weapon.h"
#include "Gun.h"
#include "Melee.h"
#include"Player.h"


class WeaponShop
{
private:
	int m_iWeaponNum;
	MapDraw m_MapDrawManager;
	Weapon ** m_WeaponList;
public:
	void WeaponShopMain(int Width, int Height, int Gold, Player *Player1);
	int WeaponShopDisplay(int Width, int Height);
	string WeaponTypeSearch(int Width, int Height, int i);
	bool WeaponTypeList(int Width, int Height, string Type, int Gold, int index, Player *Player1);
	bool BackWeaponTypeList(int Width, int Height, string Type, int Gold, int index , Player *Player1);
	bool WeaponBuy(Weapon*ChoiceWeapon,Player *Player1);
	WeaponShop();
	~WeaponShop();
};

