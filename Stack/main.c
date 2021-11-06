#include <stdio.h>
#include "stack.h"
int main() {
    int a[5]={1,4,20,2,200};
    pStack p;
    p=InitStack(a,0,5);
    printf("top is %d\n:",Top(p));
    printf("szie:%d\n",Size(p));
    Push(p,25);
    printf("after push top is %d\n:",Top(p));
    printf("szie:%d\n",Size(p));
    printf("pop top: %d\n",Pop(p));
    printf("szie:%d\n",Size(p));
    printf("after pop top is %d\n",Top(p));
    printf("szie:%d\n",Size(p));

    if(p) Destroy(p);
    return 0;
}
