#include <stdio.h>

int itemcode;//�ʱ�ȭ�� �� �� ��. �˾Ƽ� �ʱ�ȭ

int level = 1;

void stage()
{
	level += 1;
}

void score()
{
	//���� ������ �� �� ���� �ʱ�ȭ��
	//�̷������ �����Դϴ�.
	static int score = 0;

	score++;
	printf("score ������ ��: %d\n", score);



}



int main()
{
#pragma region ���� ����

	//�Լ� ���ο��� ����� ������ {}�Լ� �������� ������ �� 
	//������, {}�� ����� �Ǹ� �޸𸮿��� ������� Ư¡��
	//������ �ֽ��ϴ�.


	//int data = 100;
	//{
	//
	//	int data = 200; //�߰�ȣ�� �߰��ϸ� ���� �ٸ� ������ �����ͺ����� �Ǳ� ������ ������ ���� �ʴ´�.
	//	printf("%d\n", data);
	//	//������ ���� ��Ģ? ���� ����� ��ġ�� �ִ� data������ �����մϴ�.
	//
	//}
	//printf("%d", data); 


#pragma endregion

#pragma region ���� ����


	//�Լ� �ܺο� ����� ������, ��𿡼����� ������ �����ϸ�,
	//���α׷��� ����� �� �����ǰ�, ���α׷��� ����� �� �޸𸮿���
	//�����Ǵ� Ư¡�� ������ �ִ� �����Դϴ�.

	//stage();
	//printf("level ������ ��: %d\n", level);
	//printf("itemcode ������ ��: %d\n", itemcode);

#pragma endregion

#pragma region ���� ����
	//static�̶�� Ű���带 ����ϰ� ���� ������ Ư���� �����鼭,
	//���� ������ Ư¡�� ������ �ִ� �����Դϴ�.
	
	//score();
	//score();
	//score();
	
#pragma endregion

#pragma region ���μ� ����
	//����: 9�� 3 3, 15�� 3,5 20�̐� 2 2 5 ó���� i �� 2�� ��´�. �ݺ����� ��� 

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