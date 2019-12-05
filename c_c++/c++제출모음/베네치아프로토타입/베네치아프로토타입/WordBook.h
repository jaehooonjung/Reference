#pragma once
#include"Interface.h"
#include"Word.h"

class WordBook
{
private:
	int m_iWordNum;
	int m_iCreatedWordNum[MAXIMUMWORDCREATE_LAST];
	int m_iWordDownSpeed;
	int m_iWordOutputRate;
	int m_iWordOutputSpeed;
	int m_iWordCreateTime;
	int m_iWordDownTime;
	int m_iWordMaximum;
	int m_iItemTime;
	int m_iCurTime;
	bool m_bStopFlag;
	bool m_bBlindFlag;
	Word ** m_WordBook;
	Interface m_InterfaceManager;
public:
	void RandomWordOutout(int CreatedWordNumflag);
	void AllCreatedWordDown();
	bool AllCreatedWordCheck();
	int InputCheck(string Input);
	string WordHideBoxCheck(Word*WordTmp);
	void AllWordReset();
	void WordDelete(int Index);
	void WordItemCheak(int Index);
	void DifficultTune(int StageLevel);
	void WordMaximumNumTune(int StageLevel);
	void WordDraw();
	void TimeSet();
	void WordDownSpeedAdjust(int AdjustLevel);
	void ItemTimeAdjust(int AdjustLevel);
	void CurTimeSet();
	int CurTimeAdjust(int AdjustLevel);
	void StopFlagOn();
	void BlindFlagOn();
	WordBook();
	inline int CurTimeOutput()
	{
		return m_iCurTime;
	}
	~WordBook();
};

