#include "Weapon.h"



Weapon::Weapon()
{
}

void Weapon::WeaponInfoSetUp(string WeaponType, string WeaponName, int WeaponDemage, int WeaponPrice)
{
m_strWeaponType= WeaponType;
m_strWeaponName= WeaponName;
m_iWeaponDemage= WeaponDemage;
m_iWeaponPrice= WeaponPrice;
}

void Weapon::WeaponInfoOutput(int Width, int Height)
{
	m_MapDrawManager.DrawMidText("무기이름 : " + m_strWeaponName + "  무기타입 : " + m_strWeaponType, Width, Height);
	m_MapDrawManager.DrawMidText("무기공격력 : " + to_string(m_iWeaponDemage) + "  무기가격 : " + to_string(m_iWeaponPrice), Width, ++Height);

}



Weapon::~Weapon()
{
}
