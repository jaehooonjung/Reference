#pragma once
#include"Mecro.h"
#define UP 'w'
#define DOWN 's'
#define ENTER 13

enum GATENUMMARK
{
	GATENUMMARK_START,
	GATENUMMARK_1,
	GATENUMMARK_2,
	GATENUMMARK_3,
	GATENUMMARK_MAX
};

class MapDraw
{
public:
	void DrawMidText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void DrawPoint(string str, int x, int y);
	void ErasePoint(int x, int y);
	void EraseText(string Text, int x, int y);
	int  MenuSelectCursor(int MenuLen, int AddCol, int x, int y); //�޴�â����, �޴�â������ ���̰Ÿ�, ȭ��ǥ���� ������ġ, ȭ��ǥ���� ������ġ
	void MenuDraw();
	void GateDraw();
	MapDraw();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~MapDraw();
};

