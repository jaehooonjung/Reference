#include "Word.h"



Word::Word()
{
	m_Item = NULL;
}

void Word::WordRegister(string Text)
{
	m_strText = Text;
}

int Word::WordXposRandomSetupAndYposReset()
{
	m_iWordYpos = 1;
	m_iWordXpos = (rand() % (WIDTH*2));
	if (m_iWordXpos < 10)
		m_iWordXpos += 10;
	else if (m_iWordXpos > WIDTH*2-10)
		m_iWordXpos -= 10;
	
	return m_iWordXpos;
}

void Word::WordYposDown()
{
	m_iWordYpos++;
}

void Word::WordItemSet(Item*SelectItem)
{
	m_Item = SelectItem;
}

bool Word::ItemCheck()
{
	if (m_Item != NULL)
		return true;
	else
		return false;
}

void Word::ItemUse()
{
	m_Item->Ability();
	return;
}

void Word::WordDraw()
{
	InterfaceManager.TextDraw(m_strText, m_iWordXpos, m_iWordYpos);
}


Word::~Word()
{
	if (m_Item != NULL)
	{
		delete m_Item;
		m_Item = NULL;
	}
}
