#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ViewHP(int health)
{
	printf("HP: ");
	for (int i = 0; i < health; i++)
	{
		printf("��");
	}

}


int main()
{
#pragma region Rand() �Լ�

	//time(NULL): UCT �������� 1970�� 1�� 1�� 0�� 0�� 0�ʺ��� 
	//����� �ð��� ��(sec)�� ��ȯ�ϴ� �Լ��Դϴ�.

	//srand(time(NULL)); //���� �߻��⸦ �ʱ�ȭ�ϴ� �Լ��Դϴ�.
	//
	// //0~32767 ������ ������ �����ϴ� �Լ��Դϴ�.
	//int result = rand() % 10+1;
	//printf("result ������ ��: %d\n", result);
	//
	//0~~9������ ���ڰ� ������
	//1~10���� 


#pragma endregion

#pragma region UP-DOWN ����
	//1. ��ǻ�Ͱ� 0~30 ������ ���� ���� �̴´� 
	//2. �÷��̾�� ��ǻ�Ͱ� ���� ���ڸ� �������մϴ�.
	//3. �÷��̾ ��ǻ�Ͱ� ������ �մ� ���ڸ� Ʋ���� �� �������� 1 �����մϴ�.
	//4. ��ǻ�Ͱ� ������ �ִ� ������ �۰ų� ũ�ٰ� ��Ʈ�� �־�� �Ѵ�.
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
	//while(life>0) //life�� 0���� ū ������ �ݺ��ض�
	//{
	//
	//	ViewHP(life); 
	//	printf("���� �����ÿ�: "); 
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
	//		printf("�����Դϴ�\n"); 
	//		break;
	//	}
	//	
	//}
	//
	//if (life <= 0)
	//{
	//	printf("�����ϼ̽��ϴ�\n"); 
	//	
	//}
	//else
	//{
	//	printf("�����Ͽ����ϴ�.");
	//}
#pragma endregion



	return 0;
}