#include "MapManager.h"

MapManager::MapManager()
{
}


void MapManager::Menu_Option_UI_Set(int Width, int Height)
{
	if ((Width % 2) == 1)
		m_iMainMenuUI_pos_x = Width - 1;
	else
		m_iMainMenuUI_pos_x = Width;

	m_iMainMenuUI_pos_y = (Height - 12) / 4; // 혹시나 홀수 들어오면 예외화 필요할듯
	m_iBlankSpace = (Height / 12); //12는 맵 높이가 최하 20일때 필요한 공백+메뉴를 합친 행의 수

}

void MapManager::Console_Size(int Width, int Height)
{
	char buf[256];
	sprintf(buf, "mode con: cols=%d lines=%d", Width * 2, Height);
	system(buf);

}

void MapManager::Omok_Map_Draw(int Width, int Height)
{
	Console_Size(Width, Height);
	for (int y = 0; y < Height; y++)
	{
		gotoxy(0, y);
		if (y == 0)
		{
			cout << "┌";
			for (int x = 1; x < Width - 1; x++)
				cout << "┬";
			cout << "┐";
		}
		else if (y == (Height - 7))
		{
			cout << "└";
			for (int x = 1; x < Width - 1; x++)
				cout << "┴";
			cout << "┘";
			break;
		}
		else
		{
			cout << "├";
			for (int x = 1; x < Width - 1; x++)
				cout << "┼";
			cout << "┤";
		}

	}
	return;

}
void MapManager::Option_Box_Draw(int Width, int Height)
{
	Console_Size(Width, Height);
	for (int y = 0; y < Height; y++)
	{
		gotoxy(0, y);
		if (y == 0)
		{
			cout << "┌";
			for (int x = 1; x < Width - 1; x++)
				cout << "─";
			cout << "┐";
		}
		else if (y == (Height - 7))
		{
			cout << "└";
			for (int x = 1; x < Width - 1; x++)
				cout << "─";
			cout << "┘";
			break;
		}
		else
		{
			cout << "│";
			for (int x = 1; x < Width - 1; x++)
				cout << "  ";
			cout << "│";
		}

	}
	return;

}

void MapManager::Main_Menu(int Width)
{
	int posy = m_iMainMenuUI_pos_y;
	DrawMidText("★ 오목 ★", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("1. 게임 시작", Width, posy);

	posy += m_iBlankSpace;
	DrawMidText("2. 옵션 설정", Width, posy);

	posy += m_iBlankSpace;
	DrawMidText("3. 게임 종료", Width, posy);

	posy += m_iBlankSpace;
	DrawMidText("          ", Width, posy);
	gotoxy(m_iMainMenuUI_pos_x, posy);


}

void MapManager::Option_Menu(int Width, int Height)
{
	int posy = m_iMainMenuUI_pos_y;
	DrawMidText("= Option =", Width, posy);

	posy += m_iBlankSpace;
	DrawMidText("1. Map Size Set", Width, posy);

	posy += m_iBlankSpace;
	DrawMidText("2. Cursor Custom", Width, posy);

	posy += m_iBlankSpace;
	DrawMidText("3. Stone Custom", Width, posy);

	posy += m_iBlankSpace;
	DrawMidText("4. Undo Count Set", Width, posy);

	posy += m_iBlankSpace;
	DrawMidText("5. Return", Width, posy);

	posy += m_iBlankSpace;
	DrawMidText("입력 : ", Width, posy);

}
void MapManager::Game_Tip_Output(int Width,int Height)
{
	DrawMidText("===조작키==", Width, Height-6);
	DrawMidText("이동  : a,s,w,d 돌놓기 : r", Width, Height - 5);
	DrawMidText("무르기 : n 옵션 : p 종료 : esc", Width, Height - 4);
}

void  MapManager::Game_Status_Output(int Width, int Height,string name, int turn, int undocount)
{
	DrawMidText("Player name : ", Width, Height - 3);
	cout << name;
	cout << " 턴 수 : ";
	cout << turn;
	DrawMidText("무르기 횟수 : ", Width, Height - 2);
	cout << undocount;


}


void MapManager::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

void MapManager::Player_Name_Input_Text(int Width, int Player)
{
	string str;
	if(Player == 1)
		str += "1P 플레이어 이름 : ";
	else
		str += "2P 플레이어 이름 : ";
	DrawMidText(str, Width, m_iMainMenuUI_pos_y+(Player*2));
}
void MapManager::ErasePoint(int x, int y)
{
	gotoxy(x, y);
	cout << "  ";
	gotoxy(x, y);
	return;
}

void MapManager::Option_Cursor_Shape_Change_Text(int Width)
{
	int posy = m_iMainMenuUI_pos_y;
	DrawMidText("= Set Cursor =", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("1. ○,●", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("2. ♡,♥", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("3. ☞,☜", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("4. ①,②", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("5. return", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("입력 : ", Width, posy);

}

void MapManager::Option_Stone_Shape_Change_Text(int Width)
{
	int posy = m_iMainMenuUI_pos_y;
	DrawMidText("= Set Stone =", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("1. ○,●", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("2. ♡,♥", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("3. ☞,☜", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("4. ①,②", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("5. return", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("입력 : ", Width, posy);

}

void MapManager::Option_Undo_Text(int Width)
{
	int posy = m_iMainMenuUI_pos_y;
	DrawMidText("= Set Undo =", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("1. Set Undo Count", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("2. Undo OFF", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("3. Return", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("입력 : ", Width, posy);


}



MapManager::~MapManager()
{
}
