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
void insertNode(Node* current, Node* newNode);
void removeNode(Node** Head, Node* remove);
int getNodeCount(Node* Head);
void printNode(Node* node);
Node* getNodeAt(Node * Head, int location);

int main()
{
	int i 		  = 0;
	int count 	  = 0;
	Node* List	  = NULL;
	Node* newNode = NULL;
	Node* current = NULL;
	
	for(i=0 ; i<5 ; i++)
	{
		newNode = createNode(i);
		appendNode(&List,newNode);
	}
	
	count = getNodeCount(List);
	for(i=0 ; i<5 ; i++)
	{
		current = getNodeAt(List, i);
		printf("List[%d] : %d\n",i,current->data);
	}
	
	printf("\nInserting 3000 After [2]...\n\n");
	current = getNodeAt(List,2);
	newNode = createNode(3000);
	insertNode(current,newNode);
	
	
	count = getNodeCount(List);
	for(i=0;i<count*2;i++)
	{
		if(i==0)
			current = List;
		else
			current = current->nextNode;
		
		printf("List[%d] : %d\n",i ,current->data);
	}
	
	printf("\nDestroying List...\n");
	count = getNodeCount(List);
	
	for(i=0 ; i<count ; i++)
	{
		current = getNodeAt(List, 0);
		
		if(current != NULL)
		{
			removeNode(&List,current);
			destroyNode(current);
		}
	}
	return 0;
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
		Tail->nextNode = newNode;
		
		newNode->nextNode = (*Head);
		newNode->prevNode = Tail;
	}
}

void insertNode(Node* current, Node* newNode)
{
	newNode->nextNode = current->nextNode;
	newNode->prevNode = current;	
	
	if(current->nextNode != NULL)
	{
		current->nextNode->prevNode = newNode;
		current->nextNode = newNode;
	}
}

Node* getNodeAt(Node * Head, int location)
{
	Node* current = Head;
	while(current != NULL && (--location)>=0)
	{
		current = current->nextNode;
	}
	
	return current;
}
void removeNode(Node** Head, Node* remove)
{
	if(*Head == remove)
	{
		(*Head)->prevNode->nextNode = remove->nextNode;
		(*Head)->nextNode->prevNode = remove->prevNode;
		
		*Head = remove->nextNode;
		
		remove->prevNode = NULL;
		remove->nextNode = NULL;
	}
	else
	{
		Node* temp = remove;
		
		remove->prevNode->nextNode = temp->nextNode;
		remove->nextNode->prevNode = temp->prevNode;
		
		remove->prevNode = NULL;
		remove->nextNode = NULL;
	}
}

int getNodeCount(Node* Head)
{
	int count = 0;
	Node* current = Head;
	while(current != NULL)
	{
		count++;
		current = current->nextNode;
		
		if(current == Head) break; //원형이기때문에 nextNode가 자기 자신이 될 수 있다.
	}
	return count;
}

void printNode(Node* node)
{
	if(node->prevNode == NULL)
		printf("Prev : NULL\n");
	else
		printf("Prev : %d",node->prevNode->data);
	
	printf("Current : %d",node->data);
	
	if(node->nextNode == NULL)
		printf("Next : NULL\n");
	else
		printf("Next : %d\n",node->nextNode->data);
}