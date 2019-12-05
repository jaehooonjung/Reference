#pragma once
#include"Item.h"
#include"Interface.h"
class Word
{
private:
	string m_strText;
	int m_iWordXpos;
	int m_iWordYpos;
	Interface InterfaceManager;
	Item * m_Item;
public:
	void WordRegister(string Text);
	int WordXposRandomSetupAndYposReset();
	void WordYposDown();
	void WordItemSet(Item*SelectItem);
	void ItemUse();
	bool ItemCheck();
	void WordDraw();
	Word();
	inline string WordOutput()
	{
		return m_strText;
	}
	inline int XposOutput()
	{
		return m_iWordXpos;
	}
	inline int YposOutput()
	{
		return m_iWordYpos;
	}
	~Word();
};

