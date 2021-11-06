//
// Created by Boston on 2020/6/6.
//

#include "List.h"
#include <stdlib.h>
#include <malloc.h>
#include "sort.h"


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

/* 返回在p节点n个前驱中，数据为val的最后一个节点的位置 , 0<=n<=rank(p)<_size,成功：该节点位置；失败：NULL*/
static pNode FindNode(pNode p, int n,int val)
{
    if(p!=NULL){
        while(n--)
        {
            if(val==(p=p->Prev)->value)
                return p;
        }
    }
    return NULL;
}

pNode FindinAll(DList *plist,int val) {
    if (plist != NULL&&!isEmpty(plist)) {
        return FindNode(plist->tail,plist->_size,val);
    }
    return NULL;
}

/* 去除重复元素，并返回删除元素的个数 */
int Deduplicate(DList *plist)
{
    pNode p,q;
    q=NULL;
    int size=0;
    if(plist!=NULL){
        p=GetFirst(plist);
        size=plist->_size;
        if(isEmpty(plist)) return 0;
        for(int i=0;p!=plist->tail;p=p->Next,q=FindNode(p,i,p->value))//?不进行全去重？
        {
            q!=NULL?RemoveNode(plist,q):i++;
        }
    }
    return size-plist->_size;
}

void Traverse(DList *plist,void (*visit)())
{
    pNode p;
    if(plist!=NULL)
    {
        if(isEmpty(plist))  return;
        p=GetFirst(plist);
        while(p!=plist->tail)
        {
            visit(p->value);
            p=p->Next;
        }
    }
}

void SortList(DList *plist,int type)
{
    if(plist!=NULL&&!isEmpty(plist)){
        switch (type)
        {
            case BubbleType:
               BubbleSort(plist);
                break;
            case InsertType:
                InsertSort(plist);
                break;
        }
    }
}

int disordered(DList *plist)
{
    int i=0;
    pNode p;
    if(plist!=NULL&&!isEmpty(plist)){
        p=GetFirst(plist);
        while(p!=plist->tail)
        {
            if(p->value>p->Next->value)
                i++;
            p=p->Next;
        }
    }
    return i;
}

static pNode search(int val,int r,pNode p)
{
    do{
        p=p->Prev;
        r--;
    }while(r>-1&&p->value>val);
    return p;
}

pNode SearchNode(DList *plist, int e)
{
    return search(e,plist->_size,plist->tail);
}

int Uniquify(DList *plist)
{
    pNode temp,p;
    int i=0;
    if(plist!=NULL&&!isEmpty(plist))
    {
        p=GetFirst(plist);
        temp=p->Next;
        while(temp!=plist->tail) {
            if (p->value == temp->value) {
                temp = temp->Next;
                RemoveNode(plist,temp->Prev);
                i++;
            }
            else{
                p=temp;
                temp=temp->Next;
            }
        }
    }
    return i;
}