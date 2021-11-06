#include <stdio.h>
#include "queue.h"
int main() {
    int a[5]={55,664,157,1,46};
    pQue p=InitQueue();
    if(p!=NULL){
        for(int i=0;i<5;i++)
            Enqueue(p,a[i]);
    }

    printf("init queue,front is %d,rear is %d\n",Front(p),Rear(p));
    printf("size:%d\n",size(p));

    Dequeue(p);
    printf("init queue,front is %d,rear is %d\n",Front(p),Rear(p));
    printf("size:%d\n",size(p));


    if(p)   DestroyQueue(p);
    return 0;
}
