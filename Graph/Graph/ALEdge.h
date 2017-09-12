//
//  ALEdge.h
//  Graph
//
//  Created by kim on 2017. 9. 10..
//  Copyright © 2017년 kim. All rights reserved.
//

#ifndef ALEdge_h
#define ALEdge_h

typedef struct _edge
{
    int v1;         // 간선이 연결하는 첫 번째 정점
    int v2;         // 간선이 연결하는 두 번째 정점
    int weight;     // 간선의 가중치
} Edge;

#endif /* ALEdge_h */
