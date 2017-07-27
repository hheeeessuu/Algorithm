//
//  main.cpp
//  LinkedList
//
//  Created by kim on 2017. 7. 27..
//  Copyright © 2017년 kim. All rights reserved.
//

#include <iostream>

struct ListNode {
    int data;
    struct ListNode *next;
};

int ListLength(struct ListNode *head) {
    struct ListNode *current = head;
    int count = 0;
    
    while (current != nullptr) {
        count ++;
        current = current->next;
    }
    return count;
}

void InsertInLinkedList(struct ListNode **head, int data, int position) {
    int k = 1;
    struct ListNode *p, *q, *newNode;
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

void DeleteNodeFromLinkedList(struct ListNode **head, int position) {
    int k = 1;
    struct ListNode *p, *q;
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
    }
}

int main() {
    
    return 0;
}
