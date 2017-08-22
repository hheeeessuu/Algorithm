//
//  main.cpp
//  Stack
//
//  Created by kim on 2017. 7. 28..
//  Copyright © 2017년 kim. All rights reserved.
//

#include <iostream>

// Stack
////////////////////////////////////////////////////////////////////////////////////
namespace Stack {
    struct ArrayStack{
        int top;
        int capacity;
        int *array;
    };
    
    struct ArrayStack* CreateStack()
    {
        struct ArrayStack *S = (struct ArrayStack*)malloc(sizeof(struct ArrayStack));
        if(!S)
            return nullptr;
        
        S->capacity = 1;
        S->top = -1;
        S->array = (int *)malloc(S->capacity * sizeof(int));
        if(!S->array) {
            return nullptr;
        }
        
        return S;
    }
    
    int IsEmptyStack(struct ArrayStack *S)
    {
        return (S->top == -1);
    }
    
    int IsFullStack(struct ArrayStack *S)
    {
        // 조건이 참이면 1을, 그렇지 않으면 0을 반환.
        return (S->top == S->capacity - 1);
    }
    
    void Push(struct ArrayStack *S, int data)
    {
        if(IsFullStack(S)) {
            // S->top == capacity - 1 은 스택이 가득 찼다는 것을 의미.
            printf("Stack Overflow");
        } else {
            // 'top'을 1씩 증가시키고 값을 'top'에 저장.
            S->array[++S->top] = data;
        }
    }
    
    int Pop(struct ArrayStack *S)
    {
        if(IsEmptyStack(S)) {
            // S->top == -1 은 스택이 비었다는 것을 의미.
            printf("Stack is Empty");
            return 0;
        } else {
            // 배열의 'top'에서 요소를 제거하고 'top' 값을 1 감소시킴.
            return (S->array[S->top--]);
        }
    }
    
    void DeleteStack(struct ArrayStack *S)
    {
        if(S) {
            if(S->array) {
                free(S->array);
            }
            free(S);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////
// 배가 수행
namespace DynStack {
    struct DynArrayStack {
        int top;
        int capacity;
        int *array;
    };
    
    struct DynArrayStack* CreateStack()
    {
        // 구조체 메로리 할당
        struct DynArrayStack *S = (struct DynArrayStack*)malloc(sizeof(struct DynArrayStack));
        if(!S) {
            return nullptr;
        }
        
        S->capacity = 1;
        S->top = -1;
        S->array = (int*)malloc(S->capacity * sizeof(int));
        // 배열의 크기를 1로 초기화합니다.
        if(!S->array) {
            return nullptr;
        }
        
        return S;
    }
    
    int IsFullStack(struct DynArrayStack *S)
    {
        return (S->top == S->capacity - 1);
    }
    
    void DoubleStack(struct DynArrayStack *S)
    {
        S->capacity *= 2;
        S->array = (int*)realloc(S->array, S->capacity);
    }
    
    void Push(struct DynArrayStack *S, int x)
    {
        //이 구현에서는 overflow가 없습니다.
        if(IsFullStack(S)) {
            DoubleStack(S);
        }
        S->array[++S->top] = x;
    }
    
    int IsEmptyStack(struct DynArrayStack *S)
    {
        return S->top == - 1;
    }
    
    int Top(struct DynArrayStack *S)
    {
        if(IsEmptyStack(S))
            return INT_MIN;
        return S->array[S->top];
    }
    
    int Pop(struct DynArrayStack *S)
    {
        if(IsEmptyStack(S)) {
            return INT_MIN;
        }
        return S->array[S->top--];
    }
    
    void DeleteStack(struct DynArrayStack *S)
    {
        if(S) {
            if(S->array) {
                free(S->array);
            }
            free(S);
        }
    }
}

// 문제 21 주어진 배열 A에서 A[i]의 스팬(span) S[i]는 A[j] <= A[i]를 만족하는 A[i] 바로 직전 요소의 최대 값이라고
// 합니다. 배열 S를 구하세요.
int* FindingSpans1(int A[], int n)
{
    // Input : n개의 정수 배열 A, Output : A의 스팬의 배열 S
    int i, j, S[n]; // 새로운 n개의 정수 배열
    for(i = 0; i < n; i++) {
        j = 1;
        while (j <= i && A[i] > A[i - j]) {
            j = j + 1;
        }
        S[i] = j;
    }
    
    for(int i = 0; i < 5; i++) {
        printf("%d\n", S[i]);
    }

    return S;
}

using namespace DynStack;

// 문제 22 문제 21의 복잡도를 향상할 수 있습니까?
int* FindingSpans2(int A[], int n)
{
    struct DynArrayStack *D = CreateStack();
    int P, S[n];
    for(int i = 0; i < n; i++) {
        while (!IsEmptyStack(D)) {
            if(A[i] > A[Top(D)])
                Pop(D);
        }
        if(IsEmptyStack(D))
            P = -1;
        else
            P = Top(D);
        S[i] = i-P;
        Push(D, i);
    }
    
    for(int i = 0; i < 5; i++) {
        printf("%d\n", S[i]);
    }
    
    return S;
}

struct StackItem {
    int data;
    int index;
};

int MaxRectangleArea(int A[], int n)
{
    int i, maxArea = -1, top = -1, left, currentArea;
    struct StackItem *S = (struct StackItem *) malloc(sizeof(struct StackItem) *n);
    
    //int A[7] = { 3, 2, 5, 6, 1, 4, 4};
    for(i = 0; i <= n; i++) {
        while (top >= 0 && (i == n || S[top].data > A[i])) {
            if(top > 0) {
                left = S[top - 1].index;
            } else {
                left = -1;
            }
            currentArea = (i - left - 1) * S[top].data;
            --top;
            if(currentArea > maxArea)
                maxArea = currentArea;
        }
        
        if(i < n) {
            ++ top;
            S[top].data = A[i];
            S[top].index = i;
        }
    }
    
    return maxArea;
}



int main(int argc, const char * argv[]) {
//    int A[5] = {6, 3, 4, 5, 2};
//    FindingSpans1(A, 5);
//    FindingSpans2(A, 5);
    int A[7] = { 3, 2, 5, 6, 1, 4, 4};
    
    printf("%d\n", MaxRectangleArea(A, 7));
    return 0;
}
