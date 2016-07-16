#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode
{
	char* data;
	struct tagNode* nextNode;
}Node;

typedef struct tagLinkedListStack
{
	Node* List;
	Node* Top;
}LinkedListStack;

void createStack(LinkedListStack** stack);
void destroyStack(LinkedListStack* stack);

Node* createNode(char* data);
void destroyNode(Node* destroy);

void Push(LinkedListStack* stack, Node* newNode);
void Pop(LinkedListStack* stack);

Node* Top(LinkedListStack* stack);
int getSize(LinkedListStack* stack);
int isEmpty(LinkedListStack* stack);



void createStack(LinkedListStack** stack)
{
	(*stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*stack)->List = NULL;
	(*stack)->Top = NULL;
}

void destroyStack(LinkedListStack* stack)
{
	while(!isEmpty(stack))
	{
		Node* Popped = Pop(stack);
		destroyNode(Popped);
	}
	free(stack);
}

Node* createNode(char* newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (char*)malloc(strlen(newData)+1);
	
	strcpy(newNode->data, newData);
	
	newNode->nextNode = NULL;
	
	return newNode;
}