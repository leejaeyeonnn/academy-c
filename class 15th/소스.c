#include <stdio.h>

struct Node
{
	int data;
	struct Node* next;

};


int main()
{
#pragma region ASCII 코드
	//미국 정보 교환 포준부호(ASCII)는 7비트로 문자를
	//표현하는 표준 코드입니다.

	

	//for (int i = 0; i < 25; i++)
	//{
	//	
	//	printf("%c\n", 65 + i);
	//
	//
	//}




#pragma endregion

#pragma region 자기 참조 구조체
	//삽입과 삭제가 용이하다 중간의 데이터를 삭제할 수 있다.
	 
	
	//struct Node Node1 = { 10, NULL };
	//struct Node Node2 = { 20, NULL };
	//struct Node Node3 = { 30, NULL };
	//struct Node* currentPtr=&Node1; //커렌트에 노드1의 주소값 삽입
	//Node1.next = &Node2; 
	//Node2.next = &Node3;
	//Node3.next = NULL;
	//
	//while(currentPtr!=NULL)//커렌트의 데이터값이 NULL이 아닐 동안 반복
	//{
	//	printf("%d\n", currentPtr->data); //음.. current가 가리키는 data 프린트
	//
	//	currentPtr = currentPtr->next;
	//}
	//


#pragma endregion


	return 0;
}