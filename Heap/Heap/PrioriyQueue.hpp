//
//  PrioriyQueue.hpp
//  Heap
//
//  Created by kim on 2017. 8. 28..
//  Copyright © 2017년 kim. All rights reserved.
//

#ifndef PrioriyQueue_hpp
#define PrioriyQueue_hpp

#include "UsefulHeap.hpp"

typedef Heap PQueue;
typedef HData PQData;

// - 우선순위 큐의 초기화를 진행한다.
// - 우선순위 큐 생성 후 제일 먼저 호출되어야 하는 함수이다.
void PQueueInit(PQueue *ppq, PriorityComp pc);
// - 우선 순위 큐가 빈 경우 TRUE(1)을 그렇지 않은 경우 FALSE(0)을 반환한다.
int PQIsEmpty(PQueue *ppq);

// - 우선순위 큐에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.
void PEnqueue(PQueue *ppq, PQData data);
PQData PDequeue(PQueue *ppq);
// - 우선순위가 가장 높은 데이터를 삭제한다.
// - 삭제된 데이터는 반환된다.
// - 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.

#endif /* PrioriyQueue_hpp */
