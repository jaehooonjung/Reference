#include "Interface.h"



Interface::Interface()
{
	char buf[256];
	sprintf(buf, "mode con: cols=%d lines=%d", WIDTH * 2, HEIGHT);
	system(buf);
}

void Interface::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}
void Interface::EraseLine(int y)
{
	gotoxy(2, y);
	cout << "                                                                                                ";
	return;
}
void Interface::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void Interface::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}
void Interface::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}

void Interface::BoxErase(int Width, int Height)
{
	for (int y = 1; y < Height - 1; y++)
	{
		gotoxy(2, y);
		for (int x = 1; x < Width - 1; x++)
			cout << "  ";
	}
}

void Interface::BoxDraw(int Start_x, int Start_y, int Width, int Height)
{
	if (Start_x > Width)
		Start_x -= Width;
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y + y);
		if (y == 0)
		{
			cout << "┌";
			for (int x = 1; x < Width - 1; x++)
				cout << "─";
			cout << "┐";
		}
		else if (y == Height - 1)
		{
			cout << "└";
			for (int x = 1; x < Width - 1; x++)
				cout << "─";
			cout << "┘";
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

void Interface::BoxDraw2(int Start_x, int Start_y, int End_x, int End_y)
{
	if (Start_x >= End_x || Start_y >= End_y)
	{
		system("cls");
		gotoxy(0, 0);
		cout << "박스설정값 오류";
	}
	else
	{
		for (int i = 0; i < End_y- Start_y; i++)
		{
			if (i == 0)
			{
				gotoxy(Start_x, Start_y);
				cout << "┌";
				for (int i = 0; i < (End_x - Start_x) - 1; i++)
				{
					cout << "─";
				}
				cout << "┐";
			}
			else if (i == (End_y - Start_y)-1)
			{
				gotoxy(Start_x, End_y-1);
				cout << "└";
				for (int i = 0; i < (End_x - Start_x) - 1; i++)
				{
					cout << "─";
				}
				cout << "┘";
			}
			else
			{
				gotoxy(Start_x, Start_y+i);
				cout << "│";
				for (int i = 0; i < (End_x - Start_x) - 1; i++)
				{
					cout << "  ";
				}
				cout << "│";

			}
		}

	}

	return;
}



int Interface::MenuSelectCursor(int MenuLen, int AddCol, int x, int y)
{
	int Select = 1;
	RED
		DrawPoint("▷", x, y);
	ORIGINAL
		while (1)
		{
			switch (getch())
			{
			case UP:
				if (Select - 1 >= 1)
				{
					ErasePoint(x, y);
					y -= AddCol;
					Select--;
				}
				break;
			case DOWN:
				if (Select + 1 <= MenuLen)
				{
					ErasePoint(x, y);
					y += AddCol;
					Select++;
				}
				break;
			case ENTER:
				return Select;
			}
			RED
				DrawPoint("▷", x, y);
			ORIGINAL
		}
}

void Interface::EraseText(string Text, int x, int y)
{
	int TextLength = Text.length();
	string Eraser = { "" };
	for (int i = 0; i < TextLength; i++)
	{
		Eraser += " ";
	}
	gotoxy(x , y);
	cout << Eraser;
	return;
}

void Interface::GameMainDisplay()
{
	BoxDraw(0, 0, WIDTH, HEIGHT-5);
	DrawMidText("★ ☆ 베 네 치 아 ☆ ★", WIDTH, HEIGHT*0.2f);
	DrawMidText("1. 게임 시작", WIDTH, HEIGHT*0.4f);
	DrawMidText("2. 점 수 판", WIDTH, HEIGHT*0.5f);
	DrawMidText("3. 게임 종료", WIDTH, HEIGHT*0.6f);
}

void Interface::GameInitDisplay()
{
	BoxDraw(0, 0, WIDTH, HEIGHT - 5);
	BoxDraw2(35, (HEIGHT -15), 50, 30);
}

void Interface::PlayStatus(string Hp, int Score, string Name, int StageNum)
{
	DrawMidText("Life : " + Hp + "\tScore : " + to_string(Score) + "\tName : " + Name, WIDTH, HEIGHT - 3);
	DrawMidText(to_string(StageNum) + "스테이지", WIDTH, HEIGHT - 2); 
}

void Interface::StoryDisplay()
{
	ifstream Load;
	Load.open("베네치아_스토리.txt");
	if (!Load.is_open())
	{
		system("cls");
		DrawMidText("플래이어 디폴트 파일이 없거나 손상되었습니다. 프로그램을 종료합니다.", 30, 30 * 0.5f);
		system("pause");
		exit(1);
	}
	else
	{
		string Story[5];
		int flag = 0;
		int ypos = HEIGHT * 0.3f;
		while (!Load.eof())
		{
			if (kbhit())
			{
				char ch = getch();
				if(ch == 's' || ch == 'S')
				return;

			}

			if (flag == 5)
			{
				for (int i = 1; i < 5; i++)
				{
					Story[i - 1] = Story[i];
				}
				getline(Load, Story[4]);
				ypos = HEIGHT * 0.3f;
				for (int i = 0; i < 5; i++)
				{
					EraseLine(ypos);
					DrawMidText(Story[i], WIDTH, ypos);
					ypos++;
				}
			}
			else
			{
				getline(Load, Story[flag]);
				DrawMidText(Story[flag], WIDTH, ypos);
				flag++;
				ypos++;
			}
			Sleep(500); //시간 계 함수로 바꾸기
		}	
	}
	getch();
}

string Interface::NameSet()
{
	system("cls");
	BoxDraw(0, 0, WIDTH, HEIGHT - 5);
	BoxDraw(WIDTH, (HEIGHT - 15), 15, 5);
	DrawMidText("이름입력 : ", WIDTH, HEIGHT*0.5f);
	string Tmp;
	cin >> Tmp;
	return Tmp;
}

Interface::~Interface()
{
}
