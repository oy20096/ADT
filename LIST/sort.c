//
// Created by Boston on 2020/6/11.
//
#include "sort.h"
#include <stdlib.h>

void swap(pNode a,pNode b)
{
    int val=a->value;
    a->value=b->value;
    b->value=val;
}

void BubbleSort(DList *plist)
{
    pNode p,temp,last,sorted;
    sorted=GetLast(plist);
    p=GetFirst(plist);
    for(;sorted!=GetFirst(plist);sorted=last){
        for(temp=last=GetFirst(plist);temp!=sorted;temp=temp->Next)
        {
            if(temp->value>temp->Next->value){
                swap(temp,temp->Next);
                last=temp;
            }
        }
    }
}

static pNode search(int val,int r,pNode p)
{
    do{
        p=p->Prev;
        r--;
    }while(r>-1&&p->value>val);
    return p;
}

void InsertSort(DList *plist)
{
    pNode temp=GetFirst(plist);
    int numsize=plist->_size;
    for(int i=0;i<numsize;i++)
    {
        InsertA(plist,search(temp->value,i,temp),CreateNode(temp->value));
        temp=temp->Next;
        RemoveNode(plist,temp->Prev);
    }
}

