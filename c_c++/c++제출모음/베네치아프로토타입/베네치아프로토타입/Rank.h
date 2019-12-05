#pragma once
#include"Interface.h"

struct RANKBOOK
{
	int m_iScore;
	int m_iStage;
	string m_strPlayerName;
};

class Rank
{
private:
	int m_iRankNum;
	Interface InterfaceManager;
	RANKBOOK m_RankBook[10];
public:
	void RankDisplay();
	void RankArray();
	void RankInCheck(string Name, int Stage, int Score);
	Rank();
	~Rank();
};

