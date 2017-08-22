//
//  main.cpp
//  Tree
//
//  Created by kim on 2017. 8. 22..
//  Copyright © 2017년 kim. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// 이진 트리
struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

//              1
//          2       3
//        4   5   6   7
// 전위 운행법(PreOrder Traversal)
// 1, 2, 4, 5, 3, 6, 7
void PreOrder(struct BinaryTreeNode *root) {
    if(root) {
        printf("%d", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PreOrderNonRecursive (struct BinaryTreeNode *root) {
    stack<BinaryTreeNode*> S;
    
    while(1) {
        while(root) {
            // 현재 노드를 처리합니다.
            printf("%d", root->data);
            S.push(root);
            // 왼쪽 노드가 존재하면 스택에 담습니다.
            root = root->left;
        }
        if(S.empty())
            break;
        root = S.top();
        S.pop();
        // 현재 노드와 왼쪽 하위 트리 처리 완료, 오른쪽 하위 트리로 이동.
        root = root->right;
    }
}

//              1
//          2       3
//        4   5   6   7
// 중위 운행법(InOrder Traversal)
// 4, 2, 5, 1, 6, 3, 7
void InOrder (struct BinaryTreeNode *root) {
    if(root) {
        InOrder(root->left);
        printf("%d", root->data);
        InOrder(root->right);
    }
}

void InOrderNonRecursive(struct BinaryTreeNode *root) {
    stack<BinaryTreeNode*> S;
    
    while(1){
        while(root) {
            S.push(root);
            // 현재 노드를 스택에 담고 왼쪽 하위 트리로 이동합니다.
            root = root->left;
        }
        if(S.empty())
            break;
        root = S.top();
        S.pop();
        printf("%d", root->data); // pop을 수행한 후 현재 노드를 처리합니다.
        // 왼쪽 하위 트리와 현재 노드 처리 완료, 이제 오른쪽 하위 트리로 이동.
        root = root->right;
    }
}

//              1
//          2       3
//        4   5   6   7
// 후위 운행법(PostOrder Traversal)
// 4, 5, 2, 6, 7, 3, 1

void PostOrderNonRecursive (struct BinaryTreeNode *root) {
    stack<BinaryTreeNode*> S;
    while(1) {
        if(root != nullptr) {
            S.push(root);
            root = root->left;
        } else {
            if(S.empty()) {
                printf("Stack is Empty");
                return;
            } else if (S.top()->right == nullptr) {
                root = S.top();
                S.pop();
                printf("%d", root->data);
                if (root == S.top()->right) {
                    printf("%d", S.top()->data);
                    S.pop();
                }
            }
            if(S.empty())
                root = S.top()->right;
            else
                root = nullptr;
            
        }
    }
}

// 레벨 순서 운행법(Level Order Traversal)
// 1, 2, 3, 4, 5, 6, 7

void LevelOrder (struct BinaryTreeNode *root) {
    struct BinaryTreeNode *temp;
    queue<BinaryTreeNode*> Q;
    
    if(!root)
        return;
    
    Q.push(root);
    
    while(!Q.empty()) {
        temp = Q.front();
        Q.pop();
        // 현재 노드를 처리합니다.
        printf("%d", temp->data);
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);
    }
}

// 문제 5 이진 트리에 요소를 삽입하기 위한 알고르짐을 구하세요.

void InsertInBinaryTree(struct BinaryTreeNode *root, int data) {
    queue<BinaryTreeNode*> Q;
    struct BinaryTreeNode *temp;
    struct BinaryTreeNode *newNode;
    
    newNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    newNode->left = newNode->right = nullptr;
    if(!newNode) {
        printf("Memory Error");
        return;
    }
    
    if(!root) {
        root = newNode;
        return;
    }
    
    Q.push(root);
    while (!Q.empty()) {
        temp = Q.front();
        Q.pop();
        if(temp->left)
            Q.push(temp->left);
        else {
            temp->left = newNode;
            return;
        }
        if(temp->right)
            Q.push(temp->right);
        else {
            temp->right = newNode;
            return;
        }
    }
}

// 문제 9 트리를 삭제하는 알고리즘을 구하세요.
// 부모 노드를 삭제하기 전에 먼저 자식노드를 삭제해야 합니다. 정렬 작업이 필요없으므로 후위 운행법을 사용합니다.
// 저장 공간을 사용하여 다른 운행법으로도 트리를 삭제할 수 있습니다.

void DeleteBinaryTree(struct BinaryTreeNode *root) {
    if(root == nullptr)
        return;
    // 먼저 양쪽 하위 트리를 삭제합니다.
    DeleteBinaryTree(root->left);
    DeleteBinaryTree(root->right);
    // 하위 노드 삭제 후 현재 노드를 삭제합니다.
    free(root);
}

// 문제 10 이진 트리의 높이(또는 깊이)를 알아내는 알고리즘을 구하세요.
// 재귀적으로 주어진 노드의 왼쪽과 오른쪽 하위 트리의 높이를 계산하고 구한 높이 중 최대값에 1을 더하여
// 주어진 노드에 높이로 부여합니다. 이것은 트리의 전위 운행과 유사합니다.(그래프 알고리즘의 DFS와도 유사합니다.)

int HeightOfBinaryTree(struct BinaryTreeNode *root) {
    int leftheight, rightheight;
    if(root == nullptr)
        return 0;
    else {
        leftheight = HeightOfBinaryTree(root->left);
        rightheight = HeightOfBinaryTree(root->right);
        if(leftheight > rightheight)
            return(leftheight + 1);
        else return (rightheight + 1);
    }
}

// 문제 11 문제10을 재귀 호출없이 풀 수 있습니까?
// 레벨 순위 운행을 사용하여 풀 수 있습니다. 이것은 그래프 알고리즘의 BFS와 유사합니다.
// 제일 마지막 레벨은 NULL로 식별할 수 있습니다.

int FindHeightofBinaryTree(struct BinaryTreeNode *root) {
    int level = 1;
    queue<BinaryTreeNode*> Q;
    if(!root)
        return 0;
    Q.push(root);
    // 첫 번째 레벨 끝
    Q.push(nullptr);
    while(!Q.empty()) {
        root = Q.front();
        Q.pop();
        // 주어진 현재 레벨 완료.
        if(root == nullptr) {
            // 다음 레벨에 대한 표시.
            if(!Q.empty())
                Q.push(nullptr);
            level++;
        } else {
            if(root->left)
                Q.push(root->left);
            if(root->right)
                Q.push(root->right);
        }
    }
    return level;
}

// 문제 12 이진 트리의 가장 깊은 노드를 찾는 알고리즘을 작성하세요.



int main() {
    
    return 0;
}
