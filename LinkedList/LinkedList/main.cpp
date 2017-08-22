//
//  main.cpp
//  LinkedList
//
//  Created by kim on 2017. 7. 27..
//  Copyright © 2017년 kim. All rights reserved.
//

#include <iostream>

// 단일 연결 리스트
///////////////////////////////////////////////////////////////////////////

struct ListNode {
    int data;
    struct ListNode *next;
};

int ListLength(struct ListNode *head)
{
    struct ListNode *current = head;
    int count = 0;
    
    while (current != nullptr) {
        count ++;
        current = current->next;
    }
    return count;
}

void InsertInLinkedList(struct ListNode **head, int data, int position)
{
    int k = 1;
    struct ListNode *p, *q = nullptr, *newNode;
    newNode = (ListNode *)malloc(sizeof(struct ListNode));
    if(!newNode) {
        printf("MemoryError");
        return;
    }
    newNode->data = data;
    p = *head;
    
    // 시작 지점에 삽입.
    if(position == 1) {
        newNode->next = p;
        *head = newNode;
    } else {
        // 삽입 지점의 위치까지 목록을 탐색.
        while(p != nullptr && k < position) {
            k++;
            q = p;
            p = p->next;
        }
        q->next = newNode; // 이 작업을 위한 좀더 최적화 함.
        newNode->next = p;
    }
}

void DeleteNodeFromLinkedList(struct ListNode **head, int position)
{
    int k = 1;
    struct ListNode *p, *q = nullptr;
    if(*head == nullptr) {
        printf("List Empty");
        return;
    }
    p = *head;
    if(position == 1) {
        // 처음에서
        *head = (*head)->next;
        free (p);
        return ;
    } else {
        // 삭제하고자 하는 위치까지 목록을 탐색.
        while ((p != nullptr) && (k < position)) {
            k++;
            q = p;
            p = p->next;
        }
        if(p == nullptr) {
            // 끝에서
            printf("Position does not exist.");
        } else {
            // 중간에서
            q->next = p->next;
            free(p);
        }
    }
}

void DeleteLinkedList (struct ListNode **head)
{
    struct ListNode *auxilaryNode, *iterator;
    iterator = *head;
    while (iterator) {
        auxilaryNode = iterator->next;
        free(iterator);
        iterator = auxilaryNode;
    }
    *head = nullptr; // 호출자의 변수에 반영.
}

///////////////////////////////////////////////////////////////////////////
// 이중 연결 리스트

struct DLLNode {
    int data;
    struct DLLNode *next;
    struct DLLNode *prev;
};

void DLLInsert(struct DLLNode **head, int data, int position)
{
    int k = 1;
    struct DLLNode *temp, *newNode;
    newNode = (struct DLLNode *)malloc(sizeof(struct DLLNode));
    if(!newNode) {
        // 항상 메모리 에러를 체크.
        printf("Memory Error");
        return;
    }
    newNode->data = data;
    if(position == 1) {
        // 시작 위치에 노드를 삽입.
        newNode->next = *head;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }
    temp = *head;
    // 루프 후, temp는 마지막 노드의 이전 노드를 가리키거나
    // 삽입하고자 하는 위치의 노드의 이전 노드를 가리킴.
    while ((k < position) && temp->next != nullptr) {
        temp = temp->next;
        k++;
    }
    if(k != position) {
        printf("Desired position does not exist\n");
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return;
}

void DLLDelete(struct DLLNode **head, int position)
{
    struct DLLNode *temp, *temp2;
    temp = *head;
    int k = 1;
    if(*head == nullptr) {
        printf("List is empty");
        return;
    }
    if(position == 1) {
        *head = (*head)->next;
        if(*head != nullptr) {
            (*head)->prev = nullptr;
            free(temp);
            return;
        }
    }
    while ((k < position - 1) && temp->next != nullptr) {
        temp = temp->next;
        k++;
    }
    if(k != position - 1) {
        printf("Desired position does not exist\n");
    }
    temp2 = temp->prev;
    temp2->next = temp->next;
    if(temp->next) {
        // 중간 노드 삭제
        temp->next->prev = temp2;
    }
    free(temp);
    return;
}

///////////////////////////////////////////////////////////////////////////
// 환형 연결 리스트
struct CLLNode {
    int data;
    struct CLLNode *next;
};

int CircularListLength(struct CLLNode *head)
{
    struct CLLNode *current = head;
    int count = 0;
    if(head == nullptr)
        return 0;
    do {
        current = current->next;
        count++;
    } while (current != head);
    return count;
}

void PrintCircularListData(struct CLLNode *head)
{
    struct CLLNode *current = head;
    if(head == nullptr) {
        return;
    }
    do {
        printf("%d", current->data);
        current = current->next;
    } while(current != head);
}

void InsertAtEndInCLL (struct CLLNode **head, int data) {
    struct CLLNode *current = *head;
    struct CLLNode *newNode = (struct CLLNode*) (malloc(sizeof(struct CLLNode)));
    
    if(!newNode) {
        printf("Memory Error");
        return;
    }
    newNode->data = data;
    while (current->next != *head)
        current = current->next;
    newNode->next = newNode;
    if(*head == nullptr) {
        *head = newNode;
    } else {
        newNode->next = *head;
        current->next = newNode;
    }
}

void InsertAtBeginInCLL (struct CLLNode **head, int data)
{
    struct CLLNode *current = *head;
    struct CLLNode *newNode = (struct CLLNode*) (malloc(sizeof(struct CLLNode)));
    if(!newNode) {
        printf("Memory Error");
        return;
    }
    newNode->data = data;
    while (current->next != *head) {
        current = current->next;
    }
    newNode->next = newNode;
    if(*head == nullptr) {
        *head = newNode;
    } else {
        newNode->next = *head;
        current->next = newNode;
        *head = newNode;
    }
    return;
}

void DeleteLastNodeFromCLL (struct CLLNode **head)
{
    struct CLLNode *temp = *head, *current = *head;
    if(*head == nullptr) {
        printf("List Empty");
        return;
    }
    while (current->next != *head) {
        temp = current;
        current = current->next;
    }
    temp->next = current->next;
    free(current);
    return;
}

void DeleteFrontNodeFromCLL (struct CLLNode **head)
{
    struct CLLNode *temp = *head;
    struct CLLNode *current = *head;
    if(*head == nullptr) {
        printf("List Empty");
        return;
    }
    while (current->next != *head) {
        current = current->next;
    }
    current->next = (*head)->next;
    *head = (*head)->next;
    free(temp);
    return;
}

int main() {
    
    int test = 100;
//
    int *pnum;
    int **ppnum = &pnum;
//
    pnum = &test;
    pnum = *ppnum;
    *pnum = **ppnum;
    
    printf("%d\n",test);
    printf("%d\n",*pnum);
    printf("%p\n",&test);
    printf("%p\n",pnum);
    printf("%d\n", **ppnum);
    printf("%p\n", *ppnum);
    printf("%p\n", ppnum);
    
    
    return 0;
}
