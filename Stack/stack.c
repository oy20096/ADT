//
// Created by Boston on 2020/7/2.
//

#include "stack.h"
//
// Created by Boston on 2020/6/7.
//

#include "stack.h"
#include <stdlib.h>

#define MAX(a,b)    (a)>(b)?(a):(b)

pStack InitStack(int *a,rank lo,rank hi)
{
    return InitVec(a,lo,hi);
}

void Destroy(pStack p)
{
    DestroyVec(p);
}

void Push(pStack p, int e)
{
    Insert(p,GetSize(p),e);
}

int Pop(pStack p)
{
    int temp=val(p,GetSize(p)-1);
    Remove(p,GetSize(p)-1);
    return temp;
}

int Top(pStack p)
{
    return val(p,GetSize(p)-1);
}

int Size(pStack p)
{
    return GetSize(p);
}

int Empty(pStack p)
{
    if(p!=NULL) {
        if (p->_size == 0) return 1;
    }
    return 0;
}


/********************** 向量接口 *******************/
/* 需验证NULL */
int val(pVec p,int n)
{
    return (p->_elem)[n];
}

/* 倍增扩容 */
void Expand(pVec p)
{
    int n_cap;
    if(p!=NULL) {
        if (p->_size < p->_cap) return;
        n_cap = MAX(p->_cap, DEFAULT_CAP);
        p->_cap=n_cap*2;
        int *n = (int *) malloc(sizeof(int) * n_cap * 2);
        int *old = p->_elem;
        if(old!=NULL) {
            for (int i = 0; i < p->_size-1; i++)
                n[i] = old[i];
        }
        p->_elem = n;
        free(old);
        old = NULL;
    }
}

/* 基于复制的构造 */
pVec InitVec(int *a,rank lo,rank hi)
{
    pVec p=(pVec)malloc(sizeof(struct Vec));
    if(p!=NULL){
        p->_cap=MAX(DEFAULT_CAP,(hi-lo)*2);
        p->_size=0;
        int *n=(int *)malloc(sizeof(int)*p->_cap);
        if(n!=NULL){
            while(lo<hi) {
                Expand(p);
                n[p->_size++] = a[lo++];
            }
        }
        p->_elem=n;
    }
    return p;
}

void DestroyVec(pVec p)
{
    if(p!=NULL){
        free(p->_elem);
        p->_elem=NULL;
    }
    free(p);
    p=NULL;
}

int GetSize(pVec p)
{
    return p->_size;
}

int GetValue(pVec p,rank r)
{
    return val(p,r);
}

void SetValue(pVec p, rank r, int e)
{
    (p->_elem)[r]=e;
}

void Insert(pVec p,rank r,int e)
{
    if(p!=NULL){
        int size=p->_size++;
        if(r>size)  return;
        Expand(p);
        int *n=p->_elem;
        if(n==NULL) return;
        while(size>r)
        {
            n[size]=n[size-1];
            size--;
        }
        n[r]=e;
    }
}

static int RemoveSec(pVec p, rank lo, rank hi)
{
    int ret=0;
    if(p!=NULL){
        if(lo<0||hi>p->_size||lo>hi)  return 0;
        int *n=p->_elem;
        ret=hi-lo;
        if(n==NULL) return 0;
        for(int i=hi;i<p->_size;i++)
            n[lo++]=n[i];
        p->_size-=ret;
    }
    return ret;
}

int Remove(pVec p,rank r)
{
    int ret=0;
    if(p!=NULL) {
        if (p->_elem != NULL) {
            if(r<p->_size)  ret=val(p,r);
            RemoveSec(p, r, r + 1);
        }
    }
    return ret;
}

void Traverse(pVec p,void (*visit)())
{
    if(p!=NULL)
        if(p->_elem!=NULL){
            int *n=p->_elem;
            for(int i=0;i<p->_size;i++)
            {
                visit(n[i]);
            }
        }
}