#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

void GotoXY(int x, int y)
{
	//x��� y�� ��ǥ ����

	//COORD position = { x, y };
	//
	////Ŀ�� �̵� �Լ�
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	// 
	//GetStdHandel (STD_OUTPUT_HANDLE): ǥ�� ��� �ڵ��� �����ɴϴ�.
	//SetConsoleCursorPosition: �ܼ�â�� Ŀ���� �̵��մϴ�.

}

int main()
{
	//char key = 0;
	//
	//int x = 2;
	//int y = 5;
	//
	//GotoXY(x, y);
	//printf("��"); 
   
	
	//while (1)
	//{ 
	//	
	//	if (_kbhit())//Ű���� �Է��� �ִ���Ȯ��
	//	{
	//	
	//		key = _getch(); //Ű���� �Է�
	//		system("cls");
	//
	//		if (key == -32)
	//		{
	//			key = _getch();  
	//		}
	//
	//		switch (key)
	//		{
	//		case UP: 
	//			if (y > 0)
	//			{
	//				y--;
	//			}
	//			break;
	//		case LEFT: 
	//			if (x > 0)
	//			{
	//				x -= 2;
	//			}
	//			break;
	//
	//		case RIGHT: 
	//			if (x < 99)
	//			{
	//				x += 2;
	//			}
	//			break;
	//		case DOWN: 
	//			if (y < 29)
	//			{
	//				y++;
	//			}
	//			break;
	//		}
	//		
	//		GotoXY(x, y);
	//		printf("��");
	//
	//
	//	}
	//	
	//}
	//
	
	return 0;
}