#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define UP 72
#define LEFT 75
#define DOWN 80
#define RIGHT 77
#define SPACE 32
#define ENTER 13
#define X 0
#define Y 1

#define WIDTH 15 // 오목판 가로 사이즈
#define HEIGHT 15 // 오목판 세로 사이즈

char turn = 0,
bwin = 0,
wwin = 0;
int chk = 0;
int board[WIDTH + 2][HEIGHT + 2] = { 0 };
int cursor[2] = { WIDTH / 2, HEIGHT / 2 };

void draw_board(void); // 오목칸 그리기 함수
void winchk(void); // 승리 판정 함수
void move_cursor(void); // 키 입력 - 커서 이동
void reset_quit(void); // 키 입력 - 커서 이동, 재시작, 종료
void clear_board(void); // 초기화

int main(void)
{
	while (1)
	{
		if (chk == 1) clear_board();
		draw_board();
		winchk();
		if (bwin > 0 || wwin > 0) // 판정
		{
			while (chk == 0)
			{
				cursor[X] = 99;
				draw_board();
				if (wwin == 99 && bwin == 99) printf("　◎ 승부가 나지 않았습니다.\n\n");

				else if (turn == 1) printf("　○ 흑의 승리! ○\n\n");
				else printf("　● 백의 승리! ●\n\n");
				printf("　(다시 시작 : r, R)\n　(종료 　　 : q, Q)\n");

				reset_quit();
				if (chk > 0) break;
			}
			clear_board();
			draw_board();
		}
		if (chk == 2) break; // 종료 시 반복문 밖으로 탈출
		chk = 0;

		if (turn == 0) printf("　○ 흑의 차례 ○\n\n");
		else printf("　● 백의 차례 ●\n\n");
		printf("　(다시 시작 : r, R)\n　(종료 　　 : q, Q)\n");
		move_cursor();
	}
	return 0;
}

/* 칸 사이의 공백이 없는 오목판 */
void draw_board(void)
{
	int bx, by, i;

	system("cls");
	for (by = 1; by <= HEIGHT; by++)
	{
		printf("　");
		for (bx = 1; bx <= WIDTH; bx++)
		{
			if (cursor[X] == bx && cursor[Y] == by) // 커서 표시
			{
				if (by != 1 && by != HEIGHT) 
				{
					switch (board[by][bx])
					{
					case 0:
						printf("▒");
						break;
					case 1:
						printf("□");
						break;
					case 2:
						printf("■");
						break;
					}
				}
				else if (by == HEIGHT) 
				{ 
					switch (board[by][bx])
					{ 
					case 0:
						printf("▒");
						break;
					case 1:
						printf("□");
						break;
					case 2:
						printf("■");
						break;
					}
				}
				else 
				{
					switch (board[by][bx])
					{
					case 0:
						printf("▒");
						break;
					case 1:
						printf("□");
						break;
					case 2:
						printf("■");
						break;
					}
				}
			}
			else 
			{
				if (by != 1 && by != HEIGHT) 
				{
					switch (board[by][bx]) // 오목알 표시
					{
					case 0:
						if (bx == 1) printf("┠");
						else if (bx == WIDTH)  printf("┨"); 
						else printf("┼");
						break;
					case 1:
						printf("○");
						break;
					case 2:
						printf("●");
						break;
					}
				}
				else if (by == HEIGHT) {
					switch (board[by][bx])
					{
					case 0:
						if (bx == 1) printf("┗");
						else if (bx == WIDTH)  printf("┛"); 
						else printf("┷");
						break;
					case 1:
						printf("○");
						break;
					case 2:
						printf("●");
						break;
					}
				}
				else {
					switch (board[by][bx])
					{
					case 0:
						if (bx == 1) printf("┏");
						else if (bx == WIDTH)  printf("┓"); 
						else printf("┯");
						break;
					case 1:
						printf("○");
						break;
					case 2:
						printf("●");
						break;
					}
				}
			}
		}
		printf("\n");
	}
}
//*/

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
			if (board[j][i] != 0) fullcount++;
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
			if (board[j][i] == 1
				&& board[j][i + 1] == 1
				&& board[j][i + 2] == 1
				&& board[j][i + 3] == 1
				&& board[j][i + 4] == 1

				&& board[j][i - 1] != 1
				&& board[j][i + 5] != 1) bwin = 1;

			else if (board[j][i] == 2
				&& board[j][i + 1] == 2
				&& board[j][i + 2] == 2
				&& board[j][i + 3] == 2
				&& board[j][i + 4] == 2

				&& board[j][i - 1] != 2
				&& board[j][i + 5] != 2) wwin = 1;
		}
	}

	for (i = 1; i < WIDTH + 1; i++) // ㅣ 모양 오목
	{
		for (j = 1; j < HEIGHT - 3; j++)
		{
			if (board[j][i] == 1
				&& board[j + 1][i] == 1
				&& board[j + 2][i] == 1
				&& board[j + 3][i] == 1
				&& board[j + 4][i] == 1

				&& board[j - 1][i] != 1
				&& board[j + 5][i] != 1) bwin = 1;

			else if (board[j][i] == 2
				&& board[j + 1][i] == 2
				&& board[j + 2][i] == 2
				&& board[j + 3][i] == 2
				&& board[j + 4][i] == 2

				&& board[j - 1][i] != 2
				&& board[j + 5][i] != 2) wwin = 1;
		}
	}

	for (j = 1; j < HEIGHT - 3; j++) // ＼ 모양 오목
	{
		for (i = 1; i < WIDTH - 3; i++)
		{
			if (board[j][i] == 1
				&& board[j + 1][i + 1] == 1
				&& board[j + 2][i + 2] == 1
				&& board[j + 3][i + 3] == 1
				&& board[j + 4][i + 4] == 1

				&& board[j - 1][i - 1] != 1
				&& board[j + 5][i + 5] != 1) bwin = 1;

			else if (board[j][i] == 2
				&& board[j + 1][i + 1] == 2
				&& board[j + 2][i + 2] == 2
				&& board[j + 3][i + 3] == 2
				&& board[j + 4][i + 4] == 2

				&& board[j - 1][i - 1] != 2
				&& board[j + 5][i + 5] != 2) wwin = 1;
		}
	}

	for (i = 1; i < WIDTH - 3; i++) // / 모양 오목
	{
		for (j = 5; j < HEIGHT + 1; j++)
		{
			if (board[j][i] == 1
				&& board[j - 1][i + 1] == 1
				&& board[j - 2][i + 2] == 1
				&& board[j - 3][i + 3] == 1
				&& board[j - 4][i + 4] == 1

				&& board[j - 5][i + 5] != 1
				&& board[j + 1][i - 1] != 1) bwin = 1;

			else if (board[j][i] == 2
				&& board[j - 1][i + 1] == 2
				&& board[j - 2][i + 2] == 2
				&& board[j - 3][i + 3] == 2
				&& board[j - 4][i + 4] == 2

				&& board[j - 5][i + 5] != 2
				&& board[j + 1][i - 1] != 2) wwin = 1;
		}
	}
}

void move_cursor(void)
{
	char ch;

	ch = _getch();
	switch (ch) // 화살표키 인식
	{
	case UP: // 상
		if (cursor[Y] != 1) cursor[Y]--;
		else cursor[Y] = HEIGHT;
		break;
	case LEFT: // 좌
		if (cursor[X] != 1) cursor[X]--;
		else cursor[X] = WIDTH;
		break;
	case RIGHT: // 우
		if (cursor[X] != WIDTH) cursor[X]++;
		else cursor[X] = 1;
		break;
	case DOWN: // 하			
		if (cursor[Y] != HEIGHT) cursor[Y]++;
		else cursor[Y] = 1;
		break;
	case ENTER:
		if (turn == 0 && board[cursor[Y]][cursor[X]] == 0)
		{
			board[cursor[Y]][cursor[X]] = 1;
			turn = 1;
		}
		else if (turn == 1 && board[cursor[Y]][cursor[X]] == 0)
		{
			board[cursor[Y]][cursor[X]] = 2;
			turn = 0;
		}
		break;
	case SPACE:
		if (turn == 0 && board[cursor[Y]][cursor[X]] == 0)
		{
			board[cursor[Y]][cursor[X]] = 1;
			turn = 1;
		}
		else if (turn == 1 && board[cursor[Y]][cursor[X]] == 0)
		{
			board[cursor[Y]][cursor[X]] = 2;
			turn = 0;
		}
		break;
	case 'r':
		chk = 1;
		break;
	case 'R':
		chk = 1;
		break;
	case 'q':
		chk = 2;
		break;
	case 'Q':
		chk = 2;
		break;
	default:
		chk = 0;
		break;
	}
}

void reset_quit(void)
{
	char ch;

	ch = _getch();
	switch (ch) // 재시작, 종료 여부
	{
	case 'r':
		chk = 1;
		break;
	case 'R':
		chk = 1;
		break;
	case 'q':
		chk = 2;
		break;
	case 'Q':
		chk = 2;
		break;
	default:
		chk = 0;
		break;
	}
}

void clear_board(void)
{
	int i, j;

	turn = 0;
	wwin = 0;
	bwin = 0;
	cursor[X] = WIDTH / 2;
	cursor[Y] = HEIGHT / 2;
	for (i = 1; i < WIDTH; i++)
	{
		for (j = 1; j < HEIGHT; j++) board[j][i] = 0;
	}
}