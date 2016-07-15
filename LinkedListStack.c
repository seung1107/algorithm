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