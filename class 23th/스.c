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

HANDLE screen[2]; // 버퍼를 생성합니다.
// screen[0] front buffer
// screen[1] back buffer

// HANDLE 인덱스에 접근해서 버퍼를 교체시키는 변수
int screenIndex = 0;

void GotoXY(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

// 버퍼를 초기화하는 함수
void InitializeScreen()
{
	CONSOLE_CURSOR_INFO cursor;

	// 버퍼의 가로 사이즈, 세로 사이즈
	COORD size = { width, height };

	// left, top, right, bottom
	SMALL_RECT rect = { 0, 0, width - 1, height - 1 };

	// front buffer를 생성합니다.
	screen[0] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE, // 읽기, 쓰기
		0,                            // 공유모드
		NULL,                         // 보안속성
		CONSOLE_TEXTMODE_BUFFER,      // 버퍼모드
		NULL	                      // 보안속성
	);

	// 버퍼의 사이즈를 설정합니다.
	SetConsoleScreenBufferSize(screen[0], size);

	// 버퍼의 위치를 설정합니다.
	SetConsoleWindowInfo(screen[0], TRUE, &rect); // TRUE : 버퍼의 위치를 설정합니다.

	// back buffer를 생성합니다.
	screen[1] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE, // 읽기, 쓰기
		0,                            // 공유모드
		NULL,                         // 보안속성
		CONSOLE_TEXTMODE_BUFFER,      // 버퍼모드
		NULL	                      // 보안속성
	);

	// 버퍼의 사이즈를 설정합니다.
	SetConsoleScreenBufferSize(screen[1], size);

	// 버퍼의 위치를 설정합니다.
	SetConsoleWindowInfo(screen[1], TRUE, &rect); // TRUE : 버퍼의 위치를 설정합니다.

	// 커서의 활성화 여부
	// false : 커서를 숨깁니다.
	// true  : 커서를 보입니다.

	cursor.bVisible = FALSE;

	SetConsoleCursorInfo(screen[0], &cursor);
	SetConsoleCursorInfo(screen[1], &cursor);
}

// 버퍼를 교체하는 함수
void FlipScreen()
{
	// 버퍼를 하나만 활성화시킬 수 있는 함수
	SetConsoleActiveScreenBuffer(screen[screenIndex]);

	screenIndex = !screenIndex;
}

// 교체된 버퍼를 지워주는 함수
void ClearScreen()
{
	COORD position = { 0,0 };

	DWORD written;

	FillConsoleOutputCharacter // 화면에 문자를 그려주는 함수
	(
		screen[screenIndex], // 화면 버퍼
		' ', 				 // 화면에 그려질 문자
		width * height,		 //	화면에 그려질 문자의 개수
		position, 			 // 화면에 그려질 문자의 위치
		&written			 // 문자의 개수
	);
}

// 버퍼를 해제하는 함수
void ReleaseScreen()
{
	CloseHandle(screen[0]); // 버퍼를 해제합니다.
	CloseHandle(screen[1]);
}

// 버퍼를 출력하는 함수
void DrawScreen(int x, int y, const char* string)
{
	COORD position = { x, y };

	DWORD written;

	SetConsoleCursorPosition
	(
		screen[screenIndex],
		position
	); // 버퍼의 위치를 설정합니다.

	WriteFile // 버퍼에 문자열을 출력하는 함수
	(
		screen[screenIndex],  // 버퍼
		string,				  // 문자열
		strlen(string),		  // 문자열의 길이
		&written,			  // 문자열의 길이
		NULL				  // 보안속성
	); // 버퍼에 문자열을 출력합니다.
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
	// 1. 버퍼를 초기화합니다.
	InitializeScreen();

	srand(time(NULL));

	Star star = { 10, 10, "☆" };

	random = rand() % 4;

	while (1)
	{
		AutoMove(&star);

		DrawScreen(star.x, star.y, star.shape);

		Sleep(100);

		// 2. 버퍼를 교체합니다.
		FlipScreen();

		// 3. 교체된 버퍼의 내용을 삭제합니다.
		ClearScreen();
	}

	// 4. 버퍼를 해제합니다.
	ReleaseScreen();

	return 0;
}


