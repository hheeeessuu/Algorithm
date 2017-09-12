//
//  Table.c
//  Table&Hash
//
//  Created by kim on 2017. 9. 8..
//  Copyright © 2017년 kim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

void TBLInit(Table *pt, HashFunc *f)
{
    int i;
    
    // 모든 슬롯 초기화
    for(i = 0; i < MAX_TBL; i++)
        (pt->tbl[i]).status = EMPTY;
    
    pt->hf = f;     // 해쉬 함수 등록
}

void TBLInsert(Table *pt, Key k, Value v)
{
    int hv = pt->hf(k);
    pt->tbl[hv].val = v;
    pt->tbl[hv].key = k;
    pt->tbl[hv].status = INUSE;
}

Value TBLDelete(Table *pt, Key k)
{
    int hv = pt->hf(k);
    
    if(pt->tbl[hv].status != INUSE){
        return NULL;
    } else {
        (pt->tbl[hv]).status = DELETED;
        return (pt->tbl[hv]).val;       // 소멸 대상의 값 반환
    }
}

Value TBLSearch(Table *pt, Key k)
{
    int hv = pt->hf(k);
    
    if((pt->tbl[hv]).status != INUSE)
        return NULL;
    else
        return (pt->tbl[hv]).val;       // 탐색 대상의 값 반환
}

int MyHashFunc(int k)
{
    return k % 100;
}

int main(void)
{
    Table myTbl;
    Person *np;
    Person *sp;
    Person *rp;
    
    TBLInit(&myTbl, MyHashFunc);
    
    // 데이터 입력
    np = MakePersonData(20120003, "Lee", "Seoul");
    TBLInsert(&myTbl, GetSSN(np), np);
    
    np = MakePersonData(20130012, "Kim", "Jeju");
    TBLInsert(&myTbl, GetSSN(np), np);
    
    np = MakePersonData(20170049, "Han", "Kangwon");
    TBLInsert(&myTbl, GetSSN(np), np);
    
    // 데이터 탐색
    sp = TBLSearch(&myTbl, 20120003);
    if(sp != NULL)
        ShowPerInfo(sp);
    
    sp = TBLSearch(&myTbl, 20130012);
    if(sp != NULL)
        ShowPerInfo(sp);
    
    sp = TBLSearch(&myTbl, 20170049);
    if(sp != NULL)
        ShowPerInfo(sp);
    
    // 데이터 삭제
    rp = TBLDelete(&myTbl, 20120003);
    if(rp != NULL)
        free(rp);
    
    rp = TBLDelete(&myTbl, 20130012);
    if(rp != NULL)
        free(rp);
    
    rp = TBLDelete(&myTbl, 20170049);
    if(rp != NULL)
        free(rp);
    
    return 0;
}
