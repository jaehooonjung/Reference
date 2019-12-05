#pragma once
#include"WordBook.h"
#include"Rank.h"

class Play
{
private:
	int m_iHp;
	int m_iScore;
	int m_iStage;
	bool m_bGameStatus;
	string m_strName;
	Interface InterfaceManager;
	WordBook WordBookManger;
	Rank RankManager;
public:
	void GamePlayMain();
	void Init();
	void GamePlay();
	bool GameStatusUpdate();
	string HpToHeart(int Hp);
	void ScoreUp(int StrLength);
	Play();
	~Play();
};

