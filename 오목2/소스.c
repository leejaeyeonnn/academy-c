#include <stdio.h> // �⺻ �����
#include <windows.h> // ��ǥ ����
#include <conio.h> // �Է�
#include <string.h> // �Է� ���ڿ� ó��

#define MAX_N 19 // �ٵ�(����)���� ũ��
#define DRAW_BLACK printf("��") // ���� �� ��� (cmd������ �������̱� ����)
#define DRAW_WHITE printf("��") // �Ͼ� �� ���
#define BLACK 1 // ���� �� ����
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
					printf("��");
				else if (j == MAX_N - 1)
					printf("��");
				else
					printf("��");
			}
			else if (j == 0) {
				if (i == MAX_N - 1)
					printf("��");
				else
					printf("��");
			}
			else if (j == MAX_N - 1) 
			{
				if (i == MAX_N - 1)
					printf("��");
				else
					printf("��");
			}
			else if (i == MAX_N - 1) {
				printf("��");
			}
			else
				printf("��");
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