#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<fstream>
#include<time.h>
#include<crtdbg.h>
using namespace std;

#define WIDTH 50
#define HEIGHT 40
#define BACKSPACE 8

enum MAXIMUMWORDCREATE
{
	MAXIMUMWORDCREATE_START = 5,
	MAXIMUMWORDCREATE_STAGE1 = 5,
	MAXIMUMWORDCREATE_STAGE2,
	MAXIMUMWORDCREATE_STAGE3,
	MAXIMUMWORDCREATE_STAGE4,
	MAXIMUMWORDCREATE_STAGE5,
	MAXIMUMWORDCREATE_LAST

};
//
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//색상 지정
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
//

enum ITEMLIST
{
	ITEMLIST_START,
	ITEMLIST_DISPLAYCLEAR,
	ITEMLIST_SPEEDDOWN,
	ITEMLIST_SPEEDUP,
	ITEMLIST_WORDBLACKOUT,
	ITEMLIST_WORDSTOP,
	ITEMLIST_END
};