//
// Created by Boston on 2020/6/8.
//

#include "sort.h"

static void swap(int *a, int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubblesort(int *a, int numsize,int kind)
{
    int sorted;
    switch(kind) {
        case Jump:
        for (int last = --numsize; 0 < numsize; numsize = last) {
            for (int j = last = 0; j < numsize; j++) {
                if (a[j] > a[j + 1]) {
                    swap(&a[j], &a[j + 1]);
                    last = j;
                }
            }
        } break;
        case End:
            do{
        sorted=1;
        for(int i=0;i<numsize-1;i++){
            if(a[i]>a[i+1]){
                swap(&a[i],&a[i+1]);
                sorted=0;
            }
        }
        numsize--;
    }while(!sorted);
            break;
        case Classic:
            for(int i=0;i<numsize;i++){
                for(int j=0;j<numsize-i-1;j++){
                    if(a[j]>a[j+1])
                        swap(&a[j],&a[j+1]);
                }
            }
            break;

    }
}