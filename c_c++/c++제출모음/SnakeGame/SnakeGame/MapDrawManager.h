#pragma once
#include"Mecro.h"

class MapDrawManager
{
public:
	void DrawMidText(string str, int x, int y);
	void DrawPoint(string str, int x, int y);
	void ErasePoint(int x, int y);
	MapDrawManager();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

	~MapDrawManager();
};

