
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//��ǥ ����
#include <conio.h>//�Է�
#include <string.h>//�Է� ���ڿ� ó��
#include <time.h>
#include "people.h"

//��, �뿹, �ù� �׸� �ؽ�Ʈ
//���ư��鼭 ���� 1.�� 2.�ù�.3.�뿹 �߿� �� ���� ����
//��밡 ������ ī�� �ϳ��� ����Ʈ ��, �������� ��Ÿ���� 

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
				printf("��");
			}
			else if (maze[i][j] == '0')
			{
				printf("%d", King.shape);
			}
		}
	}
}
