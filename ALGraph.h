#ifndef __AL_GRAPH__
#define __AL_GRAPH__

#include "DLinkedList.h"
#include<math.h>


typedef struct _ual
{
	int numV;   // 정점의 수
	int numE;   // 간선의 수
	List * adjList;   // 간선의 정보
	int**arr;
} ALGraph;

double WhoIsPrecede(double data1, double data2)
{
	if (data1 < data2)
		return 1;
	else
		return 0;
}

// 그래프의 초기화
void GraphInit(ALGraph * pg, int nv, int sizea, int sizeb)
{
	int i;
	pg->adjList = (List*)malloc(sizeof(List)*(nv + 1));
	pg->numV = nv;
	pg->numE = 0;     // 초기의 간선 수는 0개
	pg->arr = (int**)malloc(sizeof(int*)*sizea);
	for (int i = 0; i < sizea; i++) {
		pg->arr[i] = (int*)malloc(sizeof(int)*sizeb);
	}
	for (i = 1; i <= nv; i++)
	{
		ListInit(&(pg->adjList[i]), sizea, sizeb, i);
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
		printf("%c 와이파이\t좌표: [%d,%d]\n", i + 64, pg->adjList[i].head->position.xpos, pg->adjList[i].head->position.ypos);
	}

}

double calcul(pos pos1, pos pos2)
{
	double far, power = 2400;
	far = sqrt((pos1.xpos - pos2.xpos)*(pos1.xpos - pos2.xpos) + (pos1.ypos - pos2.ypos)*(pos1.ypos - pos2.ypos));
	power += far;
	if (far <= 10.0)
	{
		power -= 81.0;
	}
	else if (far > 100)
	{
		power -= 101.0;
	}
	else
		power -= 121.0;
	return power;
}

void Put_Me(ALGraph* pg, int num, int sizea, int sizeb)
{
	//SetSortRule(&(pg->adjList[num-1]), WhoIsPrecede);
	ListInit(&(pg->adjList[0]), sizea, sizeb, 0);
	SetSortRule(&(pg->adjList[0]), WhoIsPrecede);
	printf("******My_Info******\n");
	printf("Me 좌표[%d, %d]\n", pg->adjList[0].head->position.xpos, pg->adjList[0].head->position.ypos);
	printf("*******************\n\n");
	for (int a = 1; a <= num; a++)
	{
		double cal;
		pos point;
		point = pg->adjList[a].head->position;
		cal = calcul(pg->adjList[a].head->position, pg->adjList[0].head->position);
		pg->adjList[a].head->data = cal;
		if (cal < pg->adjList[a].strong)
		{
			LInsert(&(pg->adjList[0].head), cal, point, a);
		}
	}
}

void Choose_wifi(ALGraph* pg)
{
	pg->adjList[0].head->connect = pg->adjList[0].head->next;
}

void show_wifi_list(ALGraph* pg)
{
	Node* preg = pg->adjList[0].head->next;
	printf("*********WIFI DIRECT********\n");
	printf("--------와이파이 목록---------\n");
	for (; preg != NULL; preg = preg->next)
	{
		printf("%c 와이파이\n", (preg->name) + 64);
		printf("와이파이 위치: [%d, %d]\n", preg->position.xpos, preg->position.ypos);
		printf("와이파이 거리: %f\n", preg->data);
		printf("\n\n");
	}
	printf("연결된 와이파이: %c\n", (pg->adjList[0].head->next->name)+64);
}

void Change_My_Position(ALGraph* pg, int num, int sizea, int sizeb)
{
	ListInit(&(pg->adjList[0]), sizea, sizeb, 0);
	SetSortRule(&(pg->adjList[0]), WhoIsPrecede);
	printf("******My_Info******\n");
	printf("변경된 Me 좌표[%d, %d]\n", pg->adjList[0].head->position.xpos, pg->adjList[0].head->position.ypos);
	printf("*******************\n\n");
	for (int a = 1; a <= num; a++)
	{
		double cal;
		pos point;
		point = pg->adjList[a].head->position;
		cal = calcul(pg->adjList[a].head->position, pg->adjList[0].head->position);
		pg->adjList[a].head->data = cal;
		if (cal < pg->adjList[a].strong)
		{
			LInsert(&(pg->adjList[0].head), cal, point, a);
		}
	}
}

#endif#pragma once
