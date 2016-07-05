#include <stdio.h>

typedef struct tagNode
{
	int Data; //데이터 필드
	struct tagNode* NextNode; //다음 노드를 가리키는 포인터
}Node;

Node* createNode(int NewData);
void AppendNode(Node** Head, Node* NewNode);
void destroyNode();
void removeNode(Node** Head, Node* removeNode);
void insertNode(Node* current, Node* NewNode);
Node* getNodeAt(Node* Head, int Location);
int getNodeCount(Node* Head);
void insertNewHead(Node** Head, Node* NewHead);


void main()
{
	int i=0;
	int Count = 0;
	Node* List = NULL;
	Node* current = NULL;
	Node* NewNode = NULL;
	
	for(i=0 ; i<5 ; i++)
	{
		NewNode = createNode(i);
		AppendNode(&List,NewNode);
	}
	
	/*NewNode = createNode(-1);
	insertNewHead(&List,NewNode);
	
	NewNode = createNode(-2);
	insertNewHead(&List,NewNode);*/
	
	Count = getNodeCount(List);
	for(i=0 ; i<Count ; i++)
	{
		current = getNodeAt(List, i);
		printf("List[%d] : %d\n",i,current->Data);
	}

	printf("\nInserting 3000 After [2]...\n\n");
	current = getNodeAt(List,2);
	NewNode = createNode(3000);
	
	insertNode(current, NewNode);
	
	Count = getNodeCount(List);
	for(i=0 ; i<Count ; i++)
	{
		current = getNodeAt(List, i);
		printf("List[%d] : %d\n", i, current->Data);
	}
	
	printf("\nDestroying List...\n");
	
	for(i=0 ; i<Count ; i++)
	{
		current = getNodeAt(List, 0);
		if(current != NULL)
		{
			removeNode(&List,current);
			destroyNode(current);
		}
	}
	return;
	
}


Node* createNode(int NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode->Data = NewData;
	NewNode->NextNode = NULL;
	
	return NewNode;
}

void destroyNode(Node* Node)
{
	free(Node);
}

void AppendNode(Node** Head, Node* NewNode)
{
	if( (*Head) == NULL)
		*Head = NewNode; // 리스트가 비었을 때
	else{
		Node* Tail = (*Head);
		while(Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

Node* getNodeAt(Node* Head, int searchData)
{
	Node* current = Head;
	if(current == NULL) return current; // 리스트가 비었을 때
	
	while(current->Data != searchData && current != NULL)
	{
		current = current->NextNode;	
	}
	return current;
}

void removeNode(Node** Head, Node* removeNode)
{
	if(*Head == removeNode)
		*Head = removeNode->NextNode;
	else
	{
		Node* current = *Head;
		while(current != NULL && current->NextNode != removeNode)
		{
			current = current->NextNode;
		}
		if(current != NULL)
		{
			current->NextNode = removeNode->NextNode;
			destroyNode(removeNode);
		}
	}
}

void insertNode(Node* current, Node* NewNode)
{
	NewNode->NextNode = current->NextNode;
	current->NextNode = NewNode;
}

int getNodeCount(Node* Head)
{
	int count = 0;
	Node* current = Head;
	
	while(current != NULL)
	{
		count++;
		current = current->NextNode;
		
	}
	return count;
}

void insertNewHead(Node** Head, Node* NewHead)
{
	if(Head == NULL)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = *Head;
		*Head = NewHead;
	}
}