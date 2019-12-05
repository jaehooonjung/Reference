#pragma once
#include"Mecro.h"
#define UP 'w'
#define DOWN 's'
#define ENTER 13

class Interface
{
public:
	Interface();
	void BoxDraw(int Start_x, int Start_y, int Width, int Height);
	void BoxDraw2(int Start_x, int Start_y, int End_x, int End_y);
	void BoxErase(int Width, int Height);
	void DrawPoint(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void ErasePoint(int x, int y);
	void EraseLine(int y);
	int MenuSelectCursor(int MenuLen, int AddCol, int x, int y); //�޴�â���� , �޴�â������ ���̰Ÿ�, ȭ��ǥ���� ������ġ , ȭ��ǥ���� ������ġ
	void EraseText(string Text, int x, int y);
	void GameMainDisplay();
	void GameInitDisplay();
	void PlayStatus(string Hp, int Score, string Name, int StageNum);
	void StoryDisplay();
	string NameSet();
		inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~Interface();
};

