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
#define P1 1
#define P2 2 

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
 

void drawmap()
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
{
	int count = 0;
	while (map[hd.y][hd.x] == flag) 
	{
		count++;
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
	}
	return count;
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
				if (turn == P1)
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
	
	int turn = P1;
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

					if (turn == P1)
					{
						map[hd.y][hd.x] = P1;
						printf("●");
						checkstone(hd, map, turn);
						turn = P2;
					}
					else
					{
						map[hd.y][hd.x] = P2;
						printf("○");
						checkstone(hd, map, turn);
						turn = P1;
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
	drawmap();
	startgame(map);

}


