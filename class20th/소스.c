#include <stdio.h>

#define SIZE 9000

void Load(const char* name)
{

	FILE* load = fopen(name, "r");
	char rabbit[SIZE] = { 0, };
	fread(rabbit, 1, SIZE, load); 
	printf("%s", rabbit); 

	fclose(load); 

}

int main()
{

#pragma region 파일 입출력

	//파일 입출력을 위해서는 파일을 열고 닫는 과정이 필요합니다.
	//파일을 열기 위해서는 fopen함수를 사용합니다
	//fopen 함수는 파일의 경로와 파일의 모드를 인자로 받습니다.
	//파일의 경로는 파일의 경로를 문자열로 입력하시면 됩니다.

	//r: 읽기 모드
	//w: 쓰기 모드
	//a: 추가모드
	//r+: 읽기/쓰기 모드
	//w+: 읽기/쓰기 모드
	//a+: 읽기/쓰기 모드

	//FILE* file = fopen("data.txt", "w"); //8바이트
	//
	//fputs("level: 5", file);
	//fputs("stage: 3", file);
	//fputs("HP: 100", file);
	//
	//fclose(file);

	//fclose 함수는 파일의 포인터를 인자로 받습니다.
	//파일을 닫으면 파일의 포인터가 NULL로 초기화됩니다.
	//파일을 닫지 않으면 파일이 계속 열려있게 되어 데이터가 손실될 수 있습니다.
	
	//FILE* file = fopen("data.txt", "r");
	//
	//char buffer[SIZE] = { 0, }; 
	//
	//fread(buffer, 1, SIZE, file);
	//
	//printf("%s", buffer);
	//
	//fclose(file);

	//파일의 내용을 읽어서 buffer에 저장합니다.
	//fread함수는 파일의 포인터, 읽을 데이터의 크기,
	//읽을 데이터의 개수, 파일의 포인터를 인자로 받습니다.

#pragma endregion

#pragma region ASCII generator

	Load("토끼txt.txt");

	while (1)
	{
		Load("data.txt");

		system("cls"); 


	}

#pragma endregion


	return 0;
}