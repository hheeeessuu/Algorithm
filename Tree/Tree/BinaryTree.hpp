//
//  BinaryTree.hpp
//  Tree
//
//  Created by kim on 2017. 8. 27..
//  Copyright © 2017년 kim. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

typedef int BTData;

typedef struct _bTreeNode {
    BTData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;

// - 이진 트리 노드를 생성하여 그 주소 값을 반환한다.
BTreeNode *MakeBTreeNode(void);
// - 노드에 저장된 데이터를 반환한다.
BTData GetData(BTreeNode *bt);
// - 노드에 데이터를 저장한다. data로 전달된 값을 저장한다.
void SetData(BTreeNode *bt, BTData data);

// - 왼쪽 서브 트리의 주소 값을 반환한다.
BTreeNode *GetLeftSubTree(BTreeNode *bt);
// - 오른쪽 서브 트리의 주소 값을 반환한다.
BTreeNode *GetRightSubTree(BTreeNode *bt);

// - 왼쪽 서브 트리를 연결한다.
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
// - 오른쪽 서브 트리를 연결한다.
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);

void DeleteTree(BTreeNode *bt);

#endif /* BinaryTree_hpp */
