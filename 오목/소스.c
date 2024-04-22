#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//좌표 설정
#include <conio.h>//입력
#include <string.h>//입력 문자열 처리
#include <time.h>

#include "player1.h" 
#include "keyboard.h"


#define WIDTH 18
#define HEIGHT 18

char maze[WIDTH][HEIGHT];
 
void map()
{
	 
	strcpy(maze[1], "1000000000000003");
	strcpy(maze[2], "1000000000000003"); 
	strcpy(maze[3], "1000000000000003"); 
	strcpy(maze[4], "1000000000000003");
	strcpy(maze[5], "1000000000000003");
	strcpy(maze[6], "1000000000000003");
	strcpy(maze[7], "1000000000000003");
	strcpy(maze[8], "1000000000000003");
	strcpy(maze[9], "1000000000000003");
	strcpy(maze[10], "1000000000000003");
	strcpy(maze[11], "1000000000000003");
	strcpy(maze[12], "1000000000000003");
	strcpy(maze[13], "1000000000000003");
	strcpy(maze[14], "1000000000000003");
	strcpy(maze[15], "1000000000000003");
	strcpy(maze[16], "1000000000000003");
	

}

void drawmap()
{
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			if (maze[i][j] == '0')
			{
				printf(" ┼ ");
			}
			else if (maze[i][j] == '1')
			{
				printf("┠ ");
			}
			else if (maze[i][j] == '2')
			{
				printf(" ┯ ");
			}
			else if (maze[i][j] == '3')
			{
				printf(" ┨");
			}
			else if (maze[i][j] == '4')
			{
				printf("┷");
			}
		}

		printf("\n");
	}

	
}

void winner()
{
	
}



int main()
{


	printf("오목의 룰:\n1. 16x16 크기의 바둑 판에 돌아가면서 바둑 알을 하나씩 놓습니다.\n");
	printf("2.자신의 바둑 색이 대각선 혹은 일자로 5개가 연속적으로 배치되어 있다면 승리입니다.\n");
	
	player1 player1 = {17, 9, "●"};
	map();

	while (1)
	{
		drawmap();  
		Input(maze, &player1); 
		GotoXY(player1.x, player1.y);
		printf("%s", player1.shape); 
		//player.shape가 프린트됐다면 
		 


		Sleep(20); 
		system("cls");
	}

	return 0;

}