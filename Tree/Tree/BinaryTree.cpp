//
//  BinaryTree.cpp
//  Tree
//
//  Created by kim on 2017. 8. 27..
//  Copyright © 2017년 kim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.hpp"

BTreeNode *MakeBTreeNode(void)
{
    BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

BTData GetData(BTreeNode *bt)
{
    return bt->data;
}

void SetData(BTreeNode *bt, BTData data)
{
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
    return bt->left;
}

BTreeNode *GetRightSubTree(BTreeNode *bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
    if(main->left != NULL)
        free(main->left);
    
    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    if(main->right != NULL)
        free(main->right);
    
    main->right = sub;
}

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)        // 전위 순회 함수
{
    if(bt == nullptr)
        return;
    
    action(bt->data);                       // 전위 순회이므로 루트 노드 먼저 방문!
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)         // 중위 순회 함수
{
    if(bt == nullptr)
        return;
    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)       // 후위 순회 함수
{
    if(bt == nullptr)
        return;
    
    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);                       // 후위 순회이므로 루트 노드 나중 방문!
}

void DeleteTree(BTreeNode *bt)
{
    if(bt == nullptr)
        return;
    
    DeleteTree(bt->left);
    DeleteTree(bt->right);
    
    free(bt);
}


