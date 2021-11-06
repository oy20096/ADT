//
// Created by Boston on 2020/6/7.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

typedef int rank;

typedef struct Vec{
    int _size;
    int cap;
    int *_elem;
} *pVec;

#define DEFUALT_CAP 5

pVec InitVec(int*,rank,rank);

void DestroyVec(pVec);

int val(pVec,rank);

void Expand(pVec);

int GetSize(pVec);

int GetValue(pVec,rank);

void SetValue(pVec,rank,int);

void Insert(pVec,rank,int);

int Remove(pVec,rank);

int Disordered(pVec);

void Sort(pVec);

rank Find(pVec,int);

rank Search(pVec,int);

void Deduplicate(pVec);

void Uniquify(pVec);

void Traverse(pVec,void (*visit)());

#endif //VECTOR_VECTOR_H
