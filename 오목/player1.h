#pragma once
#include <windows.h>
typedef struct player1 //�̸��� ������ �Ѵ�

{
	int x, y;
	const char* shape;

} player1;

void GotoXY(int x, int y)
{
	COORD positon = { x, y }; 

}