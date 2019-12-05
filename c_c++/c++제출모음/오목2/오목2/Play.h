#pragma once
#include"MapManager.h"
#include"Player.h"

enum DIRECTION
{
	DIRECTION_LEFT = 'a',
	DIRECTION_RIGHT = 'd',
	DIRECTION_UP = 'w',
	DIRECTION_DOWN = 's'
};

enum HOTKEY
{
	HOTKEY_STONE_ON = 'r',
	HOTKEY_OPTION = 'p',
	HOTKEY_UNDO= 'n',
	HOTKEY_ESC = 27
};

enum TURN
{
	TURN_1P = 1,
	TURN_2P = 0
};

class Play
{
private:
	MapManager m_MM;
	Player m_p1;
	Player m_p2;

	int m_iWidth;
	int m_iHeight;
	int m_iTurn;
	int m_iUndoCount;
	void Undo_Count_Change(int Count);
public:
	void init(int Width = 45, int Height = 32); //20~90 , 20~45
	void Map_Size_Set(int Width, int Height);
	void Game_Main();
	void Game_Option();
	void Game_Play();
	void Omok_Map_Size_Change();
	void Cursor_Move(int x, int y, int Width, int Height,int Who_Turn, int ch);
	void Option_Cursor_Shape_Change();
	void Option_Stone_Shape_Change();
	void Option_Undo_Count_Change();
	void Omok_Map_Erase_BackUp(int x, int y);
	void Undo_Manager(int Who_Turn);
	void Option_Apply(int WhoTurn);
	void Game_Status_Update(int WhoTurn);
	void Shape_Init();


	Play();
	~Play();
};

