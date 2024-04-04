#include <stdio.h>
#include <stdarg.h>
#include <math.h>

void Debug(int count, ...)
{
	//va_list: 가변 길이 목록을 저장하는 변수
	va_list list = NULL;

	//va_start: 가변 길이 목록을 사용하기 위해 초기화하는 함수
	va_start(list, count);

	//va_arg: 가변 길이 목록에서 값을 가져오고 특정 자료형의 크기만큼
	//이동하는 함수
	for (int i = 0; i < count; i++)
	{
		printf("%d ", va_arg(list, int));
	}

	//va_end: 가변 길이 목록을 사용 후 포인터를 NULL로 초기화하는 함수

	va_end(list);


}

struct person
{
	int width; 
	int length; 

};

struct monster
{
	int width;
	int length;

};

double Add (double x, double y)
{
	return x + y;
}


double Substract(double x, double y) 
{
	return x + y;
}

double Multiplay(double x, double y)
{
	return x + y;
}
double Divide(double x, double y)
{
	return x / y;
}

void calculator(double(*ptr)(double, double), double u, double v)
{
	printf("%1f\n",ptr(u, v));

}
int main()
{
#pragma region 가변 길이 목록
	//매개 변수의 개수가 정해지지 않은 매개 변수를 받을 때
	//사용하는 인수입니다.

	//Debug(3, 10, 20, 30);
	//
	//printf("\n");
	//
	//Debug(5, 10, 20, 30, 40, 50);


#pragma endregion

#pragma region 두 점 사이의 거리
	//빗변값을 구해서 5이허의 값이면 범위앙ㄴ에들어왓다고 출력.
	//제곱근, 루트,

	//printf("100의 제곱근: %1f ", sqrt(100)); //10
	//printf("2의 2승: %1f\n", pow(2, 2));//제곱 

	//struct person person1 = { 0,0 };
	//struct monster monster1 = { 5, 5 };
	//
	//int x = person1.width - monster1.width;
	//int y = person1.length - monster1.length;
	//
	//if (sqrt(pow(x, 2) + (pow(y, 2)))<=5)
	//{
	//	printf("공격할 수 있습니다");
	//}
	//else
	//{
	//	printf("공격할 수 없습니다");
	//
	//}



#pragma endregion

#pragma region 함수 포인터
	//>함수의< 주소값을 저장하고 가리킬 수 있는 변수입니다.
	//clauculator함수는 칼큘레이터를 프린트하는 함수다.
	//void (*fptr)() = NULL; 
	//
	//fptr = calculator; 
	//
	//printf("calculator의 주소: %p\n", calculator);
	//
	//fptr();
	//
	////함수 포인터는 함수의 반환형과 매개 변수의 타입이
	//일치해야 합니다.

	calculator(Substract, 10, 20); 
	calculator(Multiplay, 10, 20);
	calculator(Divide, 10, 20);
	calculator(Add, 10, 20); 
#pragma endregion



	return 0;

}