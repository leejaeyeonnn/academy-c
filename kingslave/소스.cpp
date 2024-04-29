
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//좌표 설정
#include <conio.h>//입력
#include <string.h>//입력 문자열 처리
#include <time.h>
#include "people.h"

//왕, 노예, 시민 그림 텍스트
//돌아가면서 먼저 1.왕 2.시민.3.노예 중에 뭘 낼지 고른다
//상대가 뒤집은 카드 하나를 프린트 후, 랜덤으로 나타낸다 

#define WIDTH 18
#define HEIGHT 18
char maze[WIDTH][HEIGHT];



void map()
{

	strcpy(maze[1], "1111111111111111");
	strcpy(maze[2], "1000000000000001");
	strcpy(maze[3], "1000000000000001");
	strcpy(maze[4], "1000000000000001");
	strcpy(maze[5], "1000000000000001");
	strcpy(maze[6], "1000000000000001");
	strcpy(maze[7], "1000000000000001");
	strcpy(maze[8], "1000000000000001");
	strcpy(maze[9], "1000000000000001");
	strcpy(maze[10], "1000000000000001");
	strcpy(maze[11], "1000000000000001");
	strcpy(maze[12], "1000000000000001");
	strcpy(maze[13], "1000000000000001");
	strcpy(maze[14], "1000000000000001");
	strcpy(maze[15], "1000000000000001");
	strcpy(maze[16], "1111111111111111");
}

void draw_map()
{
	for (int i = 0; i< 18; i++)
	{
		for (int j = 0; j < 18; i++)
		{
			if (maze[i][j] == '1')
			{
				printf("▦");
			}
			else if (maze[i][j] == '0')
			{
				printf("%d", King.shape);
			}
		}
	}
}
