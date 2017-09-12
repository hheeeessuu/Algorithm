//
//  ALGraphBFS.c
//  Graph
//
//  Created by kim on 2017. 9. 10..
//  Copyright © 2017년 kim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphBFS.h"
#include "DLinkedList.h"
#include "CircularQueue.h"

int WhoIsPrecede(int data1, int data2);

// 그래프의 초기화
void GraphInit(ALGraph *pg, int nv)
{
    int i;
    
    pg->adjList = (List*)malloc(sizeof(List) * nv);
    pg->numV = nv;
    pg->numE = 0;       // 초기의 간선 수는 0개
    
    for(i = 0; i < nv; i++)
    {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }
    
    pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV);
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

// 그래프 리소스의 해제
void GraphDestroy(ALGraph *pg)
{
    if(pg->adjList != NULL)
        free(pg->adjList);
    
    if(pg->visitInfo != NULL)
        free(pg->visitInfo);
}

// 간선의 추가
void AddEdge(ALGraph *pg, int fromV, int toV)
{
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;
}

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph *pg)
{
    int i;
    int vx;
    
    for(i = 0; i < pg->numV; i++)
    {
        printf("%c와 연결된 정점 : ", i + 65);
        
        if(LFirst(&(pg->adjList[i]), &vx))
        {
            printf("%c ", vx + 65);
            
            while (LNext(&(pg->adjList[i]), &vx)) {
                printf("%c ", vx + 65);
            }
            printf("\n");
        }
    }
}

int WhoIsPrecede(int data1, int data2)
{
    if(data1 < data2)
        return 0;
    else
        return 1;
}

int VisitVertex(ALGraph *pg, int visitV)
{
    if(pg->visitInfo[visitV] == 0)
    {
        pg->visitInfo[visitV] = 1;
        printf("%c ", visitV + 65);
        return TRUE;
    }
    return FALSE;
}

void BFSShowGraphVertex(ALGraph *pg, int startV)
{
    Queue queue;
    int visitV = startV;
    int nextV;
    
    QueueInit(&queue);
    
    VisitVertex(pg, visitV);
    
    while(LFirst(&pg->adjList[visitV], &nextV) == TRUE)
    {
        if(VisitVertex(pg, nextV) == TRUE)
            Enqueue(&queue, nextV);
        
        while(LNext(&pg->adjList[visitV], &nextV) == TRUE)
        {
            if(VisitVertex(pg, nextV) == TRUE)
                Enqueue(&queue, nextV);
        }
        
        if(QIsEmpty(&queue) == TRUE)
            break;
        else
            visitV = Dequeue(&queue);
    }
    
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

int main(void)
{
    ALGraph graph;          // 그래프의 생성
    GraphInit(&graph, 7);   // 그래프의 초기화
    
    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, D, C);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, F);
    AddEdge(&graph, E, G);
    
    ShowGraphEdgeInfo(&graph);
    BFSShowGraphVertex(&graph, A);  printf("\n");
    BFSShowGraphVertex(&graph, C);  printf("\n");
    BFSShowGraphVertex(&graph, E);  printf("\n");
    BFSShowGraphVertex(&graph, G);  printf("\n");
    
    GraphDestroy(&graph);
    
    return 0;
}
