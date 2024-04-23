//1. 맵 만들기 9완
//2. 승리 조건 만들기 
//3. 키보드 입력 만들기 
//4. 턴제로 바둑돌을 프린트함





#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//좌표 설정
#include <conio.h>//입력
#include <string.h>//입력 문자열 처리
#include <time.h>

#include "player.h" 
#include "keyboard.h"

#define WIDTH 18
#define HEIGHT 18

char maze[WIDTH][HEIGHT];
char bwin = 0, wwin = 0;
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
				printf(" ┼");
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

	void winchk(void)
	{
		int fullcount = 0;
		int i, j;

		bwin = 0;
		wwin = 0;

		for (j = 1; j < HEIGHT + 1; j++) // 오목판 꽉참
		{
			for (i = 1; i < WIDTH + 1; i++)
			{
				if (maze[j][i] != 0) fullcount++; 
			}
		}

		if (fullcount == WIDTH * HEIGHT)
		{
			bwin = 99;
			wwin = 99;
		}

		for (j = 1; j < HEIGHT + 1; j++) // ㅡ 모양 오목 
		{
			for (i = 1; i < WIDTH - 3; i++)
			{
				if (maze[j][i] == 1
					&& maze[j][i + 1] == 1
					&& maze[j][i + 2] == 1
					&& maze[j][i + 3] == 1
					&& maze[j][i + 4] == 1

					&& maze[j][i - 1] != 1
					&& maze[j][i + 5] != 1) bwin = 1;

				else if (maze[j][i] == 2
					&& maze[j][i + 1] == 2
					&& maze[j][i + 2] == 2
					&& maze[j][i + 3] == 2
					&& maze[j][i + 4] == 2

					&&maze[j][i - 1] != 2
					&&maze[j][i + 5] != 2) wwin = 1;
			}
		}

		for (i = 1; i < WIDTH + 1; i++) // ㅣ 모양 오목
		{
			for (j = 1; j < HEIGHT - 3; j++)
			{
				if (maze[j][i] == 1
					&& maze[j + 1][i] == 1
					&& maze[j + 2][i] == 1
					&& maze[j + 3][i] == 1
					&& maze[j + 4][i] == 1

					&& maze[j - 1][i] != 1
					&& maze[j + 5][i] != 1) bwin = 1;

				else if (maze[j][i] == 2
					&& maze[j + 1][i] == 2
					&& maze[j + 2][i] == 2
					&& maze[j + 3][i] == 2
					&& maze[j + 4][i] == 2

					&& maze[j - 1][i] != 2
					&& maze[j + 5][i] != 2) wwin = 1;
			}
		}

		for (j = 1; j < HEIGHT - 3; j++) // ＼ 모양 오목
		{
			for (i = 1; i < WIDTH - 3; i++)
			{
				if (maze[j][i] == 1
					&& maze[j + 1][i + 1] == 1
					&& maze[j + 2][i + 2] == 1
					&& maze[j + 3][i + 3] == 1
					&& maze[j + 4][i + 4] == 1
					   
					&& maze[j - 1][i - 1] != 1
					&& maze[j + 5][i + 5] != 1) bwin = 1;

				else if (maze[j][i] == 2
					&& maze[j + 1][i + 1] == 2
					&& maze[j + 2][i + 2] == 2
					&& maze[j + 3][i + 3] == 2
					&& maze[j + 4][i + 4] == 2
					   
					&& maze[j - 1][i - 1] != 2
					&& maze[j + 5][i + 5] != 2) wwin = 1;
			}
		}

		for (i = 1; i < WIDTH - 3; i++) // / 모양 오목
		{
			for (j = 5; j < HEIGHT + 1; j++)
			{
				if (maze[j][i] == 1
					&&maze[j - 1][i + 1] == 1
					&&maze[j - 2][i + 2] == 1
					&&maze[j - 3][i + 3] == 1
					&&maze[j - 4][i + 4] == 1
					  
					&&maze[j - 5][i + 5] != 1
					&&maze[j + 1][i - 1] != 1) bwin = 1;

				else if (maze[j][i] == 2
					&& maze[j - 1][i + 1] == 2
					&& maze[j - 2][i + 2] == 2
					&& maze[j - 3][i + 3] == 2
					&& maze[j - 4][i + 4] == 2

					&& maze[j - 5][i + 5] != 2
					&& maze[j + 1][i - 1] != 2) wwin = 1;
			}
		}
	}



int main()
{


	printf("오목의 룰:\n1. 16x16 크기의 바둑 판에 돌아가면서 바둑 알을 하나씩 놓습니다.\n");
	printf("2.자신의 바둑 색이 대각선 혹은 일자로 5개가 연속적으로 배치되어 있다면 승리입니다.\n");
	
	player1 player1 = {17, 9, "●"}; 
	player2 player2 = { 19, 9, "○" };
	map();

	while (1)
	{

		drawmap();  
		Input(&player1, &player2);  
		GotoXY(player1.x, player1.y);
		printf("%s", player1.shape);  
		gotoxy(player2.px, player2.py);   
		printf("%s", player2.shape);		 


		Sleep(20); 
		system("cls");
	}

	return 0;

}