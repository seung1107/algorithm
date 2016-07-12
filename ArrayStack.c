#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct tagNode
{
	element data;
}Node;

typedef struct tagArrayStack
{
	int capacity;
	int top;
	Node* nodes;
}arrayStack;

void createStack(arrayStack** stack, int capacity);
void destroyStack(arrayStack* stack);
void Push(arrayStack* stack, element data);
element Pop(arrayStack* stack);
element Top(arrayStack* stack);
int getSize(arrayStack* stack);
int isEmpty(arrayStack* stack);

int main()
{
	
	return 0;
}

void createStack(arrayStack** stack, int capacity)
{
	(*stack) = (arrayStack*)malloc(sizeof(arrayStack));
	(*stack)->nodes = (Node*)malloc(sizeof(Node)*capacity);
	
	(*stack)->capacity = capacity;
	(*stack)->top = 0;
}

void destroyStack(arrayStack *stack)
{
	free(stack->nodes);
	free(stack);
}