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

	m_iMainMenuUI_pos_y = (Height - 12) / 4; // Ȥ�ó� Ȧ�� ������ ����ȭ �ʿ��ҵ�
	m_iBlankSpace = (Height / 12); //12�� �� ���̰� ���� 20�϶� �ʿ��� ����+�޴��� ��ģ ���� ��

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
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "��";
			cout << "��";
		}
		else if (y == (Height - 7))
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "��";
			cout << "��";
			break;
		}
		else
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "��";
			cout << "��";
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
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "��";
			cout << "��";
		}
		else if (y == (Height - 7))
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "��";
			cout << "��";
			break;
		}
		else
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "  ";
			cout << "��";
		}

	}
	return;

}

void MapManager::Main_Menu(int Width)
{
	int posy = m_iMainMenuUI_pos_y;
	DrawMidText("�� ���� ��", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("1. ���� ����", Width, posy);

	posy += m_iBlankSpace;
	DrawMidText("2. �ɼ� ����", Width, posy);

	posy += m_iBlankSpace;
	DrawMidText("3. ���� ����", Width, posy);

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
	DrawMidText("�Է� : ", Width, posy);

}
void MapManager::Game_Tip_Output(int Width,int Height)
{
	DrawMidText("===����Ű==", Width, Height-6);
	DrawMidText("�̵�  : a,s,w,d ������ : r", Width, Height - 5);
	DrawMidText("������ : n �ɼ� : p ���� : esc", Width, Height - 4);
}

void  MapManager::Game_Status_Output(int Width, int Height,string name, int turn, int undocount)
{
	DrawMidText("Player name : ", Width, Height - 3);
	cout << name;
	cout << " �� �� : ";
	cout << turn;
	DrawMidText("������ Ƚ�� : ", Width, Height - 2);
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
		str += "1P �÷��̾� �̸� : ";
	else
		str += "2P �÷��̾� �̸� : ";
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
	DrawMidText("1. ��,��", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("2. ��,��", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("3. ��,��", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("4. ��,��", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("5. return", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("�Է� : ", Width, posy);

}

void MapManager::Option_Stone_Shape_Change_Text(int Width)
{
	int posy = m_iMainMenuUI_pos_y;
	DrawMidText("= Set Stone =", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("1. ��,��", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("2. ��,��", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("3. ��,��", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("4. ��,��", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("5. return", Width, posy);
	posy += m_iBlankSpace;
	DrawMidText("�Է� : ", Width, posy);

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
	DrawMidText("�Է� : ", Width, posy);


}



MapManager::~MapManager()
{
}
