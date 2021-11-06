//
// Created by Boston on 2020/7/2.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
typedef int rank;

#define DEFAULT_CAP 5

typedef struct Vec{
    int *_elem;
    int _size;
    int _cap;
}*pVec;

typedef pVec pStack;

pStack InitStack(int *, rank, rank);

void Destroy(pStack);

void Push(pStack, int);

int Pop(pStack);

int Top(pStack);

int Size(pStack);

int Empty(pStack);

/**************** 向量接口 *************************/
pVec InitVec(int*,rank,rank);

void DestroyVec(pVec);

int val(pVec,rank);

void Expand(pVec);

int GetSize(pVec);

int GetValue(pVec,rank);

void SetValue(pVec,rank,int);

void Insert(pVec,rank,int);

int Remove(pVec,rank);

void Traverse(pVec,void (*visit)());




#endif //STACK_STACK_H
