#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "character.h"

#define WIDTH 11
#define HEIGHT 11


char maze[WIDTH][HEIGHT];

void  Initialize()
{
	strcpy(maze[0], "111000111");
	strcpy(maze[1], "110000001");
	strcpy(maze[2], "100100111");
	strcpy(maze[3], "101100001");
	strcpy(maze[4], "101110001");
	strcpy(maze[5], "111000001");
	strcpy(maze[6], "100011001");
	strcpy(maze[7], "100011001");
	strcpy(maze[8], "112211111");

}

void Renderer()
{

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (maze[i][j] == '0')
			{
				printf("  ");
			}
			else if (maze[i][j] == '1')
			{
				printf("¡á");
			}
			else if (maze[i][j] == '2')
			{
				printf("¡Ý");
			}
			

		}

		printf("\n"); 
	}
}

int  main()
{
	Character character = { 4, 1, "¡Ù" };
	Initialize();

	while (1)
	{
		Renderer();

		GotoXY(character.x, character.y);
		printf("%s", character.shape);

		system("cls"); 
	}

	

	return 0;



}