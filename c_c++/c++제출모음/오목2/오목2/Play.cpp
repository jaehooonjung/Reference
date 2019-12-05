#include "Play.h"

Play::Play()
{
}

void Play::init(int Width, int Height)
{
	m_p1.MapSizeSet(Width, Height);
	m_p2.MapSizeSet(Width, Height);
	Map_Size_Set(Width, Height);
	m_MM.Menu_Option_UI_Set(Width, Height);
	m_p1.Player_Cursor_Pos_Set((Width / 2)*2, ((Height - 7) / 2));
	m_p2.Player_Cursor_Pos_Set((m_p1.Player_Cursor_x_Output()) + 2, m_p1.Player_Cursor_y_Output() + 2);


	m_iUndoCount = 5;


}
void Play::Shape_Init()
{
	m_p1.Player_Stone_Shape_Set("●");
	m_p2.Player_Stone_Shape_Set("○");
	m_p1.Player_Cursor_Shape_Set("●");
	m_p2.Player_Cursor_Shape_Set("○");
}


void Play::Map_Size_Set(int Width, int Height)
{
	m_iWidth = Width;
	m_iHeight = Height;
}

void Play::Game_Main()
{
	int Select;
	Shape_Init();
	while (true)
	{
		init();
		m_MM.Omok_Map_Draw(m_iWidth,m_iHeight);
		m_MM.Main_Menu(m_iWidth);
		cin >> Select;
		switch (Select)
		{
		case 1:
			Game_Play();
			break;
		case 2:
			Game_Option();
			break;

		case 3:
			return;
		}

	}
}

void Play::Game_Play()
{
	system("cls");
	m_iTurn = TURN_1P;
	string name;
	int Who_Turn;
	char ch;

	m_MM.Option_Box_Draw(m_iWidth, m_iHeight);
	m_MM.Player_Name_Input_Text(m_iWidth, 1);
	cin >> name;
	m_p1.Player_Name_Set(name);
	m_MM.Player_Name_Input_Text(m_iWidth, 2);
	cin >> name;
	m_p2.Player_Name_Set(name);

	system("cls");
	m_MM.Omok_Map_Draw(m_iWidth, m_iHeight);
	m_MM.Game_Tip_Output(m_iWidth, m_iHeight);
	m_MM.Game_Status_Output(m_iWidth, m_iHeight, m_p1.Player_Name_Output(), m_iTurn, m_iUndoCount);
	while (true)
	{
		ch = NULL;
		Who_Turn = m_iTurn % 2;
		Game_Status_Update(Who_Turn);
		if (Who_Turn == TURN_1P) // 1p의 차례
		{
			m_MM.gotoxy(m_p1.Player_Cursor_x_Output(), m_p1.Player_Cursor_y_Output());
			m_p1.Player_Cursor_Output();
			while (true)
			{
				ch = getch();
				if (ch == DIRECTION_LEFT || ch == DIRECTION_RIGHT || ch == DIRECTION_UP || ch == DIRECTION_DOWN)
					Cursor_Move(m_p1.Player_Cursor_x_Output(), m_p1.Player_Cursor_y_Output(), m_iWidth, m_iHeight, Who_Turn, ch);
				if (ch == HOTKEY_STONE_ON)
				{
					if (m_p1.Player_Stone_Placed_Check(m_p1.Player_Cursor_x_Output(), m_p1.Player_Cursor_y_Output()) == false &&
						m_p2.Player_Stone_Placed_Check(m_p1.Player_Cursor_x_Output(), m_p1.Player_Cursor_y_Output()) == false)
					{
						m_p1.Stone_Place(m_p1.Player_Cursor_x_Output(), m_p1.Player_Cursor_y_Output());
						if (m_p1.Win_Check() == true)
						{
							m_MM.DrawMidText("1p 승리", m_MM.UI_Pos_x_output(), m_MM.UI_Pos_y_output()*2);
							getch();
							return;
						}
						m_iTurn++;
						break;
					}
				}
				if (ch == HOTKEY_UNDO)
				{
					Undo_Manager(TURN_1P);
					break;
				}
				if (ch == HOTKEY_OPTION)
				{
					Game_Option();
					Option_Apply(TURN_1P);
				}
				if (ch == HOTKEY_ESC)
					return;

			}
		}
		else if (Who_Turn == TURN_2P) // 2p의 차례
		{
			m_MM.gotoxy(m_p2.Player_Cursor_x_Output(), m_p2.Player_Cursor_y_Output());
			m_p2.Player_Cursor_Output();

			while (true)
			{
				ch = getch();
				if (ch == DIRECTION_LEFT || ch == DIRECTION_RIGHT || ch == DIRECTION_UP || ch == DIRECTION_DOWN)
				Cursor_Move(m_p2.Player_Cursor_x_Output(), m_p2.Player_Cursor_y_Output(), m_iWidth, m_iHeight, Who_Turn,ch);
				if (ch == HOTKEY_STONE_ON)
				{
					if (m_p1.Player_Stone_Placed_Check(m_p2.Player_Cursor_x_Output(), m_p2.Player_Cursor_y_Output()) == false && 
						m_p2.Player_Stone_Placed_Check(m_p2.Player_Cursor_x_Output(), m_p2.Player_Cursor_y_Output()) == false)
					{
						m_p2.Stone_Place(m_p2.Player_Cursor_x_Output(), m_p2.Player_Cursor_y_Output());
						if (m_p2.Win_Check() == true)
						{
							m_MM.DrawMidText("2p 승리", m_MM.UI_Pos_x_output(), m_MM.UI_Pos_y_output()*2);
							getch();
							return;
						}
						m_iTurn++;
						break;
					}
				}
				if (ch == HOTKEY_UNDO)
				{
					Undo_Manager(TURN_2P);
					break;
				}
				if (ch == HOTKEY_OPTION)
				{
					Game_Option();
					Option_Apply(TURN_2P);
				}
				if (ch == HOTKEY_ESC)
					return;
			}
		}
	}
}

void Play::Option_Apply(int WhoTurn)
{
	m_MM.Omok_Map_Draw(m_iWidth, m_iHeight);
	for (int i = 0; i < m_p1.Stone_Num_Output(); i++)
		Omok_Map_Erase_BackUp(m_p1.Stone_Pos_X(i), m_p1.Stone_Pos_Y(i));
	for (int i = 0; i < m_p2.Stone_Num_Output(); i++)
		Omok_Map_Erase_BackUp(m_p2.Stone_Pos_X(i), m_p2.Stone_Pos_Y(i));
	m_MM.Game_Tip_Output(m_iWidth, m_iHeight);
	Game_Status_Update(WhoTurn);
}

void Play::Game_Status_Update(int WhoTurn)
{
	if (WhoTurn == TURN_1P)  //함수화 해서 인이트 시키기
		m_MM.Game_Status_Output(m_iWidth, m_iHeight, m_p1.Player_Name_Output(), m_iTurn, m_iUndoCount);
	else if (WhoTurn == TURN_2P)
		m_MM.Game_Status_Output(m_iWidth, m_iHeight, m_p2.Player_Name_Output(), m_iTurn, m_iUndoCount);

}

void Play::Undo_Manager(int Who_Turn)
{
	if (m_iUndoCount - 1 < 0)
		return;
	if (Who_Turn == TURN_1P && m_iTurn > 1)
	{
		m_MM.ErasePoint(m_p1.Player_Cursor_x_Output(), m_p1.Player_Cursor_y_Output()); 
		Omok_Map_Erase_BackUp(m_p1.Player_Cursor_x_Output(), m_p1.Player_Cursor_y_Output());

		m_MM.ErasePoint(m_p2.Last_Stone_Pos_X() ,m_p2.Last_Stone_Pos_Y()); //스톤 갯수 
		m_p2.Undo();
		Omok_Map_Erase_BackUp(m_p2.Player_Cursor_x_Output(), m_p2.Player_Cursor_y_Output());

	}
	else if (Who_Turn == TURN_2P)
	{
		m_MM.ErasePoint(m_p2.Player_Cursor_x_Output(), m_p2.Player_Cursor_y_Output());
		Omok_Map_Erase_BackUp(m_p2.Player_Cursor_x_Output(), m_p2.Player_Cursor_y_Output());

		m_MM.ErasePoint(m_p1.Last_Stone_Pos_X(), m_p1.Last_Stone_Pos_Y()); //스톤 갯수 
		m_p1.Undo();
		Omok_Map_Erase_BackUp(m_p1.Player_Cursor_x_Output(), m_p1.Player_Cursor_y_Output());
	}
	m_iTurn--;
	m_iUndoCount--;

}


void Play::Cursor_Move(int x, int y, int Width, int Height, int Who_Turn,int ch)
{
		m_MM.ErasePoint(x, y);
		Omok_Map_Erase_BackUp(x, y);
	switch (ch)
	{
	case DIRECTION_LEFT:
		if ((x - 1) > 0)
			x-=2;
		break;

	case DIRECTION_RIGHT:
		if ((x + 1) < m_iWidth*2-1)
			x+=2;
		break;
	case DIRECTION_UP:
		if ((y - 1) >= 0)
			y--;
		break;

	case DIRECTION_DOWN:
		if ((y + 1) <= m_iHeight-7)
			y++;
		break;
	}
		m_MM.gotoxy(x, y);
		if (Who_Turn == 1)
		{
			m_p1.Player_Cursor_Pos_Set(x, y);
			m_p1.Player_Cursor_Output();
		}
		else if (Who_Turn == 0)
		{
			m_p2.Player_Cursor_Pos_Set(x, y);
			m_p2.Player_Cursor_Output();
		}

	
}

void Play::Omok_Map_Erase_BackUp(int x, int y)
{
	if (m_p1.Player_Stone_Placed_Check(x, y) == true)
	{
		m_MM.gotoxy(x, y);
		m_p1.Player_Stone_Output();
		return;
	}
	if (m_p2.Player_Stone_Placed_Check(x, y) == true)
	{
		m_MM.gotoxy(x, y);
		m_p2.Player_Stone_Output();
		return;
	}
	if (x == 0)
	{
		if (y == 0)
			cout << "┌";
		else if (y == m_iHeight - 7)
			cout << "└";
		else
			cout << "├";
	}
	else if (x == m_iWidth * 2 - 2)
	{
		if (y == 0)
			cout << "┐";
		else if (y == m_iHeight - 7)
			cout << "┘";
		else
			cout << "┤";
	}
	else if (y == 0)
	{
		if (x > 0 && x < m_iWidth * 2)
			cout << "┬";
	}
	else if (y == m_iHeight - 7)
	{
		if (x > 0 && x < m_iWidth * 2)
			cout << "┴";
	}
	else if (x > 1 && x < m_iWidth * 2 - 2 && y > 0 && y < m_iHeight - 7)
		cout << "┼";

}

void Play::Game_Option()
{
	int Select;
	while (true)
	{
		m_MM.Option_Box_Draw(m_iWidth, m_iHeight);
		m_MM.Option_Menu(m_iWidth, m_iHeight);
		cin >> Select;
		system("cls");
		switch (Select)
		{
		case 1:
			if (m_iTurn > 0)
			{
				system("cls");
				m_MM.DrawMidText("접근 불가능", m_iWidth, m_MM.UI_Pos_y_output());
				getch();
				break;
			}
			Omok_Map_Size_Change();
			break;
		case 2:
			Option_Cursor_Shape_Change();
			break;
		case 3:
			Option_Stone_Shape_Change();
			break;
		case 4:
			if (m_iTurn > 0)
			{
				system("cls");
				m_MM.DrawMidText("접근 불가능", m_iWidth, m_MM.UI_Pos_y_output());
				getch();
				break;
			}
			Option_Undo_Count_Change();
			break;
		case 5:
			return;
		}


	}

}

void Play::Omok_Map_Size_Change()
{
	int tmpWidth = 0;
	int tmpHeight = 0;
	while (true)
	{
		m_MM.Option_Box_Draw(m_iWidth, m_iHeight);
		m_MM.DrawMidText("Width : ", m_iWidth, m_MM.UI_Pos_y_output());
		cin >> tmpWidth;
		m_MM.DrawMidText("Height : ", m_iWidth, m_MM.UI_Pos_y_output() + m_MM.UI_Blankspace_output());
		cin >> tmpHeight;
		if ((tmpWidth >= 20 && tmpWidth <= 90) && (tmpHeight >= 20 && tmpHeight <= 45))
			break;
		system("cls");
		m_MM.Option_Box_Draw(m_iWidth, m_iHeight);
		m_MM.DrawMidText("변경 불가능", m_iWidth, m_MM.UI_Pos_y_output());
		m_MM.DrawMidText("(가로 : 20 ~ 90, 세로 : 20 ~ 45)", m_iWidth, m_MM.UI_Pos_y_output() + m_MM.UI_Blankspace_output());
		getch();
	}
	init(tmpWidth, tmpHeight);
}

void Play::Option_Cursor_Shape_Change()
{
	int Select;

	while (true)
	{
		m_MM.Option_Cursor_Shape_Change_Text(m_iWidth);
		cin >> Select;
		switch (Select)
		{
		case 1:
			m_p1.Player_Cursor_Shape_Set("○");
			m_p2.Player_Cursor_Shape_Set("○");
			return;
		case 2:
			m_p1.Player_Cursor_Shape_Set("♡");
			m_p2.Player_Cursor_Shape_Set("♥");
			return;
		case 3:
			m_p1.Player_Cursor_Shape_Set("☞");
			m_p2.Player_Cursor_Shape_Set("☜");
			return;
		case 4:
			m_p1.Player_Cursor_Shape_Set("①");
			m_p2.Player_Cursor_Shape_Set("②");
			return;
		case 5:
			return;
		}
	}	
}

void Play::Option_Stone_Shape_Change()
{
	int Select;

	while (true)
	{
		m_MM.Option_Stone_Shape_Change_Text(m_iWidth);
		cin >> Select;
		switch (Select)
		{
		case 1:
			m_p1.Player_Stone_Shape_Set("○");
			m_p2.Player_Stone_Shape_Set("○");
			return;
		case 2:
			m_p1.Player_Stone_Shape_Set("♡");
			m_p2.Player_Stone_Shape_Set("♥");
			return;
		case 3:
			m_p1.Player_Stone_Shape_Set("☞");
			m_p2.Player_Stone_Shape_Set("☜");
			return;
		case 4:
			m_p1.Player_Stone_Shape_Set("①");
			m_p2.Player_Stone_Shape_Set("②");
			return;
		case 5:
			return;
		}
	}
}

void Play::Option_Undo_Count_Change()
{
	int Select;
	int TmpCount = NULL;
	while (true)
	{
		m_MM.Option_Box_Draw(m_iWidth, m_iHeight);
		m_MM.Option_Undo_Text(m_iWidth);
		cin >> Select;
		switch (Select)
		{
		case 1:
			while (true)
			{
				system("cls");
				m_MM.Option_Box_Draw(m_iWidth, m_iHeight);

				m_MM.DrawMidText("무르기 횟수 입력 (최대 10회) : ", m_iWidth, (m_iHeight - 7) / 2);
				cin >> TmpCount;
				if (TmpCount <= 10 && TmpCount > 0)
					break;
				m_MM.DrawMidText("범위가 맞지 않습니다. (범위 1~10)", m_iWidth, ((m_iHeight - 7) / 2)+2);
				getch();
			}
			Undo_Count_Change(TmpCount);
			return;

		case 2:
			system("cls");
			m_MM.Option_Box_Draw(m_iWidth, m_iHeight);
			m_MM.DrawMidText("무르기 OFF", m_iWidth, (m_iHeight - 7) / 2);
			Undo_Count_Change(0);
			getch();
			return;
		case 3:
			return;
		}
	}

}

void Play::Undo_Count_Change(int Count)
{
	m_iUndoCount = Count;
}


Play::~Play()
{
}
