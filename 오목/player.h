#pragma once
#include <windows.h>

typedef struct player1 //이름을 재정의 한다
{
	int x, y;
	const char* shape;

} player1;

typedef struct player2
{
	int px, py;
	const char* shape;
} player2;

void GotoXY(int x, int y)
{
	COORD position = { x, y }; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void gotoxy(int px, int py)
{
	COORD position = { px, py };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}