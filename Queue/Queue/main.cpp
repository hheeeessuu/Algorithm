//
//  main.cpp
//  Queue
//
//  Created by kim on 2017. 8. 21..
//  Copyright © 2017년 kim. All rights reserved.
//

#include <iostream>
namespace ArrayQueue {
    struct ArrayQueue {
        int front, rear;
        int capacity;
        int *array;
    };
    
    struct ArrayQueue* Queue(int size) {
        struct ArrayQueue *Q = (struct ArrayQueue*)malloc(sizeof(struct ArrayQueue));
        if(!Q)
            return nullptr;
        Q->capacity = size;
        Q->front = Q->rear = -1;
        Q->array = (int *)malloc(Q->capacity * sizeof(int));
        if(!(Q->array))
            return nullptr;
        return Q;
    }
    
    int IsEmptyQueue (struct ArrayQueue *Q) {
        // 조건이 참이면 1을, 그렇지 않으면 0을 반환.
        return (Q->front == -1);
    }
    
    int IsFullQueue (struct ArrayQueue *Q) {
        // 조건이 참이면 1을, 그렇지 않으면 0을 반환.
        return ((Q->rear + 1) % Q->capacity == Q->front);
    }
    
    int QueueSize(struct ArrayQueue *Q) {
        return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
    }
    
    void EnQueue(struct ArrayQueue *Q, int data) {
        if(IsFullQueue(Q))
            printf("Queue Overflow");
        else {
            Q->rear = (Q->rear + 1) % Q->capacity;
            Q->array[Q->rear] = data;
            if(Q->front == -1)
                Q->front = Q->rear;
        }
    }
    
    int DeQueue(struct ArrayQueue *Q) {
        int data = 0; // 또는 Queue에 존재하지 않는 요소
        if(IsEmptyQueue(Q)) {
            printf("Queue is Empty");
            return 0;
        } else {
            data = Q->array[Q->front];
            if(Q->front == Q->rear)
                Q->front = Q->rear = -1;
            else
                Q->front = (Q->front + 1) % Q->capacity;
        }
        return data;
    }
    
    void DeleteQueue(struct ArrayQueue *Q) {
        if(Q) {
            if(Q->array)
                free(Q->array);
            free(Q);
        }
    }
}

namespace DynArrayQueue{
    struct DynArrayQueue {
        int front, rear;
        int capacity;
        int *array;
    };
    
    struct DynArrayQueue *CreateDynQueue() {
        struct DynArrayQueue *Q = (struct DynArrayQueue*)malloc(sizeof(struct DynArrayQueue));
        if(!Q)
            return nullptr;
        Q->capacity = 1;
        Q->front = Q->rear = -1;
        Q->array = (int *)malloc(Q->capacity * sizeof(int));
        if(!Q->array)
            return nullptr;
        return Q;
        
    }
    
    int IsEmptyQueue (struct DynArrayQueue *Q) {
        // 조건이 참이면 1을, 그렇지 않으면 0을 반환
        return (Q->front == -1);
    }
    
    int IsFullQueue(struct DynArrayQueue *Q) {
        // 조건이 참이면 1을, 그렇지 않으면 0을 반환
        return ((Q->rear + 1) % Q->capacity == Q->front);
    }
    
    int QueueSize(struct DynArrayQueue *Q) {
        return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
    }
    
    void ResizeQueue (struct DynArrayQueue *Q) {
        int size = Q->capacity;
        Q->capacity = Q->capacity * 2;
        Q->array = (int *)realloc(Q->array, Q->capacity);
        if(!Q->array) {
            printf("Memory Error");
            return;
        }
        if(Q->front > Q->rear) {
            for(int i = 0; i < Q->front; i++) {
                Q->array[i + size] = Q->array[i];
            }
            Q->rear = Q->rear + size;
        }
    }
    
    void EnQueue(struct DynArrayQueue *Q, int data) {
        if(IsFullQueue(Q))
            ResizeQueue(Q);
        Q->rear = (Q->rear + 1) % Q->capacity;
        Q->array[Q->rear] = data;
        if(Q->front == -1)
            Q->front = Q->rear;
    }
    
    int DeQueue(struct DynArrayQueue *Q) {
        int data = 0; // 또는 Queue에 존재하지 않는 요소
        if(IsEmptyQueue(Q)) {
            printf("Queue is Empty");
            return 0;
        } else {
            data = Q->array[Q->front];
            if(Q->front == Q->rear)
                Q->front = Q->rear = -1;
            else
                Q->front = (Q->front + 1) % Q->capacity;
        }
        return data;
    }
    
    void DeleteQueue(struct DynArrayQueue *Q) {
        if(Q) {
            if(Q->array)
                free(Q->array);
            free(Q);
        }
    }
}

namespace ListQueue {
    struct ListNode {
        int data;
        struct ListNode *next;
    };
    
    struct Queue {
        struct ListNode *front;
        struct ListNode *rear;
    };
    
    struct Queue* CreateQueue() {
        struct Queue *Q;
//        struct ListNode *temp;
        Q = (struct Queue *)malloc(sizeof(struct Queue));
        if(!Q)
            return nullptr;
//        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        Q->front = Q->rear = nullptr;
        return Q;
    }
    
    int IsEmptyQueue (struct Queue *Q) {
        // 조건이 참이면 1을, 그렇지 않으면 0을 반환
        return (Q->front == nullptr);
    }
    
    void EnQueue (struct Queue *Q, int  data) {
        struct ListNode *newNode;
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        if(!newNode)
            return;
        newNode->data = data;
        newNode->next = nullptr;
        Q->rear->next = newNode;
        Q->rear = newNode;
        if(Q->front == nullptr)
            Q->front = Q->rear;
    }
    
    int DeQueue (struct Queue *Q) {
        int data = 0; // 또는 Queue에 존재하지 않는 요소
        struct ListNode *temp;
        if(IsEmptyQueue(Q)) {
            printf("Queue is empty");
            return 0;
        } else {
            temp = Q->front;
            data = Q->front->data;
            Q->front = Q->front->next;
            free(temp);
        }
        
        return data;
    }
    
    void DeleteQueue (struct Queue *Q) {
        struct ListNode *temp;
        while(Q) {
            temp = Q->front;
            Q->front = Q->front->next;
            free(temp);
        }
        free(Q);
    }
}

int main() {
    
    return 0;
}
