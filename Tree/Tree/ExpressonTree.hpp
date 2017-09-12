//
//  ExpressonTree.hpp
//  Tree
//
//  Created by kim on 2017. 8. 27..
//  Copyright © 2017년 kim. All rights reserved.
//

#ifndef ExpressonTree_hpp
#define ExpressonTree_hpp

#include "BinaryTree.hpp"

BTreeNode *MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode *bt);

void ShowPrefixTypeExp(BTreeNode *bt);
void ShowInfixTypeExp(BTreeNode *bt);
void ShowPostfixTypeExp(BTreeNode *bt);

#endif /* ExpressonTree_hpp */
