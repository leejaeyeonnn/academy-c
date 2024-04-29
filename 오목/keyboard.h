#pragma once
#include "player.h"
#include <stdio.h>
#include <conio.h>



#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ENTER 13

#define WIDTH 18
#define HEIGHT 18

int cc = 0;

int aa=1;

void Input(char maze[WIDTH][HEIGHT], Player1*player1, Player2*player2)  
{
	for (int r = 0; r < WIDTH * HEIGHT; r++) 
	{
		if (_kbhit()) //키보드 입력이 확인됐다면
		{
			char key = _getch();//키보드 입력을 받습니다.
			if (aa = 1)
			{
				switch (key)
				{
				case 32:

					break;

				case UP:
					player1->y--;
					break;

				case LEFT:
					player1->x -= 2;
					break;

				case RIGHT:
					player1->x += 2;
					break;

				case DOWN:
					player1->y++;
					break;

				case ENTER:
					printf("%s", *player1->shape);

				}
			}


			if (aa == 0)
			{
				switch (key)
				{
				case UP:
					player2->py--;
					break;

				case LEFT:
					player2->px -= 2;
					break;

				case RIGHT:
					player2->px += 2;
					break;

				case DOWN:
					player2->py++;
					break;

	
				}
			}



		}
	}
}
