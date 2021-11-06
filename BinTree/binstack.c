//
// Created by Boston on 2020/7/22.
//


//
// Created by Boston on 2020/6/7.
//

#include "binstack.h"
#include <stdlib.h>

#define MAX(a,b)    (a)>(b)?(a):(b)

pStack InitStack(void)
{
    pStack p=(pStack)malloc(sizeof(struct BinStack));
    if(p!=NULL){
        p->_size=0;
        p->top=NULL;
    }
    return p;
}

void ClearStack(pStack p)
{
    pNode node;
    while(!isEmpty(p))
    {
        node=Pop(p);
        free(node);
        node=NULL;
    }
}

void Destroy(pStack p)
{
    if(p){
        ClearStack(p);
    }
    free(p);
    p=NULL;
}

int GetSize(pStack p) {
    if (p != NULL) {
        return p->_size;
    }
    return 0;
}

pNode MakeStackNode(TreeNode node)
{
    pNode p=(pNode)malloc(sizeof(struct Node));
    if(p!=NULL){
        p->elem=node;
        p->down=NULL;
    }
    return p;
}

void Push(pStack p,pNode node)
{
    if(p!=NULL){
        node->down=Top(p);
        p->top=node;
        p->_size++;
    }
}

pNode Pop(pStack p)
{
    pNode node=p->top;
    if(!isEmpty(p)&&node!=NULL){
        if(GetSize(p)>1) {
            p->_size--;
            p->top = p->top->down;
            node->down = NULL;
        }
        else{
            p->_size--;
            p->top=NULL;
        }
    }
    return node;
}

pNode Top(pStack p)
{
    if(!isEmpty(p)){
        return p->top;
    }
}

int Size(pStack p)
{
    return GetSize(p);
}

int isEmpty(pStack p)
{
    if(p!=NULL) {
        if (p->top==NULL&&p->_size == 0) return 1;
    }
    return 0;
}
