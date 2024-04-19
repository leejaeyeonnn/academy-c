#pragma once
#include <windows.h>

typedef struct player1 //이름을 재정의 한다
{
	int x, y;
	const char* shape;

} player1;

void GotoXY(int x, int y)
{
	COORD position = { x, y }; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}