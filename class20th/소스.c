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

#pragma region ���� �����

	//���� ������� ���ؼ��� ������ ���� �ݴ� ������ �ʿ��մϴ�.
	//������ ���� ���ؼ��� fopen�Լ��� ����մϴ�
	//fopen �Լ��� ������ ��ο� ������ ��带 ���ڷ� �޽��ϴ�.
	//������ ��δ� ������ ��θ� ���ڿ��� �Է��Ͻø� �˴ϴ�.

	//r: �б� ���
	//w: ���� ���
	//a: �߰����
	//r+: �б�/���� ���
	//w+: �б�/���� ���
	//a+: �б�/���� ���

	//FILE* file = fopen("data.txt", "w"); //8����Ʈ
	//
	//fputs("level: 5", file);
	//fputs("stage: 3", file);
	//fputs("HP: 100", file);
	//
	//fclose(file);

	//fclose �Լ��� ������ �����͸� ���ڷ� �޽��ϴ�.
	//������ ������ ������ �����Ͱ� NULL�� �ʱ�ȭ�˴ϴ�.
	//������ ���� ������ ������ ��� �����ְ� �Ǿ� �����Ͱ� �սǵ� �� �ֽ��ϴ�.
	
	//FILE* file = fopen("data.txt", "r");
	//
	//char buffer[SIZE] = { 0, }; 
	//
	//fread(buffer, 1, SIZE, file);
	//
	//printf("%s", buffer);
	//
	//fclose(file);

	//������ ������ �о buffer�� �����մϴ�.
	//fread�Լ��� ������ ������, ���� �������� ũ��,
	//���� �������� ����, ������ �����͸� ���ڷ� �޽��ϴ�.

#pragma endregion

#pragma region ASCII generator

	Load("�䳢txt.txt");

	while (1)
	{
		Load("data.txt");

		system("cls"); 


	}

#pragma endregion


	return 0;
}