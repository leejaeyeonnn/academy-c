#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ViewHP(int health)
{
	printf("HP: ");
	for (int i = 0; i < health; i++)
	{
		printf("♥");
	}

}


int main()
{
#pragma region Rand() 함수

	//time(NULL): UCT 기준으로 1970년 1월 1일 0시 0분 0초부터 
	//경과된 시간을 초(sec)로 반환하는 함수입니다.

	//srand(time(NULL)); //난수 발생기를 초기화하는 함수입니다.
	//
	// //0~32767 사이의 난수를 생성하는 함수입니다.
	//int result = rand() % 10+1;
	//printf("result 변수의 값: %d\n", result);
	//
	//0~~9사이의 슛자가 나오게
	//1~10사이 


#pragma endregion

#pragma region UP-DOWN 게임
	//1. 컴퓨터가 0~30 사이의 난수 값을 뽑는다 
	//2. 플레이어는 컴퓨터가 뽑은 숫자를 맞혀야합니다.
	//3. 플레이어가 컴퓨터가 가지고 잇는 숫자를 틀렸을 때 라이프가 1 감소합니다.
	//4. 컴퓨터가 가지고 있는 값보다 작거나 크다고 힌트를 주어야 한다.
	//while (1)
	//{
	//	ViewHP(5);
	//	system("cls");
	//}

	//int number = rand()%31;
	//int pnumber=0;
	//int life = 5; 
	//
	//srand(time(NULL));
	//
	//while(life>0) //life가 0보다 큰 동안은 반복해라
	//{
	//
	//	ViewHP(life); 
	//	printf("값을 적으시오: "); 
	//	scanf_s("%d", &pnumber); 
	//	system("cls");
	//	printf("\n");
	//
	//	if (pnumber < number)
	//	{
	//		printf("UP\n");
	//		life--;
	//
	//	}
	//	else if (pnumber > number)
	//	{
	//		printf("Down\n");
	//		life--;
	//	}
	//	else if (pnumber == number)
	//	{
	//		printf("정답입니다\n"); 
	//		break;
	//	}
	//	
	//}
	//
	//if (life <= 0)
	//{
	//	printf("실패하셨습니다\n"); 
	//	
	//}
	//else
	//{
	//	printf("성공하였습니다.");
	//}
#pragma endregion



	return 0;
}