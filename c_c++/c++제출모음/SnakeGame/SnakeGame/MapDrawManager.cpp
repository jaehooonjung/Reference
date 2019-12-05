#include "MapDrawManager.h"



MapDrawManager::MapDrawManager()
{
}

void MapDrawManager::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

void MapDrawManager::DrawPoint(string str, int x, int y)
{
	gotoxy(x*2, y);
	cout << str;

}

void MapDrawManager::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}


MapDrawManager::~MapDrawManager()
{
}
