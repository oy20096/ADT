//
// Created by Boston on 2020/7/2.
//

#include "queue.h"
//
// Created by Boston on 2020/6/6.
//

#include "queue.h"
#include <stdlib.h>
#include <malloc.h>


static int isEmpty(DList *plist);

pQue InitQueue(void)
{
    return InitList();
}

void DestroyQueue(pQue p)
{
    DestroyList(p);
}

int empty(pQue p)
{
    return isEmpty(p);
}

int size(pQue p)
{
    return GetSize(p);
}

void Enqueue(pQue p, int e)
{
    InsertLast(p,CreateNode(e));
}

int Rear(pQue p)
{
    return GetLast(p)->value;
}

int Dequeue(pQue p)
{
    int temp=GetFirst(p)->value;
    RemoveNode(p,GetFirst(p));
    return temp;
}

int Front(pQue p)
{
    return GetFirst(p)->value;
}


/* 验证plist */
static int isEmpty(DList *plist)
{
    if(plist->_size==0&&plist->head->Next==plist->tail&&plist->tail->Prev==plist->head)
        return 1;
    return 0;
}

DList* InitList(void)
{
    DList *plist=(DList*)malloc(sizeof(DList));
    pNode head=CreateNode(0);//创建头节点，外部不可见
    pNode tail=CreateNode(0);//创建尾节点，外部不可见
    if(plist!=NULL){
        if(head!=NULL&&tail!=NULL){
            plist->_size=0;
            plist->head=head;
            plist->tail=tail;
            plist->head->Next=tail;
            plist->tail->Prev=head;
        }
    }
    return plist;
}

pNode CreateNode(int val)
{
    pNode p=(pNode)malloc(sizeof(struct Node));
    if(p!=NULL) {
        p->value = val;
        p->Prev = NULL;
        p->Next = NULL;
    }
    return p;
}

void FreeNode(pNode p)
{
    free(p);
    p=NULL;
}

/* 验证plist */
void ClearList(DList* plist)
{
    while(!isEmpty(plist)){
        RemoveNode(plist,GetFirst(plist));
    }
}

void DestroyList(DList *plist)
{
    if(plist!=NULL)
    {
        ClearList(plist);
        FreeNode(plist->head);
        FreeNode(plist->tail);
        free(plist);
        plist=NULL;
    }
}

pNode GetPrev(pNode p)
{
    if(p!=NULL){
        return p->Prev;
    }
    return NULL;
}

pNode GetNext(pNode p)
{
    if(p!=NULL){
        return p->Next;
    }
    return NULL;
}

/*使用前需验证p*/
int GetValue(pNode p)
{
    return p->value;
}

void SetValue(pNode p,int val)
{
    if(p!=NULL){
        p->value=val;
    }
}

/* 验证plist */
int GetSize(DList *plist)
{
    return plist->_size;
}

pNode GetFirst(DList *plist)
{
    if(plist!=NULL){
        if(!isEmpty(plist))
            return plist->head->Next;
    }
    return NULL;
}

pNode GetLast(DList *plist)
{
    if(plist!=NULL)
    {
        if(!isEmpty(plist))
            return plist->tail->Prev;
    }
    return NULL;
}

pNode InsertFirst(DList *plist,pNode new)
{
    return InsertA(plist,plist->head,new);//插入头节点后面
}

pNode InsertLast(DList *plist,pNode new)
{
    return InsertB(plist,plist->tail,new);//插入尾节点前面
}

pNode InsertA(DList *plist,pNode p,pNode new)
{
    if(plist!=NULL&&p!=NULL&&new!=NULL)
    {
        if(p==plist->tail)  return NULL;//尾节点为哨兵
        p->Next->Prev=new;
        new->Next=p->Next;

        p->Next=new;
        new->Prev=p;

        plist->_size++;
    }
    return new;
}

pNode InsertB(DList *plist,pNode p,pNode new)
{
    if(plist!=NULL&&p!=NULL&&new!=NULL)
    {
        if(p==plist->head)  return NULL;//头节点为哨兵
        p->Prev->Next=new;
        new->Prev=p->Prev;

        p->Prev=new;
        new->Next=p;

        plist->_size++;
    }
    return new;
}


int RemoveNode(DList *plist,pNode p)
{
    int e=p->value;
    if(plist!=NULL&&p!=NULL&&p!=plist->head&&p!=plist->tail)
    {
        p->Prev->Next=p->Next;
        p->Next->Prev=p->Prev;

        plist->_size--;
    }
    FreeNode(p);
    return e;
}



