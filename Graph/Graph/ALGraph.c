////
////  ALGraph.c
////  Graph
////
////  Created by kim on 2017. 9. 10..
////  Copyright © 2017년 kim. All rights reserved.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include "ALGraph.h"
//#include "DLinkedList.h"
//
//int WhoIsPrecede(int data1, int data2);
//
//// 그래프의 초기화
//void GraphInit(ALGraph *pg, int nv)
//{
//    int i;
//    
//    pg->adjList = (List*)malloc(sizeof(List) * nv);
//    pg->numV = nv;
//    pg->numE = 0;       // 초기의 간선 수는 0개
//    
//    for(i = 0; i < nv; i++)
//    {
//        ListInit(&(pg->adjList[i]));
//        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
//    }
//}
//
//// 그래프 리소스의 해제
//void GraphDestroy(ALGraph *pg)
//{
//    if(pg->adjList != NULL)
//        free(pg->adjList);
//}
//
//// 간선의 추가
//void AddEdge(ALGraph *pg, int fromV, int toV)
//{
//    LInsert(&(pg->adjList[fromV]), toV);
//    LInsert(&(pg->adjList[toV]), fromV);
//    pg->numE += 1;
//}
//
//// 간선의 정보 출력
//void ShowGraphEdgeInfo(ALGraph *pg)
//{
//    int i;
//    int vx;
//    
//    for(i = 0; i < pg->numV; i++)
//    {
//        printf("%c와 연결된 정점 : ", i + 65);
//        
//        if(LFirst(&(pg->adjList[i]), &vx))
//        {
//            printf("%c ", vx + 65);
//            
//            while (LNext(&(pg->adjList[i]), &vx)) {
//                printf("%c ", vx + 65);
//            }
//            printf("\n");
//        }
//    }
//}
//
//int WhoIsPrecede(int data1, int data2)
//{
//    if(data1 < data2)
//        return 0;
//    else
//        return 1;
//}
///*
//int main(void)
//{
//    ALGraph graph;          // 그래프의 생성
//    GraphInit(&graph, 5);   // 그래프의 초기화
//    
//    AddEdge(&graph, A, B);      // 정점 A와 B를 연결
//    AddEdge(&graph, A, D);      // 정점 A와 D를 연결
//    AddEdge(&graph, B, C);      // 정점 B와 C를 연결
//    AddEdge(&graph, C, D);      // 정점 C와 D를 연결
//    AddEdge(&graph, D, E);      // 정점 D와 E를 연결
//    AddEdge(&graph, E, A);      // 정점 E와 A를 연결
//    
//    ShowGraphEdgeInfo(&graph);  // 그래프의 간선정보 출력
//    GraphDestroy(&graph);       // 그래프의 리소스 소멸
//    return 0;
//}
//*/
