#include <stdio.h> // 기본 입출력
#include <windows.h> // 좌표 설정
#include <conio.h> // 입력
#include <string.h> // 입력 문자열 처리

#define MAX_N 19 // 바둑(오목)판의 크기
#define DRAW_BLACK printf("○") // 검은 돌 출력 (cmd에서는 색반전이기 때문)
#define DRAW_WHITE printf("●") // 하얀 돌 출력
#define BLACK 1 // 검은 돌 정의
#define WHITE 2 //  




void drawInit() 
{
	gotoxy(0, 0);
	for (int i = 0; i < MAX_N; i++) 
	{
		for (int j = 0; j < MAX_N; j++)
		{
			gotoxy(j, i);
			if (i == 0) 
			{
				if (j == 0)
					printf("┌");
				else if (j == MAX_N - 1)
					printf("┐");
				else
					printf("┬");
			}
			else if (j == 0) {
				if (i == MAX_N - 1)
					printf("└");
				else
					printf("├");
			}
			else if (j == MAX_N - 1) 
			{
				if (i == MAX_N - 1)
					printf("┘");
				else
					printf("┤");
			}
			else if (i == MAX_N - 1) {
				printf("┴");
			}
			else
				printf("┼");
		}
		printf("\n");
	}
	for (int i = 0; i < MAX_N; i++) {
		gotoxy(MAX_N, i);
		printf("%d", i + 1);
		gotoxy(i, MAX_N);
		printf("%c", i + 'A');
	}
	gotoInput();
	
}

int main()
{
	
}