#define _CRT_SECURE_NO_WARNINGS  

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define WIDTH 19
#define HEIGHT 19
#define ESC 27
#define U1 1
#define U2 2

typedef struct XY
{
	int x;
	int y;
}XY;


void gotoxy(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
 

void initGame()
{
	
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int k = 0; k < WIDTH; k++)
		{
			if (i == 0)
			{
				if (k == 0)
					printf("┌");
				else if (k + 1 == WIDTH)
					printf( " ┐");
				else
					printf(" ┬");
			}

			else if (i + 1 < HEIGHT)
			{
				if (k == 0)
					printf("├");
				else if (k + 1 == WIDTH)
					printf(" ┤");
				else
					printf(" ┼");
			}
			else
			{
				if (k == 0)
				{
					printf("└");
				}
				else if (k + 1 == WIDTH)
				{
					printf(" ┘");
				}
				else if(k == 0)
				{
						printf("└");
				}
				else
				{
					printf(" ┴");
				}

			}
			
		}
		printf("\n"); 
	}

}

int searchstone(XY hd, int map[HEIGHT][WIDTH], int flag, int p, int sw) 
//flag는 돌을 나타내는 값. //p는 이동방향을 나타내는 변수0 
// 0은 위쪽 1은 오른쪽 2 대각선오른쪽아래 3대각선오른쪽 위 
//sw는 이동 거리를 나타내는 변수 
{
	if (map[hd.y][hd.x] != flag)
	{
		return 0;
	}
	if (p == 0)
	{
		hd.y += sw;
	}
	else if (p == 1)
	{
		hd.x += sw;
	}
	else if (p == 2)
	{
		hd.x += sw;
		hd.y += sw;
	}
	else
	{
		hd.x += sw;
		hd.y -= sw;
	}
	return 1 + searchstone(hd, map, flag, p, sw);
	//돌을 찾을 때마다 1을 반환한다

}

void checkstone(XY hd, int map[HEIGHT][WIDTH], int turn)
{
	int i = 0, countstone = 0;
	for (i = 0; i < 4; i++)
	{
		countstone = 0;
		countstone += searchstone(hd, map, turn, i, 1);
		countstone += searchstone(hd, map, turn, i, -1);
		if (countstone == 6)
		{
			gotoxy(0, HEIGHT);
				if (turn == U1)
				{
					printf("사용자 1");
					
				}
				else
				{
					printf("사용자 2");
				}
				printf("님이 승리하였습니다.");
				_getch();
				exit(1);
		}
	}
}

void startgame(int map[HEIGHT][WIDTH])
{
	
	int turn = U1;
	XY hd = { WIDTH / 2,HEIGHT / 2 };
	while (1)
	{
		if (_kbhit())
		{
			char key= _getch();  
			switch (key)  
			{
			case LEFT: 
				if (hd.x > 0)
				{
					hd.x -= 1;
					break;
				}

			case RIGHT:
				if (hd.x < WIDTH - 1)
				{
					hd.x += 1;
					break;
				}
			case UP:
				if (hd.y > 0)
				{
					hd.y -= 1;
					break;
				}
			case DOWN:
				if (hd.y < HEIGHT - 1)
				{
					hd.y += 1;
					break;
				}
			case SPACE:
				if (map[hd.y][hd.x] == 0)
				{
					gotoxy(hd.x * 2, hd.y);

					if (turn == U1)
					{
						map[hd.y][hd.x] = U1;
						printf("●");
						checkstone(hd, map, turn);
						turn = U2;
					}
					else
					{
						map[hd.y][hd.x] = U2;
						printf("○");
						checkstone(hd, map, turn);
						turn = U1;
					}
				}

				break;
			case ESC:
				exit(1);
				break;
			}
			gotoxy(hd.x * 2, hd.y);
		}
	}
}
int main()
{
	int map[HEIGHT][WIDTH] = { 0, };
	printf("2인용 턴제 오목 게임\n");
	printf("종료하려면 ESC를 누르십시오.\n");

	printf("게임을 시작하시려면 아무키나 누르십시오");

	_getch();
	system("cls");
	initGame();
	startgame(map);

}


