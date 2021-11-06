#include <stdio.h>


#include <stdlib.h>
#include <stdio.h>
#include "math.h"

int DayInWeight(int *weights, int wd, int weightsSize)
{
    int wtd=0,day=0;
    for(int i=0;i<weightsSize;i++){
        wtd+=weights[i];
        if(wtd>wd) {
            wtd=0;
            i--;
            day++;
        }
        if(i==weightsSize-1)    day++;
    }
    return day;
}


void int2str_9(int num,char *str)
{
    str[9]='\0';
	for(int i=0;i<9;i++) {
        str[8 - i] = num % 10;
        num /= 10;
    }
}

int main(void)
{
    //int s[6]={3,2,2,4,1,4};
    //int a=DayInWeight(s,6,6);
    int num=500000000;
    char p[10]={0};
    int2str_9(num,p);
    printf("×ª»»ºóÎª%s\n", p);
    return 0;
}
