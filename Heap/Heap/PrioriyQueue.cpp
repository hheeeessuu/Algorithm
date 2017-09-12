//
//  PrioriyQueue.cpp
//  Heap
//
//  Created by kim on 2017. 8. 28..
//  Copyright © 2017년 kim. All rights reserved.
//

#include "PrioriyQueue.hpp"

void PQueueInit(PQueue *ppq, PriorityComp pc)
{
    HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue *ppq)
{
    return HIsEmpty(ppq);
}

void PEnqueue(PQueue *ppq, PQData data)
{
    HInsert(ppq, data);
}

PQData PDequeue(PQueue *ppq)
{
    return HDelete(ppq);
}
