#include "Rank.h"

Rank::Rank()
{
	ifstream Load;
	Load.open("Rank.txt");
	if (!Load.is_open())
	{
		system("cls");
		InterfaceManager.DrawMidText("�÷��̾� ����Ʈ ������ ���ų� �ջ�Ǿ����ϴ�. ���α׷��� �����մϴ�.", 30, 30 * 0.5f);
		system("pause");
		exit(1);
	}
	else
	{
		m_iRankNum = 0;
		while (!Load.eof())
		{
			Load >> m_RankBook[m_iRankNum].m_strPlayerName;
			Load >> m_RankBook[m_iRankNum].m_iStage;
			Load >> m_RankBook[m_iRankNum].m_iScore;
			m_iRankNum++;
		}
	}
	Load.close();
}

void Rank::RankDisplay()
{
	RankArray();
	system("cls");
	InterfaceManager.BoxDraw(0, 0, WIDTH, HEIGHT-1);
	InterfaceManager.BoxDraw2(35, 5, 50, 10);
	InterfaceManager.gotoxy(40, 7);
	cout << "�� R A N K ��";
	InterfaceManager.gotoxy(2, 14);
	cout << "================================================================================================";
	InterfaceManager.gotoxy(30, 16);
	cout << "����" << "\t�̸�\t��������\t���ھ�";
	int RankYpos = 18;
	for (int i = 0; i < m_iRankNum; i++ , RankYpos+=2)
	{
		InterfaceManager.gotoxy(30, RankYpos);
		cout << i + 1 << "\t\t" << m_RankBook[i].m_strPlayerName << "\t" << m_RankBook[i].m_iStage << "\t\t" << m_RankBook[i].m_iScore;
	}
	getch();
	system("cls");
}

void Rank::RankArray()
{
	RANKBOOK Tmp;
	for (int i = 0; i <= m_iRankNum-1; i++)
	{
		for (int j = i; j <= m_iRankNum; j++)
		{
			if (m_RankBook[i].m_iScore < m_RankBook[j].m_iScore)
			{
				Tmp = m_RankBook[i];
				m_RankBook[i] = m_RankBook[j];
				m_RankBook[j] = Tmp;
			}
		}
	}
}

void Rank::RankInCheck(string Name, int Stage, int Score)
{
	ofstream Save;

	if (m_iRankNum < 9)
	{
			m_RankBook[m_iRankNum+1].m_strPlayerName = Name;
			m_RankBook[m_iRankNum+1].m_iStage = Stage;
			m_RankBook[m_iRankNum+1].m_iScore = Score;
			m_iRankNum++;
	}
	else
	{
		if (m_RankBook[9].m_iScore < Score)
		{
			m_RankBook[9].m_strPlayerName = Name;
			m_RankBook[9].m_iStage = Stage;
			m_RankBook[9].m_iScore = Score;
		}
	}
	RankArray();
	Save.open("Rank.txt");
	if (!Save.is_open())
	{
		system("cls");
		InterfaceManager.DrawMidText("�÷��̾� ����Ʈ ������ ���ų� �ջ�Ǿ����ϴ�. ���α׷��� �����մϴ�.", 30, 30 * 0.5f);
		system("pause");
		exit(1);
	}
	else
	{
		for (int i = 0; i < m_iRankNum; i++)
		{
			Save << m_RankBook[i].m_strPlayerName << " " << m_RankBook[i].m_iStage << " " << m_RankBook[i].m_iScore;
			if (i != m_iRankNum - 1)
				Save << endl;
		}
	}
	Save.close();
}


Rank::~Rank()
{
}
