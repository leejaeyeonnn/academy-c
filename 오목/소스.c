#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <windows.h>//��ǥ ����
#include <conio.h>//�Է�
#include <string.h>//�Է� ���ڿ� ó��
#include <time.h>

#include "player1.h" 
#include "keyboard.h"
#include "ai.h"

#define WIDTH 19
#define HEIGHT 19

char maze[WIDTH][HEIGHT];
 
void map()
{
	strcpy(maze[0], "111111111111111111");    
	strcpy(maze[1], "100000000000000001");
	strcpy(maze[2], "100000000000000001"); 
	strcpy(maze[3], "100000000000000001"); 
	strcpy(maze[4], "100000000000000001");
	strcpy(maze[5], "100000000000000001");
	strcpy(maze[6], "100000000000000001");
	strcpy(maze[7], "100000000000000001");
	strcpy(maze[8], "100000000000000001");
	strcpy(maze[9], "100000000000000001");
	strcpy(maze[10], "100000000000000001");
	strcpy(maze[11], "100000000000000001");
	strcpy(maze[12], "100000000000000001");
	strcpy(maze[13], "100000000000000001");
	strcpy(maze[14], "100000000000000001");
	strcpy(maze[15], "100000000000000001");
	strcpy(maze[16], "100000000000000001");
	strcpy(maze[17], "111111111111111111");

}

void draw()
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (maze[i][j] == '0')
			{
				printf("  ");
			}
			else if (maze[i][j] == '1')
			{
				printf("��");
			}
		}

		printf("\n");
	}

	
}





int main()
{


	printf("������ ��:\n1. 16x16 ũ���� �ٵ� �ǿ� ���ư��鼭 �ٵ� ���� �ϳ��� �����ϴ�.\n");
	printf("2.�ڽ��� �ٵ� ���� �밢�� Ȥ�� ���ڷ� 5���� ���������� ��ġ�Ǿ� �ִٸ� �¸��Դϴ�.\n");
	
	player1 player1 = {16, 9, "��"};
	map();

	while (1)
	{
		draw();
		GotoXY(player1.x, player1.y);
		printf("%s", player1.shape); 
		//player.shape�� ����Ʈ�ƴٸ� 
		Input(maze, &player1); 


		Sleep(50); 
		system("cls");
	}



}