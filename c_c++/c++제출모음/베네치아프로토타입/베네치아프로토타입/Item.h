#pragma once
#include"Mecro.h"

class WordBook;
class Item
{
protected:
	string m_ItemName;
	string m_ItemExplanation;
public:
	static WordBook* s_WordBookManager;
	static void SetWordBookManagerInstance(WordBook* This)
	{
		s_WordBookManager = This;
	}
	virtual void Ability() = 0;
	Item();
	~Item();
};

class WordBook;
class ItemDisplayClear: public Item
{
public:
	void Ability();
	ItemDisplayClear();
	~ItemDisplayClear();
};

class WordBook;
class ItemSpeedDown : public Item
{
public:
	void Ability();
	ItemSpeedDown();
	~ItemSpeedDown();
};

class WordBook;
class ItemSpeedUp : public Item
{
public:
	void Ability();
	ItemSpeedUp();
	~ItemSpeedUp();
};


class WordBook;
class ItemWordBlackOut : public Item
{
public:
	void Ability();
	ItemWordBlackOut();
	~ItemWordBlackOut();
};


class WordBook;
class ItemWordStop : public Item
{
public:
	void Ability();
	ItemWordStop();
	~ItemWordStop();
};
