#pragma once
#include"Mecro.h"

class MapManager
{
private:
	int m_iMainMenuUI_pos_x;
	int m_iMainMenuUI_pos_y;
	int m_iBlankSpace;

public:
	void Menu_Option_UI_Set(int Width, int Height);
	void Omok_Map_Draw(int Width, int Height);
	void Option_Box_Draw(int Width, int Height);
	void Console_Size(int Width, int Height);
	void Main_Menu(int Width);
	void Option_Menu(int Width, int Height);
	void DrawMidText(string str, int x, int y);
	void Player_Name_Input_Text(int Width,int Player);
	void Game_Tip_Output(int Width, int Height);
	void ErasePoint(int x, int y);
	void Option_Cursor_Shape_Change_Text(int Width);
	void Option_Stone_Shape_Change_Text(int Width);
	void Option_Undo_Text(int Width);
	void Game_Status_Output(int Width, int Height, string name, int turn, int undocount);


	MapManager();//20~90 , 20~45
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	inline int UI_Pos_x_output()
	{
		return m_iMainMenuUI_pos_x;
	}
	inline int UI_Pos_y_output()
	{
		return m_iMainMenuUI_pos_y;
	}
	inline int UI_Blankspace_output()
	{
		return m_iBlankSpace;
	}

	~MapManager();
};

