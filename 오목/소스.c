#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//��ǥ ����
#include <conio.h>//�Է�
#include <string.h>//�Է� ���ڿ� ó��
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
				printf(" �� ");
			}
			else if (maze[i][j] == '1')
			{
				printf("�� ");
			}
			else if (maze[i][j] == '2')
			{
				printf(" �� ");
			}
			else if (maze[i][j] == '3')
			{
				printf(" ��");
			}
			else if (maze[i][j] == '4')
			{
				printf("��");
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


	printf("������ ��:\n1. 16x16 ũ���� �ٵ� �ǿ� ���ư��鼭 �ٵ� ���� �ϳ��� �����ϴ�.\n");
	printf("2.�ڽ��� �ٵ� ���� �밢�� Ȥ�� ���ڷ� 5���� ���������� ��ġ�Ǿ� �ִٸ� �¸��Դϴ�.\n");
	
	player1 player1 = {17, 9, "��"};
	map();

	while (1)
	{
		drawmap();  
		Input(maze, &player1); 
		GotoXY(player1.x, player1.y);
		printf("%s", player1.shape); 
		//player.shape�� ����Ʈ�ƴٸ� 
		 


		Sleep(20); 
		system("cls");
	}

	return 0;

}