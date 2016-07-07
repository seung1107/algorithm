#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int data;
	struct tagNode* nextNode;
	struct tagNode* prevNode;
}Node;


Node* createNode(int newData); //노드 생성Node* createNode
void removeNode(Node** Head); //삭제
void insertNode(Node* current, Node* newNode);//추가
void destroyNode(Node* removeNode);//해제
void appendNode(Node** Head, Node* newNode); //붙이기

void main()
{
	int i = 0;
	Node* Head = NULL;
	Node* newNode = NULL;
	
	for(i=0 ; i<5 ; i++)
	{
		createNode(i);
		appendNode(&Head,newNode);
	}
}


Node* createNode(int newData)//노드 생성Node* createNode
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->nextNode = NULL;
	newNode->prevNode = NULL;
	
	return newNode;
}

void appendNode(Node** Head,Node* newNode)//붙이기
{
	if((*Head) == NULL)
	{
		*Head = newNode;
		newNode->prevNode = Head;
	}
	else
	{
		Node* Tail = (*Head);
		while(Tail->nextNode != NULL)
		{
			Tail = Tail->nextNode;
		}
		Tail->nextNode = newNode;
		newNode->prevNode = Tail;
	}
}


void removeNode(Node** Head);//삭제
void insertNode(Node* current, Node* newNode);//추가
void destroyNode(Node* removeNode);//해제
