#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int data;
	struct tagNode* nextNode;
	struct tagNode* prevNode;
}Node;


Node* createNode(int newData); //노드 생성Node* createNode
void destroyNode(Node* destroyNode);//해제
Node* getNodeAt(Node* Head, int SearchData);
void removeNode(Node** Head,Node* remove); //삭제
void insertNode(Node* current, Node* newNode);//추가
void appendNode(Node** Head, Node* newNode); //붙이기
int getNodeCount(Node* Head);

void main()
{
	int i = 0;
	Node* Head = NULL;
	Node* newNode = NULL;
	//Node* current = NULL;
	
	for(i=0 ; i<5 ; i++)
	{
		newNode = createNode(i);
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
	}
	else
	{
		Node* Tail = (*Head);
		while(Tail->nextNode != NULL)
		{
			Tail = Tail->nextNode;
		}
		Tail->nextNode = newNode;
		newNode->prevNode = Tail; /*새로운 노드의 preNode 포인터가 이전의 노드를 가리킨다*/
	}
}

Node* getNodeAt(Node *Head,int searchData)
{
	Node* current = Head;
	while(current != NULL && current->data != searchData)
	{
		current = current->nextNode;
	}
	return current;
}

void removeNode(Node** Head,Node* remove)//삭제
{
	if(*Head == remove)
	{
		*Head = remove->nextNode;
		
		if(*Head != NULL)
			(*Head)->prevNode = NULL;
		
		remove->nextNode = NULL;
		remove->prevNode = NULL;
	}
	else
	{
		Node* temp = remove;
		
		if(remove->prevNode != NULL)
			remove->prevNode->nextNode = temp->nextNode;
			//remove->nextNode->prevNode = temp->prevNode;
		if(remove->nextNode != NULL)
			remove->nextNode->prevNode = temp->prevNode;
			//remove->prevNode->nextNode = temp->nextNode;
		
		remove->nextNode = NULL;
		remove->prevNode = NULL;
	}
}	

void insertNode(Node* current, Node* newNode)//추가
{
	newNode->nextNode = current->nextNode;
	newNode->prevNode = current;

	if(current->nextNode != NULL)
	{
		current->nextNode->prevNode = newNode;
		current->nextNode = newNode;
	}
}

void destroyNode(Node* destroyNode)//해제
{
	free(destroyNode);
}

int getNodeCount(Node* Head)
{
	int count = 0;
	Node* current = Head;
	while(current != NULL)
	{
		count++;
		current = current->nextNode;
	}
	return count;
}