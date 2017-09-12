//
//  ALGraphKruskal.c
//  Graph
//
//  Created by kim on 2017. 9. 10..
//  Copyright © 2017년 kim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedList.h"
#include "ArrayBaseStack.h"
#include "ALGraphKruskal.h"

int WhoIsPrecede(int data1, int data2);
int PQWeightComp(Edge d1, Edge d2)
{
    return d1.weight - d2.weight;
}

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
    
    // 우선순위 큐의 초기화
    PQueueInit(&(pg->pqueue), PQWeightComp);
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
void AddEdge(ALGraph *pg, int fromV, int toV, int weight)
{
    Edge edge = { fromV, toV, weight };     // 간선의 가중치 정보를 담음
    
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;
    
    // 간선의 가중치 정보를 우선순위 큐에 저장
    PEnqueue(&(pg->pqueue), edge);
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

void ShowGraphEdgeWeightInfo(ALGraph *pg)
{
    PQueue copyPQ = pg->pqueue;
    Edge edge;
    
    while(!PQIsEmpty(&copyPQ))
    {
        edge = PDequeue(&copyPQ);
        printf("(%c-%c), w : %d \n", edge.v1 + 65, edge.v2 + 65, edge.weight);
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
//        printf("%c ", visitV + 65);
        return TRUE;
    }
    return FALSE;
}

void DFSShowGraphVertex(ALGraph * pg, int startV)
{
    Stack stack;
    int visitV = startV;
    int nextV;

    StackInit(&stack);
    VisitVertex(pg, visitV);
    SPush(&stack, visitV);

    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
    {
        int visitFlag = FALSE;

        if(VisitVertex(pg, nextV) == TRUE)
        {
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        }
        else
        {
            while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
            {
                if(VisitVertex(pg, nextV) == TRUE)
                {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        if(visitFlag == FALSE)
        {
            if(SIsEmpty(&stack) == TRUE)
                break;
            else
                visitV = SPop(&stack);
        }
    }
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void RemoveWayEdge(ALGraph *pg, int fromV, int toV)     // 한쪽 방향의 간선 소멸
{
    int edge;
    
    if(LFirst(&(pg->adjList[fromV]), &edge))
    {
        if(edge == toV) {
            LRemove(&(pg->adjList[fromV]));
            return;
        }
        
        while(LNext(&(pg->adjList[fromV]), &edge))
        {
            if(edge == toV) {
                LRemove(&(pg->adjList[fromV]));
                return;
            }
        }
    }
}

void RemoveEdge(ALGraph *pg, int fromV, int toV)        // 간선의 소멸
{
    RemoveWayEdge(pg, fromV, toV);
    RemoveWayEdge(pg, toV, fromV);
    (pg->numE)--;
}

void RecoverEdge(ALGraph *pg, int fromV, int toV, int weight)
{
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    (pg->numE)++;
}

int IsConnVertex(ALGraph *pg, int v1, int v2)
{
    Stack stack;
    int visitV = v1;
    int nextV;
    
    StackInit(&stack);
    VisitVertex(pg, visitV);
    SPush(&stack, visitV);
    
    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
    {
        int visitFlag = FALSE;
        // 정점을 돌아다니는 도중에 목표를 찾는다면 TRUE를 반환한다.
        if(nextV == v2) {
            // 함수가 반환하기 전에 초기화를 진행한다.
            memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
            return TRUE;    // 목표를 찾았으니 TRUE를 반환!
        }
        
        if(VisitVertex(pg, nextV) == TRUE)
        {
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        }
        else
        {
            while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
            {
                // 정점을 돌아다니는 도중에 목표를 찾는다면 TRUE를 반환한다.
                if(nextV == v2) {
                    // 함수가 반환하기 전에 초기화를 진행한다.
                    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
                    return TRUE;        // 목표를 찾았으니 TRUE를 반환!
                }
                
                if(VisitVertex(pg, nextV) == TRUE) {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }
        
        if(visitFlag == FALSE)
        {
            if(SIsEmpty(&stack) == TRUE)
                break;
            else
                visitV = SPop(&stack);
        }
    }
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
    return FALSE;   // 여기까지 왔다는 것은 목표를 찾지 못했다는 것!
}

void ConKruskalMST(ALGraph *pg) // 크루스칼 알고리즘 기반 MST의 구성
{
    Edge recvEdge[20];  // 복원할 간선의 정보 저장
    Edge edge;
    int eidx = 0;
    int i;
    
    // MST를 형성할 때까지 아래의 while문을 반복
    while(pg->numE + 1 > pg->numV)      // MST 간선의 수 + 1 == 정점의 수
    {
        edge = PDequeue(&(pg->pqueue));
        RemoveEdge(pg, edge.v1, edge.v2);
        
        if(!IsConnVertex(pg, edge.v1, edge.v2))
        {
            RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
            recvEdge[eidx++] = edge;
        }
    }
    
    // 우선순위 큐에서 삭제된 간선의 정보를 회복
    for(i = 0; i < eidx; i++)
        PEnqueue(&(pg->pqueue), recvEdge[i]);
}


int main(void)
{
    ALGraph graph;          // 그래프의 생성
    GraphInit(&graph, 6);   // 그래프의 초기화

    AddEdge(&graph, A, B, 9);
    AddEdge(&graph, B, C, 2);
    AddEdge(&graph, A, C, 12);
    AddEdge(&graph, A, D, 8);
    AddEdge(&graph, D, C, 6);
    AddEdge(&graph, A, F, 11);
    AddEdge(&graph, F, D, 4);
    AddEdge(&graph, D, E, 3);
    AddEdge(&graph, E, C, 7);
    AddEdge(&graph, F, E, 13);

    ConKruskalMST(&graph);      // MST로 변환
    ShowGraphEdgeInfo(&graph);
    ShowGraphEdgeWeightInfo(&graph);
    
    GraphDestroy(&graph);

    return 0;
}
