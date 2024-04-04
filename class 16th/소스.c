#include <stdio.h>
#include <stdarg.h>
#include <math.h>

void Debug(int count, ...)
{
	//va_list: ���� ���� ����� �����ϴ� ����
	va_list list = NULL;

	//va_start: ���� ���� ����� ����ϱ� ���� �ʱ�ȭ�ϴ� �Լ�
	va_start(list, count);

	//va_arg: ���� ���� ��Ͽ��� ���� �������� Ư�� �ڷ����� ũ�⸸ŭ
	//�̵��ϴ� �Լ�
	for (int i = 0; i < count; i++)
	{
		printf("%d ", va_arg(list, int));
	}

	//va_end: ���� ���� ����� ��� �� �����͸� NULL�� �ʱ�ȭ�ϴ� �Լ�

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
#pragma region ���� ���� ���
	//�Ű� ������ ������ �������� ���� �Ű� ������ ���� ��
	//����ϴ� �μ��Դϴ�.

	//Debug(3, 10, 20, 30);
	//
	//printf("\n");
	//
	//Debug(5, 10, 20, 30, 40, 50);


#pragma endregion

#pragma region �� �� ������ �Ÿ�
	//�������� ���ؼ� 5������ ���̸� �����Ӥ������Ӵٰ� ���.
	//������, ��Ʈ,

	//printf("100�� ������: %1f ", sqrt(100)); //10
	//printf("2�� 2��: %1f\n", pow(2, 2));//���� 

	//struct person person1 = { 0,0 };
	//struct monster monster1 = { 5, 5 };
	//
	//int x = person1.width - monster1.width;
	//int y = person1.length - monster1.length;
	//
	//if (sqrt(pow(x, 2) + (pow(y, 2)))<=5)
	//{
	//	printf("������ �� �ֽ��ϴ�");
	//}
	//else
	//{
	//	printf("������ �� �����ϴ�");
	//
	//}



#pragma endregion

#pragma region �Լ� ������
	//>�Լ���< �ּҰ��� �����ϰ� ����ų �� �ִ� �����Դϴ�.
	//clauculator�Լ��� Įŧ�����͸� ����Ʈ�ϴ� �Լ���.
	//void (*fptr)() = NULL; 
	//
	//fptr = calculator; 
	//
	//printf("calculator�� �ּ�: %p\n", calculator);
	//
	//fptr();
	//
	////�Լ� �����ʹ� �Լ��� ��ȯ���� �Ű� ������ Ÿ����
	//��ġ�ؾ� �մϴ�.

	calculator(Substract, 10, 20); 
	calculator(Multiplay, 10, 20);
	calculator(Divide, 10, 20);
	calculator(Add, 10, 20); 
#pragma endregion



	return 0;

}