#pragma once
#include "player1.h"
#include <stdio.h>
#include <conio.h>


#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ENTER 13

#define WIDTH 19
#define HEIGHT 19


void Input(char maze[WIDTH][HEIGHT], player1*player1)
{
	if (_kbhit()) //키보드 입력이 확인됐다면
	{
		char key = _getch();//키보드 입력을 받습니다.

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
					
		}
	}
}
