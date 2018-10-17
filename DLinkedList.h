#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define __D_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0


typedef struct Point
{
	int xpos;
	int ypos;
}pos;


typedef double LData;

typedef struct _node
{
	LData data;
	int name;
	pos position;
	struct _node * next;
	struct _node * connect;
} Node;

typedef struct _linkedList
{
	Node * head;
	Node * before;
	LData strong;
	int name;
	int numOfData;
	double(*comp)(LData d1, LData d2);
} LinkedList;


typedef LinkedList List;


void FInsert(List * plist, LData data);
void SInsert(List * plist, LData data);
void ListInit(List * plist, int sizea, int sizeb, int num)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->name = num;
	plist->numOfData = 0;
	plist->strong = 2345;
	plist->head->position.xpos = rand() % sizea;
	plist->head->position.ypos = rand() % sizeb;
}

void SetSortRule(List * plist, double(*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}


void LInsert(List * plist, LData data, pos point, int name)
{
	if (plist->head->next == NULL)
	{
		FInsert(plist, data, point, name);
	}
	else
	{
		SInsert(plist, data, point, name);
	}

}


void FInsert(List * plist, LData data, pos point, int name)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->position = point;
	newNode->name = name;
	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List * plist, LData data, pos point, int name)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	Node * pred = plist->head;
	newNode->data = data;
	newNode->position = point;
	newNode->name = name;
	while (pred->next != NULL &&
		plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}
	printf("\n");
	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
	
}



