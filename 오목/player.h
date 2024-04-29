#pragma once
#include <windows.h>

typedef struct Player1 //�̸��� ������ �Ѵ�
{
	int x, y;
	const char* shape;

} Player1;

typedef struct Player2
{
	int px, py;
	const char* shape;
} Player2;

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
