#include "MonsterBook.h"



MonsterBook::MonsterBook()
{
	m_MonsterList = NULL;
}


void MonsterBook::FileLoading(string Filename,int Width, int Height)
{
	ofstream Save;
	ifstream Load;
	Load.open(Filename+".txt");
	if (!Load.is_open())
	{
		m_MapDrawManager.DrawMidText("몬스터 디폴트 파일이 없거나 손상되었습니다. 프로그램을 종료합니다.", Width, Height*0.5f);
		system("pause");
		exit(1);
	}
	else
	{
		if (m_MonsterList != NULL)
		{
			delete[] m_MonsterList;
		}
		Load >> m_iMonsterNum;
		m_MonsterList = new Monster[m_iMonsterNum];
		for (int i = 0; i < m_iMonsterNum; i++)
		{
			string Name;
			int Demage;
			int Hp;
			int MaxHp;
			int Gold;
			int Exp;
			Load >> Name;
			Load >> Demage;
			Load >> MaxHp;
			Hp = MaxHp;
			Load >> Gold;
			Load >> Exp;
			m_MonsterList[i].InfoSetUp(Name, Demage, Hp, MaxHp, Gold, Exp);
		}
	}
	Load.close();
}

void MonsterBook::MonsterShowAll(int Width)
{
	int ypos = 1;
		for (int i = 0; i < m_iMonsterNum; i++, ypos +=4)
		{
			m_MonsterList[i].InfoShow(Width, ypos);
		}
		getch();
}

void MonsterBook::MonsterShow(int Num, int Width, int Height)
{
	m_MonsterList[Num].InfoShow(Width, Height);
}

void MonsterBook::MonsterDemagePhase(int i, int Demage)
{
	m_MonsterList[i].DemagePhase(Demage);
}

bool MonsterBook::MonsterDeathCheck(int i)
{
	if (m_MonsterList[i].DeathCheck() == true)
		return true;
	else
		return false;
}

void MonsterBook::MonsterSave(int FileNum)
{
	ofstream Save;
	ifstream Load;
	Save.open("MonsterFile" + to_string(FileNum) + ".txt");
	if (Save.is_open())
	{
		Save << m_iMonsterNum;
		Save << "\n";
		for (int i = 0; i < m_iMonsterNum; i++)
		{
			Save << m_MonsterList[i].NameOutput();
			Save << " ";
			Save << m_MonsterList[i].DemageOutput();
			Save << " ";
			Save << m_MonsterList[i].MaxHpOutput();
			Save << " ";
			Save << m_MonsterList[i].GoldOutput();
			Save << " ";
			Save << m_MonsterList[i].ExpOutput();
			Save << "\n";
		}
	}
		Save.close();
}




MonsterBook::~MonsterBook()
{
		delete[] m_MonsterList;
}

