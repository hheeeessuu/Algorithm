//
//  main.cpp
//  Heap
//
//  Created by kim on 2017. 8. 23..
//  Copyright © 2017년 kim. All rights reserved.
//

#include <iostream>

enum {
    MIN_HEAP,
    MAX_HEAP
};

// 힙 선언
// 코딩 인터뷰 퀘스쳔
namespace interview {
    struct Heap {
        int *array;
        int count;      // 힙 내 요소들의 수.
        int capacity;   // 힙의 크기.
        int heap_type;  // 최대 혹은 최소 힙.
    };
    
    // 힙 생성
    struct Heap* CreateHeap(int capacity, int heap_type) {
        struct Heap *h = (struct Heap*) malloc(sizeof(struct Heap));
        if(h == NULL) {
            printf("Memory Error");
            return nullptr;
        }
        h->heap_type = heap_type;
        h->count = 0;
        h->capacity = capacity;
        h->array = (int *) malloc(sizeof(int) * h->capacity);
        if(h->array == nullptr) {
            printf("Memory Error");
            return nullptr;
        }
        return h;
    }
    
    // 노드의 부모
    // 배열 i 번째 위치한 노드의 부모는 (i - 1) / 2에 위치합니다.
    
    int Parent (struct Heap *h, int i) {
        if(i <= 0 || i >= h->count)
            return -1;
        return (i - 1) / 2;
    }
    
    int GetMaximum(Heap *h) {
        if(h->count == 0)
            return -1;
        return h->array[0];
    }
    
    // 요소의 Heapifying
    // 요소가 힙에 삽입되면 해당 요소로 인해 힙의 성질이 깨질 수 있다. 이런 경우 다시 힙의 성질을 만족 시키기 위해
    // 요소들의 위치를 조정해야 하는데, 이 과정을 heapifying이라고 한다.
    
    int LeftChild(struct Heap *h, int i) {
        int left = 2 * i + 1;
        if(left >= h->count)
            return -1;
        return left;
    }
    
    int RightChild(struct Heap *h, int i) {
        int right = 2 * i + 2;
        if(right >= h->count)
            return -1;
        return right;
    }
    
    void PercolateDown(struct Heap *h, int i) {
        int l, r, max, temp;
        l = LeftChild(h, i);
        r = RightChild(h, i);
        
        if(l != -1 && h->array[l] > h-> array[i]) max = l;
        else max = i;
        
        if(r != -1 && h->array[r] > h->array[max])
            max = r;
        
        if(max != i) {
            // h->array[i]와 h->array[max]를 서로 바꿉니다.
            temp = h->array[i];
            h->array[i] = h->array[max];
            h->array[max] = temp;
        }
        
        PercolateDown(h, max);
    }
    
    int DeleteMax(struct Heap *h) {
        int data;
        if(h->count == 0)
            return -1;
        data = h->array[0];
        h->array[0] = h->array[h->count - 1];
        h->count--; // 힙의 크기를 줄입니다.
        PercolateDown(h, 0);
        return data;
    }
    
    void ResizeHeap(struct Heap *h) {
        int *array_old = h->array;
        h->array = (int *)malloc(sizeof(int) * h->capacity * 2);
        
        if(h->array == nullptr) {
            printf("Memory Error");
            return;
        }
        
        for(int i = 0; i < h->capacity; i++) {
            h->array[i] = array_old[i];
        }
        
        h->capacity *= 2;
        free(array_old);
    }
    
    void Insert(struct Heap *h, int data, int i) {   // i 불확실 int 반환 불확실
        if(h->count == h->capacity)
            ResizeHeap(h);
        h->count++; // 새로운 아이템을 저장하기 위해 힙의 크기를 늘립니다.
        while(i > 1 && data > h->array[(i - 1) / 2]) {
            h->array[i] = h->array[(i - 1) / 2];
            i = i - 1 / 2;
        }
        h->array[i] = data;
    }
    
    void DestroyHeap(struct Heap *h) {
        if(h == nullptr)
            return;
        free(h->array);
        free(h);
        h = nullptr;
    }
    
    void BuildHeap(struct Heap *h, int A[], int n) {
        
        if(h == nullptr)
            return;
        while(n >= h->capacity)
            ResizeHeap(h);
        for(int i = 0; i < n; i++)
            h->array[i] = A[i];
        h->count = n;
        for(int i = n / 2 - 1; i >= 0; i--)
            PercolateDown(h, i);
    }
    
    void Heapsort(int A[], int n) {
        struct Heap *h = CreateHeap(n, MAX_HEAP);
        int old_size, i, temp;
        BuildHeap(h, A, n);
        old_size = h->count;
        
        for(i = n - 1; i > 0; i++) {
            // h->array [0]가 마지막 요소입니다.
            temp = h->array[0];
            h->array[0] = h->array[h->count - 1];
            h->count--;
            PercolateDown(h, i);
        }
        
        h->count = old_size;
    }
}

// 윤성우 열혈 C 자료구조

//#include "SimpleHeap.hpp"

//#include "UsefulHeap.hpp"

#include "PrioriyQueue.hpp"

int DataPriorityComp(char ch1, char ch2)    // 우선순위 비교함수
{
    return ch2 - ch1;
//    return ch1 - ch2;
}

int main() {
    
    /* SimpleHeap.hpp
    Heap heap;
    HeapInit(&heap);            // 힙의 초기화
    
    HInsert(&heap, 'A', 1);     // 문자 'A'를 최고의 우선순위로 저장
    HInsert(&heap, 'B', 2);     // 문자 'B'를 두 번째 우선순위로 저장
    HInsert(&heap, 'C', 3);     // 문자 'C'를 세 번째 우선순위로 저장
    printf("%c \n", HDelete(&heap));
    
    HInsert(&heap, 'A', 1);     // 문자 'A' 한 번 더 저장!
    HInsert(&heap, 'B', 2);     // 문자 'B' 한 번 더 저장!
    HInsert(&heap, 'C', 3);     // 문자 'C' 한 번 더 저장!
    printf("%c \n", HDelete(&heap));
    
    while(!HIsEmpty(&heap))
        printf("%c \n", HDelete(&heap));*/
    
    /* UsefulHeap.hpp
    Heap heap;
    HeapInit(&heap, DataPriorityComp);      // 우선순위 비교함수 등록
    
    HInsert(&heap, 'A');     // 문자 'A'를 최고의 우선순위로 저장
    HInsert(&heap, 'B');     // 문자 'B'를 두 번째 우선순위로 저장
    HInsert(&heap, 'C');     // 문자 'C'를 세 번째 우선순위로 저장
    printf("%c \n", HDelete(&heap));
    
    HInsert(&heap, 'A');     // 문자 'A' 한 번 더 저장!
    HInsert(&heap, 'B');     // 문자 'B' 한 번 더 저장!
    HInsert(&heap, 'C');     // 문자 'C' 한 번 더 저장!
    printf("%c \n", HDelete(&heap));
    
    while(!HIsEmpty(&heap))
        printf("%c \n", HDelete(&heap));*/

    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);
    
    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("%c \n", PDequeue(&pq));
    
    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("%c \n", PDequeue(&pq));
    
    while(!PQIsEmpty(&pq))
        printf("%c \n", PDequeue(&pq));
    
    return 0;
}
