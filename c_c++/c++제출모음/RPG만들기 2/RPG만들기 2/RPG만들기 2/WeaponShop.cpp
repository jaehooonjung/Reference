
#include "WeaponShop.h"



WeaponShop::WeaponShop()
{	
	m_WeaponList = NULL;
	ofstream Save;
	ifstream Load;
	Load.open("WeaponListDefalut.txt");
	if (!Load.is_open())
	{
		system("cls");
		m_MapDrawManager.DrawMidText("플래이어 디폴트 파일이 없거나 손상되었습니다. 프로그램을 종료합니다.", 30, 30 * 0.5f);
		system("pause");
		exit(1);
	}
	else
	{
		Load >> m_iWeaponNum;
		m_WeaponList = new Weapon*[m_iWeaponNum];
	
		for (int i = 0; i < m_iWeaponNum; i++)
		{
			Weapon*WeaponTmp;
			string WeaponType;
			string WeaponName;
			int WeaponDemage;
			int WeaponPrice;
		Load >> WeaponType;
			Load >> WeaponName;
			Load >> WeaponDemage;
			Load >> WeaponPrice;
			if (WeaponType == "melee")
				WeaponTmp = new Melee;
			else if(WeaponType == "Gun")
				WeaponTmp = new Gun;
			WeaponTmp->WeaponInfoSetUp(WeaponType, WeaponName, WeaponDemage, WeaponPrice);
			m_WeaponList[i] = WeaponTmp;
		}
	}
	Load.close();
}

void WeaponShop::WeaponShopMain(int Width, int Height, int Gold, Player *Player1)
{
	while (1)
	{
		int TypeFlag = WeaponShopDisplay(Width, Height) + 1;
		int ChoiceFlag = NULL;
		ChoiceFlag = m_MapDrawManager.MenuSelectCursor(TypeFlag, 2, (Width / 2) - 8, (Height * 0.2f) + 2);
		if (ChoiceFlag == TypeFlag)
			return;
		else
			WeaponTypeList(Width, Height, WeaponTypeSearch(Width, Height, ChoiceFlag), Gold, 0 , Player1);
		int i = 1;
	}
		
}

int WeaponShop::WeaponShopDisplay(int Width, int Height)
{
	int Heighttmp = Height * 0.2f;
	system("cls");
	m_MapDrawManager.BoxDraw(0, 0, Width, Height);
	m_MapDrawManager.DrawMidText("◆ ◇ 무기상점 ◇ ◆", Width, Heighttmp);
	string WeaponTypeTmp;
	int TypeFlag = 1;
	for (int  i = 0; i < m_iWeaponNum; i++)
	{
		if (i == 0)
		{
			WeaponTypeTmp = m_WeaponList[i]->WeaponTypeOutput();
			m_MapDrawManager.DrawMidText(WeaponTypeTmp, Width, Heighttmp += 2);
		}
		else if (WeaponTypeTmp != m_WeaponList[i]->WeaponTypeOutput())
		{
			WeaponTypeTmp = m_WeaponList[i]->WeaponTypeOutput();
			m_MapDrawManager.DrawMidText(WeaponTypeTmp, Width, Heighttmp += 2);
			TypeFlag++;
		}
	}
	m_MapDrawManager.DrawMidText("무기상점 나가기", Width, Heighttmp += 2);
	return TypeFlag;
}

string WeaponShop::WeaponTypeSearch(int Width, int Height, int i)
{
	string WhatType;
	if (i == 1)
		WhatType = m_WeaponList[0]->WeaponTypeOutput();
	else
	{
		for (int TypeFlag=0, j = 1; j < m_iWeaponNum; j++)
		{
			if (WhatType != m_WeaponList[j]->WeaponTypeOutput())
			{
				WhatType = m_WeaponList[j]->WeaponTypeOutput();
				TypeFlag++;
			}
			if (TypeFlag == i)
				break;
		}
	}
	return WhatType;
}

bool WeaponShop::WeaponTypeList(int Width, int Height, string Type, int Gold, int index,Player *Player1)
{
	//flase == 리스트 종료 , true == 리스트 동작
	while (1)
	{
		int Ypos = Height * 0.1f;
		int WeaponShowNum = 0;
		int select;
		int fristindexTmp = index;
		system("cls");
		m_MapDrawManager.BoxDraw(0, 0, Width, Height);
		m_MapDrawManager.DrawMidText(Type + " 타입 무기리스트", Width, Ypos);
		m_MapDrawManager.DrawMidText("소지금 : " + to_string(Gold), Width, ++Ypos);
		for (; index < m_iWeaponNum; index++)
		{
			if (WeaponShowNum == 4)
				break;
			if (m_WeaponList[index]->WeaponTypeOutput() == Type)
			{
				Ypos += 3;
				WeaponShowNum++;
				m_WeaponList[index]->WeaponInfoOutput(Width, Ypos);
			}
		}
		m_MapDrawManager.DrawMidText("다음 페이지", Width, Ypos += 3);
		m_MapDrawManager.DrawMidText("이전 페이지", Width, Ypos += 3);
		m_MapDrawManager.DrawMidText("돌아가기", Width, Ypos += 3);
		select = m_MapDrawManager.MenuSelectCursor(WeaponShowNum + 3, 3, 4, Height * 0.1f + 4);

		if (select <= WeaponShowNum)
		{
			//무기구매 관련

			bool WeaponBuyCheck;
			if (select == 1)
				WeaponBuyCheck = WeaponBuy(m_WeaponList[index - 4], Player1);
			else if (select == 2)
				WeaponBuyCheck = WeaponBuy(m_WeaponList[index - 3], Player1);
			else if (select == 3)
				WeaponBuyCheck = WeaponBuy(m_WeaponList[index - 2], Player1);
			else if (select == 4)
				WeaponBuyCheck = WeaponBuy(m_WeaponList[index - 1], Player1);
			if (WeaponBuyCheck == true)
				return false;
			else
				return true;
		}
		else if (select == WeaponShowNum + 1)
		{
			//다음 페이지
			if (WeaponShowNum == 4)
				if (WeaponTypeList(Width, Height, Type, Gold, index,Player1) == false)
					return false;
			index = fristindexTmp;
		}
		else if (select == WeaponShowNum + 2)
		{
			if (BackWeaponTypeList(Width, Height, Type, Gold, fristindexTmp - 1, Player1) == false)
				return false;
			index = fristindexTmp;
		}
		else if (select == WeaponShowNum + 3)
		{
			return false;
		}

	}
}

bool WeaponShop::BackWeaponTypeList(int Width, int Height, string Type, int Gold, int index, Player *Player1)
{
	int flag = 0;
	for (int i = index; i >= 0; i--)
	{
		if (m_WeaponList[i]->WeaponTypeOutput() == Type)
			flag++;
	}
	if (flag < 4)
		return true;

	while (1)
	{
		int Ypos = Height * 0.1f;
		int WeaponShowNum = 0;
		int select;
		int fristindexTmp = index;
		system("cls");
		m_MapDrawManager.BoxDraw(0, 0, Width, Height);
		m_MapDrawManager.DrawMidText(Type + " 타입 무기리스트", Width, Ypos);
		m_MapDrawManager.DrawMidText("소지금 : " + to_string(Gold), Width, ++Ypos);
		Ypos += 15;
		for (; index >= 0 ; index--)
		{
			if (WeaponShowNum == 4)
				break;
			if (m_WeaponList[index]->WeaponTypeOutput() == Type)
			{
				Ypos -= 3;
				WeaponShowNum++;
				m_WeaponList[index]->WeaponInfoOutput(Width, Ypos);
			}
		}
		m_MapDrawManager.DrawMidText("다음 페이지", Width, Ypos += 12);
		m_MapDrawManager.DrawMidText("이전 페이지", Width, Ypos += 3);
		m_MapDrawManager.DrawMidText("돌아가기", Width, Ypos += 3);
		select = m_MapDrawManager.MenuSelectCursor(WeaponShowNum + 3, 3, 4, Height * 0.1f + 4);
		if (select <= WeaponShowNum)
		{

			//무기구매 관련
			bool WeaponBuyCheck;
			if (select == 1)
				WeaponBuyCheck = WeaponBuy(m_WeaponList[index - 4], Player1);
			else if (select == 2)
				WeaponBuyCheck = WeaponBuy(m_WeaponList[index - 3], Player1);
			else if (select == 3)
				WeaponBuyCheck = WeaponBuy(m_WeaponList[index - 2], Player1);
			else if (select == 4)
				WeaponBuyCheck = WeaponBuy(m_WeaponList[index - 1], Player1);


			if (WeaponBuyCheck == true)
				return false;
			else
				return true;
		}
		else if (select == WeaponShowNum + 1)
		{
			//다음 페이지
			if (WeaponShowNum == 4)
				if (WeaponTypeList(Width, Height, Type, Gold, fristindexTmp+1, Player1) == false)
					return false;
			index = fristindexTmp;
		}
		else if (select == WeaponShowNum + 2)
		{
			//이전페이지
			if(index == -1)
				index++;
			if(BackWeaponTypeList(Width, Height, Type, Gold, index, Player1)== false)
			return false;
			index = fristindexTmp;
		}
		else if (select == WeaponShowNum + 3)
		{
			return false;
		}
	}
}

bool WeaponShop::WeaponBuy(Weapon*ChoiceWeapon, Player *Player1)
{
	return Player1->WeaponGET(ChoiceWeapon);
}


WeaponShop::~WeaponShop()
{
	if (m_WeaponList != NULL)
	{
		for (int i = 0; i < m_iWeaponNum; i++)
		{
			if (m_WeaponList[i] != NULL)
			{
				delete m_WeaponList[i];
				m_WeaponList[i] = NULL;
			}
		}
		delete[] m_WeaponList;
	}
}
