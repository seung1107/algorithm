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
	int Top;
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
	int i = 0;
	arrayStack* stack = NULL;
	
	createStack(&stack, 10);
	
	Push(stack, 3);
	Push(stack, 37);
	Push(stack, 11);
	Push(stack, 12);
	printf("Capacity : %d, Size: %d, Top : %d\n\n",stack->capacity,getSize(stack),Top(stack));
	for(i=0 ; i<4 ; i++)
	{
		if(isEmpty(stack))
			break;
		
		printf("Popped : %d, ",Pop(stack));
		
		if(!isEmpty(stack))
			printf("Current Top : %d\n",Top(stack));
		else
			printf("Stack is Empty\n");
	}
	destroyStack(stack);
	
	return 0;
}

void createStack(arrayStack** stack, int capacity)
{
	(*stack) = (arrayStack*)malloc(sizeof(arrayStack));
	(*stack)->nodes = (Node*)malloc(sizeof(Node)*capacity);
	
	(*stack)->capacity = capacity;
	(*stack)->Top = 0;
}

void destroyStack(arrayStack *stack)
{
	free(stack->nodes);
	free(stack);
}

void Push(arrayStack* stack, element data)
{
	int position = stack->Top;
	
	stack->nodes[position].data = data;
	stack->Top++;
}

element Pop(arrayStack* stack)
{
	int position = --(stack->Top);
	
	return stack->nodes[position].data;
}

element Top(arrayStack* stack)
{
	int position = stack->Top - 1;
	
	return stack->nodes[position].data;
}

int getSize(arrayStack* stack)
{
	return stack->Top;
}

int isEmpty(arrayStack* stack)
{
	return (stack->Top==0);
}