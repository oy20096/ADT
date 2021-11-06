//
// Created by Boston on 2020/6/6.
//

#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
#include "List.h"

#define SIZE 10

void PrintList(int val)
{
    printf("%d->",val);
}

int main(void)
{
    DList *plist;
    pNode temp;
    plist=InitList();
    int a[SIZE]={3,4,4,1,7,32,42,51,32,32};
    if(plist!=NULL) {
        for (int i = 0; i < SIZE; i++) {
            InsertLast(plist, CreateNode(a[i]));
        }
    }
    printf("Init:");
    Traverse(plist,PrintList);
    printf("\n");

    InsertFirst(plist,CreateNode(5));
    printf("after insert first:");
    Traverse(plist,PrintList);
    printf("\n");

    InsertLast(plist,CreateNode(100));
    printf("after insert last:");
    Traverse(plist,PrintList);
    printf("\n");

    temp=FindinAll(plist,42);
    if(temp!=NULL)  PrintList(temp->Next->value);
    printf("\n");

    InsertA(plist,temp,CreateNode(43));
    printf("after insert after temp:");
    Traverse(plist,PrintList);
    printf("\n");

    InsertB(plist,temp,CreateNode(41));
    printf("after insert before temp:");
    Traverse(plist,PrintList);
    printf("\n");

    RemoveNode(plist,temp);
    printf("after remove temp:");
    Traverse(plist,PrintList);
    printf("\n");

    printf("remove %d elm after Deduplicate\n",Deduplicate(plist));
    printf("after deduplicate:");
    Traverse(plist,PrintList);
    printf("\n");

    InsertLast(plist,CreateNode(32));
    InsertLast(plist,CreateNode(5));
    printf("after insert 2 elm:");
    Traverse(plist,PrintList);
    printf("\n");

    printf("%d disordered pairs\n",disordered(plist));

    SortList(plist,InsertType);
    printf("after sorted:");
    Traverse(plist,PrintList);
    printf("\n");

    Uniquify(plist);
    printf("after uniquify:");
    Traverse(plist,PrintList);
    printf("\n");

    temp=SearchNode(plist,32);
    if(temp!=NULL) PrintList(temp->Next->value);
    printf("\n");



    if(plist)   DestroyList(plist);

    return 0;
}
