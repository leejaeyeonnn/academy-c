#pragma once
#include <windows.h>

typedef struct Character //�̸��� �������ϰڴ�
{
	int x, y;
	const char* shape;

}Character;   //�̶��� �ϸ� ȣ���� �� ���� ��Ʈ��Ʈ�� ���� �ʾƵ� �ȴ�. 

void GotoXY(int x, int y)
{
	COORD position = { x, y };  
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	
}
