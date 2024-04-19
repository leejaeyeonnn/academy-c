#pragma once
#include <stdio.h>
#include <windows.h>
#include "player1.h"
#include "keyboard.h"
#include <time.h>  

typedef struct ai
{
	srand(time(NULL)); // 난수 랜덤화    
	int ax = rand() % 19;
	int ay = rand() % 19;
}

int main()
{
	
	if ( ) //만약 좌표가 2라면  
	{
		printf("컴퓨터의 중복수입니다. 잠시 기다려주세요.\n");

	}
	else
	{

	}
	system("cls");
}

