#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int width = 100;
int height = 30;

int random = 0;

typedef struct Star
{
	int x;
	int y;
	const char* shape;
}Star;

HANDLE screen[2]; // ���۸� �����մϴ�.
// screen[0] front buffer
// screen[1] back buffer

// HANDLE �ε����� �����ؼ� ���۸� ��ü��Ű�� ����
int screenIndex = 0;

void GotoXY(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

// ���۸� �ʱ�ȭ�ϴ� �Լ�
void InitializeScreen()
{
	CONSOLE_CURSOR_INFO cursor;

	// ������ ���� ������, ���� ������
	COORD size = { width, height };

	// left, top, right, bottom
	SMALL_RECT rect = { 0, 0, width - 1, height - 1 };

	// front buffer�� �����մϴ�.
	screen[0] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE, // �б�, ����
		0,                            // �������
		NULL,                         // ���ȼӼ�
		CONSOLE_TEXTMODE_BUFFER,      // ���۸��
		NULL	                      // ���ȼӼ�
	);

	// ������ ����� �����մϴ�.
	SetConsoleScreenBufferSize(screen[0], size);

	// ������ ��ġ�� �����մϴ�.
	SetConsoleWindowInfo(screen[0], TRUE, &rect); // TRUE : ������ ��ġ�� �����մϴ�.

	// back buffer�� �����մϴ�.
	screen[1] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE, // �б�, ����
		0,                            // �������
		NULL,                         // ���ȼӼ�
		CONSOLE_TEXTMODE_BUFFER,      // ���۸��
		NULL	                      // ���ȼӼ�
	);

	// ������ ����� �����մϴ�.
	SetConsoleScreenBufferSize(screen[1], size);

	// ������ ��ġ�� �����մϴ�.
	SetConsoleWindowInfo(screen[1], TRUE, &rect); // TRUE : ������ ��ġ�� �����մϴ�.

	// Ŀ���� Ȱ��ȭ ����
	// false : Ŀ���� ����ϴ�.
	// true  : Ŀ���� ���Դϴ�.

	cursor.bVisible = FALSE;

	SetConsoleCursorInfo(screen[0], &cursor);
	SetConsoleCursorInfo(screen[1], &cursor);
}

// ���۸� ��ü�ϴ� �Լ�
void FlipScreen()
{
	// ���۸� �ϳ��� Ȱ��ȭ��ų �� �ִ� �Լ�
	SetConsoleActiveScreenBuffer(screen[screenIndex]);

	screenIndex = !screenIndex;
}

// ��ü�� ���۸� �����ִ� �Լ�
void ClearScreen()
{
	COORD position = { 0,0 };

	DWORD written;

	FillConsoleOutputCharacter // ȭ�鿡 ���ڸ� �׷��ִ� �Լ�
	(
		screen[screenIndex], // ȭ�� ����
		' ', 				 // ȭ�鿡 �׷��� ����
		width * height,		 //	ȭ�鿡 �׷��� ������ ����
		position, 			 // ȭ�鿡 �׷��� ������ ��ġ
		&written			 // ������ ����
	);
}

// ���۸� �����ϴ� �Լ�
void ReleaseScreen()
{
	CloseHandle(screen[0]); // ���۸� �����մϴ�.
	CloseHandle(screen[1]);
}

// ���۸� ����ϴ� �Լ�
void DrawScreen(int x, int y, const char* string)
{
	COORD position = { x, y };

	DWORD written;

	SetConsoleCursorPosition
	(
		screen[screenIndex],
		position
	); // ������ ��ġ�� �����մϴ�.

	WriteFile // ���ۿ� ���ڿ��� ����ϴ� �Լ�
	(
		screen[screenIndex],  // ����
		string,				  // ���ڿ�
		strlen(string),		  // ���ڿ��� ����
		&written,			  // ���ڿ��� ����
		NULL				  // ���ȼӼ�
	); // ���ۿ� ���ڿ��� ����մϴ�.
}

void AutoMove(Star* star)
{
	static int count = 0;

	count += 1;

	if (count % 5 == 0)
	{
		random = rand() % 4;
	}

	switch (random)
	{
	case 0:
		if (star->y > 0)
			star->y--;
		break;
	case 1:
		if (star->x >0)
		{
			star->x -= 2;
		}
		break;
	case 2:
		if (star->x< 98)
		{
			star->x += 2;
		}
		break;
	case 3: 
		if (star->y< 29)
		{
			star->y++;
		}
		break;
	}

}

int main()
{
	// 1. ���۸� �ʱ�ȭ�մϴ�.
	InitializeScreen();

	srand(time(NULL));

	Star star = { 10, 10, "��" };

	random = rand() % 4;

	while (1)
	{
		AutoMove(&star);

		DrawScreen(star.x, star.y, star.shape);

		Sleep(100);

		// 2. ���۸� ��ü�մϴ�.
		FlipScreen();

		// 3. ��ü�� ������ ������ �����մϴ�.
		ClearScreen();
	}

	// 4. ���۸� �����մϴ�.
	ReleaseScreen();

	return 0;
}


