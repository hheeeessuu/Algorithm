//
//  ALGraphKruskal.h
//  Graph
//
//  Created by kim on 2017. 9. 10..
//  Copyright © 2017년 kim. All rights reserved.
//

#ifndef ALGraphKruskal_h
#define ALGraphKruskal_h

#include "DLinkedList.h"    // 연결 리스트를 가져다 쓴다!
#include "PriorityQueue.h"
#include "ALEdge.h"

// 정점의 이름을 상수화
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
    int numV;       // 정점의 수
    int numE;       // 간선의 수
    List *adjList;  // 간선의 정보
    int *visitInfo;
    PQueue pqueue;  // 간선의 가중치 정보 저장
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph *pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph *pg);

// 간선의 추가
void AddEdge(ALGraph *pg, int fromV, int toV, int weight);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph *pg);

void DFSShowGraphVertex(ALGraph * pg, int startV);

void ConKruskalMST(ALGraph *pg);    // 최소 비용 신장 트리의 구성

void ShowGraphEdgeWeightInfo(ALGraph *pg); // 가중치 정보 출력

#endif /* ALGraphKruskal_h */
