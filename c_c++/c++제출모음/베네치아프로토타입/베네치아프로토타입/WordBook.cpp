#include "WordBook.h"



WordBook::WordBook()
{
	m_WordBook = NULL;
	ifstream Load;
	Load.open("Word.txt");
	if (!Load.is_open())
	{
		system("cls");
		m_InterfaceManager.DrawMidText("플래이어 디폴트 파일이 없거나 손상되었습니다. 프로그램을 종료합니다.", 30, 30 * 0.5f);
		system("pause");
		exit(1);
	}
	else
	{
		Load >> m_iWordNum;
		m_WordBook = new Word*[m_iWordNum];


		for (int i = 0; i < m_iWordNum; i++)
		{
			Word*Tmp;
			string WordTmp;
			Load >> WordTmp;
			Tmp = new Word;
			Tmp->WordRegister(WordTmp);
			m_WordBook[i] = Tmp;
		}
		Load.close();
	}
	for (int i = 0; i < MAXIMUMWORDCREATE_LAST; i++)
	{
		m_iCreatedWordNum[i] = NULL;
	}
}

void WordBook::RandomWordOutout(int CreatedWordNumflag)
{
	int CreatedWordFlag=0;
	for (int i = 0; i < MAXIMUMWORDCREATE_LAST; i++)
	{
		if (m_iCreatedWordNum[i] != NULL)
			CreatedWordFlag++;
	}
	if (CreatedWordFlag == CreatedWordNumflag)
		return;

	int RandomNum;
	int ItemMakeFlag;
	Item*ItemTmp = NULL;

	while(1) //중복된 단어가 나오지 않게 막아주는 반복문
	{
		bool Flag = true;
		RandomNum = (rand() % m_iWordNum);
		for (int i = 0; i < MAXIMUMWORDCREATE_LAST; i++)
		{
			if (RandomNum == m_iCreatedWordNum[i])
			{
				Flag = false;
				break;
			}
		}
		if (Flag == false)
			continue;
		else
			break;
	}
	
	m_WordBook[RandomNum]->WordXposRandomSetupAndYposReset();
	ItemMakeFlag = (rand() % 50);
	switch (ItemMakeFlag)
	{

	case 1:
		ItemTmp = new ItemDisplayClear;
		break;
	case 2:
		ItemTmp = new ItemSpeedDown;
		break;
	case 3:
		ItemTmp = new ItemSpeedUp;
		break;
	case 4:
		ItemTmp = new ItemWordBlackOut;
		break;
	case 5:
		ItemTmp = new ItemWordStop;
		break;

	
	}
	if (ItemTmp != NULL)
	{
		m_WordBook[RandomNum]->WordItemSet(ItemTmp);
	}
	if(m_WordBook[RandomNum]->ItemCheck() == true)
		BLUE
		if(m_bBlindFlag == true)
		BLACK
		m_WordBook[RandomNum]->WordDraw();
		ORIGINAL
	for (int i = 0; i < CreatedWordNumflag; i++)
	{
		if (m_iCreatedWordNum[i] == NULL)
		{
			m_iCreatedWordNum[i] = RandomNum;
			break;
		}
	}
}

void WordBook::AllCreatedWordDown()
{
	for (int i = 0; i < MAXIMUMWORDCREATE_LAST; i++)
	{
		if (m_iCreatedWordNum[i] == NULL)
			continue;
		m_InterfaceManager.EraseText(WordHideBoxCheck(m_WordBook[m_iCreatedWordNum[i]]), m_WordBook[m_iCreatedWordNum[i]]->XposOutput(), m_WordBook[m_iCreatedWordNum[i]]->YposOutput());
		m_WordBook[m_iCreatedWordNum[i]]->WordYposDown();
		if (m_WordBook[m_iCreatedWordNum[i]]->ItemCheck() == true)
			BLUE
			if (m_bBlindFlag == true)
				BLACK
			m_WordBook[m_iCreatedWordNum[i]]->WordDraw();
		ORIGINAL
	}
}

bool WordBook::AllCreatedWordCheck()  //생성된 단어의 생존여부 체크
{
	for (int i = 0; i < MAXIMUMWORDCREATE_LAST; i++)
	{
		if (m_iCreatedWordNum[i] == NULL)
			continue;

		if ((m_WordBook[m_iCreatedWordNum[i]]->YposOutput()) == (HEIGHT - 7))
		{
			m_InterfaceManager.EraseLine(m_WordBook[m_iCreatedWordNum[i]]->YposOutput());
			m_iCreatedWordNum[i] = NULL;
			return false;
		}
	}
	return true;
}

string WordBook::WordHideBoxCheck(Word*WordTmp)
{
	string Answer = {""};
	int CheckFlag;
	if (WordTmp->YposOutput() >= 25 && WordTmp->YposOutput() <= 30)
	{
		CheckFlag = ((WordTmp->XposOutput()) + WordTmp->WordOutput().length());
		if (WordTmp->XposOutput() < (35) &&  (CheckFlag <= 65 && CheckFlag >= 35)) //50
		{
			for (int i = 0; i < (CheckFlag - 35-4); i++)
			{
				Answer += WordTmp->WordOutput()[i];
			}
		}
		else if (WordTmp->XposOutput() <= 65 && CheckFlag >= 65) // 50 05
		{
			for (int i = (65 - WordTmp->XposOutput())+4 ; i < (CheckFlag - 65); i++)
			{
				Answer += WordTmp->WordOutput()[i];
			}
		}
		else if(((WordTmp->XposOutput() >= 35 && WordTmp->XposOutput() <= 65)) && (CheckFlag <= 65) )
		{
			return Answer;
		}
		else
		{
			return WordTmp->WordOutput();
		}
		return Answer;
	}
	else
	{
		return WordTmp->WordOutput();
	}
}

int WordBook::InputCheck(string Input)
{
	for (int i = 0; i < MAXIMUMWORDCREATE_LAST; i++)
	{
		if (m_iCreatedWordNum[i] == NULL)
			continue;
		else
		{
			if (m_WordBook[m_iCreatedWordNum[i]]->WordOutput() == Input)
			{
				m_InterfaceManager.EraseText(Input, m_WordBook[m_iCreatedWordNum[i]]->XposOutput(), m_WordBook[m_iCreatedWordNum[i]]->YposOutput());
				return i;
			}
			else
				continue;
		}
	}
	return MAXIMUMWORDCREATE_LAST; 
}

void WordBook::WordDelete(int Index)
{
	m_iCreatedWordNum[Index] = NULL;
}



void WordBook::AllWordReset()
{
	for (int i = 0; i < MAXIMUMWORDCREATE_LAST; i++)
	{
		if (m_iCreatedWordNum[i] == NULL)
			continue;
		else
		{
			m_InterfaceManager.EraseText(m_WordBook[m_iCreatedWordNum[i]]->WordOutput(), m_WordBook[m_iCreatedWordNum[i]]->XposOutput(), m_WordBook[m_iCreatedWordNum[i]]->YposOutput());
			m_iCreatedWordNum[i] = NULL;
		}
	}
}

void WordBook::WordItemCheak(int Index)
{
	if (m_WordBook[m_iCreatedWordNum[Index]]->ItemCheck() == true)
	{
		m_WordBook[m_iCreatedWordNum[Index]]->ItemUse();
	}
	return;
}

void WordBook::DifficultTune(int StageLevel)
{
	switch (StageLevel)
	{
	case 1:
		m_iWordDownSpeed = 450;
		m_iWordOutputRate = 3;
		m_iWordOutputSpeed = 2000;
		break;
	case 2:
		m_iWordDownSpeed = 400;
		m_iWordOutputRate = 3;
		m_iWordOutputSpeed = 2000;
		break;
	case 3:
		m_iWordDownSpeed = 375;
		m_iWordOutputRate = 2;
		m_iWordOutputSpeed = 1500;
		break;
	case 4:
		m_iWordDownSpeed = 350;
		m_iWordOutputRate = 2;
		m_iWordOutputSpeed = 1500;
		break;
	case 5:
		m_iWordDownSpeed = 325;
		m_iWordOutputRate = 2;
		m_iWordOutputSpeed = 1000;
		break;
	}
}

void WordBook::WordMaximumNumTune(int StageLevel)
{
	switch (StageLevel)
	{
	case 1:
		m_iWordMaximum = MAXIMUMWORDCREATE_STAGE1;
		break;
	case 2:
		m_iWordMaximum =  MAXIMUMWORDCREATE_STAGE2;
		break;
	case 3:
		m_iWordMaximum = MAXIMUMWORDCREATE_STAGE3;
		break;
	case 4:
		m_iWordMaximum = MAXIMUMWORDCREATE_STAGE4;
		break;
	case 5:
		m_iWordMaximum = MAXIMUMWORDCREATE_STAGE5;
		break;
	}
}

void WordBook::WordDraw()
{
	if (m_iCurTime <= m_iItemTime && m_bStopFlag == true)
		return;
	else
		m_bStopFlag = false;

	if (m_iCurTime > m_iItemTime && m_bBlindFlag == true)
		m_bBlindFlag = false;
	

	if ((m_iCurTime - m_iWordCreateTime > m_iWordOutputSpeed && (rand() % m_iWordOutputRate) == 1))  //5000이거 난이도에 따라 가변해야함
	{
		m_iWordCreateTime = m_iCurTime;
		RandomWordOutout(m_iWordMaximum); // 스테이지 당 갯수 제한
	}
	if ((m_iCurTime - m_iWordDownTime > m_iWordDownSpeed))
	{
		m_iWordDownTime = m_iCurTime;
		AllCreatedWordDown();
	}
	

}

void WordBook::TimeSet()
{
	Item::SetWordBookManagerInstance(this);
	m_iWordCreateTime = clock(), m_iWordDownTime = clock();
	m_iItemTime = clock();

}

void WordBook::WordDownSpeedAdjust(int AdjustLevel)
{
	m_iWordDownSpeed += AdjustLevel;
}

void WordBook::ItemTimeAdjust(int AdjustLevel)
{
	m_iItemTime = (m_iCurTime + AdjustLevel);
}

void WordBook::CurTimeSet()
{
	m_iCurTime = clock();
}

int WordBook::CurTimeAdjust(int AdjustLevel)
{
	return m_iCurTime += AdjustLevel;
}

void WordBook::BlindFlagOn()
{
	m_bBlindFlag = true;
}
void WordBook::StopFlagOn()
{
	m_bStopFlag = true;
}


WordBook::~WordBook()
{
	for (int i = 0; i < m_iWordNum; i++)
	{
		if (m_WordBook[i] != NULL)
			delete m_WordBook[i];
	}
	delete[] m_WordBook;
}
