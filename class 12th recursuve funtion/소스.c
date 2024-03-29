#include <stdio.h>

int itemcode;//초기화를 안 한 것. 알아서 초기화

int level = 1;

void stage()
{
	level += 1;
}

void score()
{
	//정적 변수에 단 한 번만 초기화가
	//이루어지는 변수입니다.
	static int score = 0;

	score++;
	printf("score 변수의 값: %d\n", score);



}



int main()
{
#pragma region 지역 변수

	//함수 내부에서 선언된 변수로 {}함수 내에서만 접근할 수 
	//있으며, {}를 벗어나게 되면 메모리에서 사라지는 특징을
	//가지고 있습니다.


	//int data = 100;
	//{
	//
	//	int data = 200; //중괄호를 추가하면 완전 다른 지역의 데이터변수가 되기 때문에 오류가 나지 않는다.
	//	printf("%d\n", data);
	//	//변수의 범위 규칙? 가장 가까운 위치에 있는 data변수에 접근합니다.
	//
	//}
	//printf("%d", data); 


#pragma endregion

#pragma region 전역 변수


	//함수 외부에 선언된 변수로, 어디에서든지 접근이 가능하며,
	//프로그램이 실행될 때 생성되고, 프로그램이 종료될 때 메모리에서
	//해제되는 특징을 가지고 있는 변수입니다.

	//stage();
	//printf("level 변수의 값: %d\n", level);
	//printf("itemcode 변수의 값: %d\n", itemcode);

#pragma endregion

#pragma region 정적 변수
	//static이라는 키워드를 사용하고 지역 변수의 특성을 가지면서,
	//전역 변수의 특징을 가지고 있는 변수입니다.
	
	//score();
	//score();
	//score();
	
#pragma endregion

#pragma region 소인수 분해
	//문제: 9가 3 3, 15면 3,5 20이먄 2 2 5 처음에 i 를 2로 잡는다. 반복문을 사용 

	int n;
	scanf_s("%d", &n); 

	//for (int i = a; i<1; i--)
	//{
	//
	//	if (a % i == 0) 
	//	{	
	//		printf("%d", i);
	//		for (int p = (a / i); p < 1; p--)
	//		{
	//			int x = (a / i);
	//		}
	//		
	//	
	//	}
	//}
	//

	for (int i = 2; i <= n; i++) 
	{
		if (n % i == 0)
		{
			n /= i;
			printf("%d", i);

			i--;
		}
	}





#pragma endregion



	return 0;

}