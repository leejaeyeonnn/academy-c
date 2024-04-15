#pragma once
#include <windows.h>

typedef struct Character //이름을 재정의하겠다
{
	int x, y;
	const char* shape;

}Character;   //이랗게 하면 호출할 때 굳이 스트럭트를 적지 않아도 된다. 

void GotoXY(int x, int y)
{
	COORD position = { x, y };  
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	
}
