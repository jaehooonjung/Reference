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
	m_MapDrawManager.DrawMidText("�����̸� : " + m_strWeaponName + "  ����Ÿ�� : " + m_strWeaponType, Width, Height);
	m_MapDrawManager.DrawMidText("������ݷ� : " + to_string(m_iWeaponDemage) + "  ���Ⱑ�� : " + to_string(m_iWeaponPrice), Width, ++Height);

}



Weapon::~Weapon()
{
}
