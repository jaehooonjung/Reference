#include "Play.h"

Play::Play()
{
	srand((unsigned)time(NULL));
}

void Play::GamePlayMain()
{
	while (1)
	{
		InterfaceManager.GameMainDisplay();
		switch (InterfaceManager.MenuSelectCursor(3, HEIGHT*0.1f, WIDTH * 0.1f, HEIGHT*0.4f))
		{
			system("cls");
		case 1:
				Init();
				InterfaceManager.GameInitDisplay();
				InterfaceManager.StoryDisplay();
				m_strName = InterfaceManager.NameSet();
				while (m_bGameStatus != false)
				{
					GamePlay();
				}
				RankManager.RankInCheck(m_strName,m_iStage,m_iScore);
			break;
		case 2:
			RankManager.RankDisplay();
			break;
		case 3:
			return;
		}
	}

}

void Play::Init()
{
	m_iHp = 5;
	m_iStage = 1;
	m_iScore = 0;
	m_strName = "???";
	m_bGameStatus = true;
	WordBookManger.AllWordReset();
}

string Play::HpToHeart(int Hp)
{
	string strHp = {""};
	for (int i = 0; i < Hp; i++)
	{
		strHp += "♥";
	}
	return strHp;
}

void Play::GamePlay() 
{
	int YouInputWrongWordTime = clock();
	int CurTime;
	WordBookManger.TimeSet();
	int AnswerInputFlag = 0;
	WordBookManger.WordMaximumNumTune(m_iStage);
	string AnswerInput = { "" };
	string EraserLengthTmp = "qwertyuiopasdasfgzxc"; //문자열 길이 20
	bool StageClearFlag;
	WordBookManger.DifficultTune(m_iStage);
	InterfaceManager.GameInitDisplay();
	InterfaceManager.PlayStatus(HpToHeart(m_iHp), m_iScore, m_strName, m_iStage);
	InterfaceManager.DrawMidText("★ " + to_string(m_iStage) + " 스테이지 ★", WIDTH, HEIGHT*0.5f);
	getch();
	InterfaceManager.EraseLine(HEIGHT*0.5f);
	while (m_bGameStatus != false)
	{
		if (WordBookManger.AllCreatedWordCheck() == false)
		{
			m_iHp--;
			GameStatusUpdate();
		}

		WordBookManger.CurTimeSet();
		CurTime = clock();
		if (WordBookManger.CurTimeOutput() < YouInputWrongWordTime)
		{
			InterfaceManager.gotoxy(45, 27);
			cout << "패널티";
			InterfaceManager.EraseText(EraserLengthTmp, 40, 27);
		}
		else if (kbhit())
		{

			char ch;
			ch = getch();
			if (ch == ENTER)
			{
				int Index = WordBookManger.InputCheck(AnswerInput);
				if (Index != MAXIMUMWORDCREATE_LAST)
				{
					ScoreUp(AnswerInput.length());
					InterfaceManager.EraseText(EraserLengthTmp, 40, 27);
					AnswerInput = { "" };
					AnswerInputFlag = 0;
					WordBookManger.WordItemCheak(Index);
					StageClearFlag = GameStatusUpdate();
					WordBookManger.WordDelete(Index);
					if (StageClearFlag == true)
						return;
				}
				else
				{
					InterfaceManager.EraseText(EraserLengthTmp, 40, 27);
					AnswerInput = { "" };
					AnswerInputFlag = 0;
					YouInputWrongWordTime = CurTime +3000;
				}
			}
			if (ch == BACKSPACE && AnswerInputFlag >= 1)
			{
				InterfaceManager.EraseText(EraserLengthTmp, 40, 27);
				string tmp;
				for (int i = 0; i < AnswerInputFlag - 1; i++)
				{
					tmp += AnswerInput[i];
				}
				AnswerInput = { "" };
				AnswerInputFlag--;
				AnswerInput = tmp;
				InterfaceManager.gotoxy(45, 27);
				cout << AnswerInput;
			}
			if (ch >= 'a' && ch <= 'z' && AnswerInputFlag <= 13)
			{
				AnswerInput += ch;
				AnswerInputFlag++;
				InterfaceManager.gotoxy(45, 27);
				cout << AnswerInput;
			}
		}
			WordBookManger.WordDraw();
	
	}

	system("cls");
	InterfaceManager.gotoxy(50, 20);
	cout << "게임 종료";
	getch();
	WordBookManger.AllWordReset();
}

bool Play::GameStatusUpdate()
{
		InterfaceManager.EraseLine(HEIGHT - 3);
		InterfaceManager.EraseLine(HEIGHT - 2);
		InterfaceManager.PlayStatus(HpToHeart(m_iHp), m_iScore, m_strName, m_iStage);
	if (m_iScore >= (m_iStage * (m_iStage * 40)))
	{
		m_iStage++;
		WordBookManger.AllWordReset();
		return true;
	}
	if (m_iHp == 0 || m_iStage ==6)
	{
		m_bGameStatus = false;
		return false;
	}
}

void Play::ScoreUp(int StrLength)
{
	m_iScore += (m_iStage * StrLength);
}

Play::~Play()
{
}
