//
// Created by Boston on 2020/6/8.
//

#include "SearchAlgo.h"

int binsearch(int *a, int e, int numsize)
{
    int lo=0,hi=numsize,mi;
    while(hi>lo){
        mi=(hi+lo)>>1;
        if(e<a[mi])
            hi=mi;
        else lo=mi+1;
    }
    return lo-1;
}