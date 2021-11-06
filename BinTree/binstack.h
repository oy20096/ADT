//
// Created by Boston on 2020/7/2.
//

#ifndef BINSTACK_BINSTACK_H
#define BINSTACK_BINSTACK_H

#include "bintree.h"

typedef struct Node{
    TreeNode elem;
    struct Node *down;
}*pNode;

typedef struct BinStack{
    int _size;
    pNode top;
}*pStack;

pNode MakeStackNode(TreeNode node);

pStack InitStack(void);

void Destroy(pStack);

void Push(pStack, pNode node);

pNode Pop(pStack);

pNode Top(pStack);

int Size(pStack);

int isEmpty(pStack);





#endif //BINSTACK_BINSTACK_H
