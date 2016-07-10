#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int data;
	struct tagNode* prevNode;
	struct tagNode* nextNode;
}Node;

Node* createNode(int Data);
void destroyNode(Node* Node);
void appendNode(Node** Head, Node* newNode);
void InsertNode(Node* current, Node* newNode);
void removeNode(Node** Head, Node* remove);
int getNodeCount(Node* Head);

void main()
{
	Node* Head = NULL;
	return;
}

Node* createNode(int Data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = Data;
	newNode->prevNode = NULL;
	newNode->nextNode = NULL;
	
	return newNode;
}

void destroyNode(Node* Node)
{
	free(Node);
}

void appendNode(Node** Head, Node* newNode)
{
	if((*Head) == NULL)
	{
		*Head = newNode;
		(*Head)->prevNode = *Head;
		(*Head)->nextNode = *Head;
	}
	else
	{
		Node* Tail = (*Head)->prevNode;
		
		Tail->nextNode->nextNode = newNode;
		Tail->nextNode - newNode;
		
		newNode->nextNode = (*Head);
		newNode->prevNode = Tail;
	}
}

