//
// Created by Boston on 2020/6/7.
//

#include "vector.h"
#include "SearchAlgo.h"
#include "sort.h"
#include <stdlib.h>

#define MAX(a,b)    (a)>(b)?(a):(b)

static void swap(int *a, int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

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
        if (p->_size < p->cap) return;
        n_cap = MAX(p->cap, DEFUALT_CAP);
        p->cap=n_cap*2;
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
        p->cap=MAX(DEFUALT_CAP,(hi-lo)*2);
        p->_size=0;
        int *n=(int *)malloc(sizeof(int)*p->cap);
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

int Disordered(pVec p)
{
    int i=0,ret=0;
    if(p!=NULL) {
        if (p->_elem != NULL) {
            int *n=p->_elem;
            while(i<p->_size-1){
                if(n[i++]>n[i])
                    ret++;
            }
        }
    }
    return ret;
}

void Sort(pVec p)
{
    sortkind=Classic;
    if(p!=NULL){
        if(p->_elem!=NULL)
        {
            int *n=p->_elem;
            bubblesort(n,p->_size,sortkind);
        }
    }
}

rank Find(pVec p, int e)
{
    if(p!=NULL){
        if(p->_elem!=NULL){
            int *n=p->_elem;
            for(int i=p->_size-1;i>=0;i--)
            {
                if(n[i]==e) return i;
            }
        }
    }
    return -1;
}

static rank find(pVec p, int e,int hi)
{
    if(p!=NULL){
        if(p->_elem!=NULL){
            int *n=p->_elem;
            for(int i=hi-1;i>=0;i--)
            {
                if(n[i]==e) return i;
            }
        }
    }
    return -1;
}

rank Search(pVec p, int e)
{
    if(p!=NULL){
        if(p->_elem!=NULL){
            int *n=p->_elem;
                return binsearch(n,e,p->_size);
        }
    }
    return -1;
}

void Deduplicate(pVec p)
{
    int i=1;
    if(p!=NULL){
        if(p->_elem!=NULL){
            int *n=p->_elem;
            while(i<p->_size){
                find(p,n[i],i)<0?i++:Remove(p,i);
            }
        }
    }
}

void Uniquify(pVec p)
{
    int i=0,k=1;
    if(p!=NULL){
        if(p->_elem!=NULL){
            int *n=p->_elem;
            for(;k<p->_size;k++)
            {
                if(n[i]!=n[k]){
                    swap(&n[i+1],&n[k]);
                    i++;
                }
            }
        }
        p->_size=i+1;
    }
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