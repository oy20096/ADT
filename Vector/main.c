#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#define SIZE 10

void PrintVal(int n)
{
    printf("%d->",n);
}

int main()
{
    int c;
    pVec p;
    int a[SIZE/2]={4,25,12,23,42};
    int b[SIZE]={32,355,23,21,23,46,3,2,12,99};
    p=InitVec(a,0,SIZE/2);//测试copy初始化
    if(p!=NULL){
        Traverse(p,PrintVal);
    }
    printf("\nsize:%d\n",GetSize(p));

    for(int i=0;i<SIZE;i++) {
        Insert(p, i, b[i]);//测试insert&expand
        c=val(p,p->_size-1);
    }
    Traverse(p,PrintVal);
    printf("\nsize:%d\n",GetSize(p));

    printf("remove:%d\n",Remove(p,1));//测试remove
    Traverse(p,PrintVal);
    printf("\nsize:%d\n",GetSize(p));

    int f=4;
    printf("%d in %d of p\n",f,Find(p,f));//测试Find
    printf("p has %d disordered pair\n",Disordered(p));//测试disordered
    Deduplicate(p);//测试去重
    Traverse(p,PrintVal);
    printf("\nafter deduplicate size:%d\n",GetSize(p));

    Sort(p);//测试排序
    Traverse(p,PrintVal);
    printf("\nsize:%d\n",GetSize(p));
    printf("p has %d disordered pair\n",Disordered(p));//测试disordered

    f=21;
    printf("before insert %d after %d of p\n",f,Search(p,21));
    Insert(p,10,f);
    Sort(p);
    printf("after insert & sort ");
    Traverse(p,PrintVal);
    printf("\nsize:%d\n",GetSize(p));
    printf("after insert %d after %d of p\n",f,Search(p,21));
    Uniquify(p);
    Traverse(p,PrintVal);
    printf("\nafter uniquify size:%d\n",GetSize(p));

    if(p!=NULL)   DestroyVec(p);
    return 0;
}
