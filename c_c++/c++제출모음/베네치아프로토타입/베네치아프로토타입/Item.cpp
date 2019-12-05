#include "Item.h"
#include"WordBook.h"

WordBook* Item::s_WordBookManager = NULL;

Item::Item()
{
}

Item::~Item()
{
}

ItemDisplayClear::ItemDisplayClear()
{
	m_ItemName = "DisplayClear";
}

void ItemDisplayClear::Ability()
{
	s_WordBookManager->AllWordReset();
}

ItemDisplayClear::~ItemDisplayClear()
{
}

ItemSpeedDown::ItemSpeedDown()
{
	m_ItemName = "ItemSpeedDown";
}

void ItemSpeedDown::Ability()
{
	s_WordBookManager->WordDownSpeedAdjust(300);
}

ItemSpeedDown::~ItemSpeedDown()
{
}

ItemSpeedUp::ItemSpeedUp()
{
	m_ItemName = "ItemSpeedUp";

}

void ItemSpeedUp::Ability()
{
	s_WordBookManager->WordDownSpeedAdjust(-150);
}

ItemSpeedUp::~ItemSpeedUp()
{
}


ItemWordBlackOut::ItemWordBlackOut()
{
	m_ItemName = "ItemWordBlackOut";
}

void ItemWordBlackOut::Ability()
{
	s_WordBookManager->ItemTimeAdjust(3000);
	s_WordBookManager->BlindFlagOn();
}

ItemWordBlackOut::~ItemWordBlackOut()
{
}

ItemWordStop::ItemWordStop()
{
	m_ItemName = "ItemWordStop";
}

void ItemWordStop::Ability()
{
	s_WordBookManager->ItemTimeAdjust(3000);
	s_WordBookManager->StopFlagOn();
}

ItemWordStop::~ItemWordStop()
{

	delete s_WordBookManager;
}