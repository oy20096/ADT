# **vector 知识点**
#### **1.与数组区别**  
&nbsp;抽象和泛化，动态空间管理  
#### **2.向量的初始化与析构**  
&nbsp;1)初始化 copyfrom，从数组或其他向量获取元素进行初始化  
```c
//从num数组中复制[lo,hi)个元素到向量中,并返回
pVec InitVec(int *num,rank lo, rank hi)
{
    ...
    ...//申请内存
    while(lo<hi)
        _val[_size++]=num[lo++];//逐个复制
    ...
    return p;
}
```
&nbsp;2)析构，free指针并赋为NULL
```c
//析构向量
void DestroyVec(pVec p);
```
#### **3.扩容**
&nbsp; 采用倍增扩容策略
```c
//在每次插入元素前都需要条用expand防止溢出
void Expand(pVec p)
{
    ...
    if(_size<_cap) return;//未到达_cap则不扩
    _cap=2*max(DEFAULT,_cap);//倍增扩容
    for(...)
        new[i]=old[i];//申请新内存，复制老元素
    free(old);//释放老内存
    _val=new;//指向新内存
    ...
}
```
#### **4.插入与删除**
&nbsp; 1）插入，逐次向前直到秩r，插入元素
```c
//在秩为r的位置插入元素e，后驱全部后移,返回秩
Rank Insert(pVec p, Rank r, int e)
{
    ...
    if(r>=_size)    return -1;//超过元素个数，退出
    _size++;//增加元素个数
    Expand(p);//扩容
    for(int i=_size-1,i>r,i--)//直至i=r
    {
        _val[i]=_val[i-1];//逐个递减，后移元素
    }
    _val[r]=e;//插入元素
    return r;//返回秩
}
```
&nbsp; 2)移除，移除采用区间删除方式，单个元素删除调用区间删除：将从[hi,_size)的所有值，前移hi-lo个位置
```c
//移除秩为[lo,hi)的元素，后驱全部前移，返回删除元素个数
unsigned int RemoveSec(pVec p,Rank lo,Rank hi)
{
    Rank n=hi-lo;//删除元素个数
    if(lo<0||hi>=_size||n<0) return 0;//如果出现越界，直接返回
    ...
    while(hi<_size)//直到hi越界
    {
        _val[lo++]=_val[hi++];//逐个复制
    }
    _size=lo;//元素个数为最后lo的值
    return n;//返回删除元素个数
}

//删除单元素
int Remove(pVec p,Rank r)
{
    ...
    if(r<_size)    e=_val[r];//不越界，则备份值
    RemoveSec(p,r,r+1);//调用区间删除，删除单元素
    return e;//返回备份
}
```
#### **5.无序向量：顺序查找与去重操作**
&nbsp; 1)顺序查找，**从后往前**遍历[lo,hi)的所有元素，找到值为e的元素，返回秩，没有则返回-1
```c
//从后往前遍历[lo,hi)区间，直至找到该元素
Rank FindSec(pVec p,Rank lo,Rank hi,int e)
{
    ...
    while(hi>=lo)//直至hi<lo
    {
        if(_val[--hi]==e)//找到该元素，则返回秩
            return hi;
    }
    return -1;//找不到则返回-1
}

//在所有向量p中所有元素查找，调用区间顺序查找
Rank Find(pVec p,int e)
{
    return FindSec(p,0,_size,e);
}
```
&nbsp; 2)去重操作，去掉向量p中所有重复元素
```c
//去掉p中重复元素，返回删除元素个数
unsigned int Deduplicate(pVec p)
{
    ...
    int old_size=_size;
    Rank i=1;//从第二个元素开始
    while(i<_size)//直至i越界
    {
        //在秩为i的前驱中[0,i)找到是否有等于_val[i]的元素，有则删除i元素，没有则跳至i+1个元素再查找
        FindSec(p,0,i,_val[i])<0?i++:Remove(p,i);
    }
    return _size-old_size;//返回删除元素个数
}
```
#### **6.无序向量->有序向量：排序**
&nbsp; 向量常用排序算法：冒泡排序，选择排序，归并排序
```c
//接口
void Sort(pVec p)
{
    TYPESort(_val,_size);
}
//交换函数,传址
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
```  
&nbsp; 1)冒泡排序：遍历所有元素，比较相邻两个元素，发现逆序对，则交换，每一次排序确定一个元素的位置，需进行n次n-i的遍历
```c
//经典冒泡排序 复杂度：O(n^2)
void BubbleSort(int *num, int numsize)
{
    for(int i=0;i<numsize;i++)
    {
        //注意numsize-i-1，防止越界
        for(int j=0;j<numsize-i-1;j++)//双重循环，一个循环减少n的个数，另一循坏遍历n
        {
            if(num[j]>num[j+1])//发现逆序对，则交换
                swap(&num[j],&num[j+1]);
        }
    }
}

//优化1：提前结束，利用一个标志位表示是否有序，如果在一次遍历中，标志位提示一直有序，则证明该数组已经有序，不在进行交换
//最坏 O(n^2),最好O(n)
void BubbleSort(int *num, int numsize)
{
    int sorted;//有序标志位
    do{
        sorted=1;//每次进入循环，假设有序
        for(int i=0;i<numsize-1;i++)遍历n-i区间
        {
            if(num[i]>num[i+1]){//发现逆序对，则交换
                swap(&num[i],&num[i+1]);
                sorted=0;//标志位设为无序
            }
        }
        numsize--;//每次循环区间减一   
    }while(!sorted);   
}
//优化2：跳跃，利用一个参数last确定每次交换的位置，则交换位置的后驱是有序的，可以不进行遍历，每次将区间置为[0,last),即可完成跳跃排序
//最坏 O(n^2),最好O(n)
void BubbleSort(int *num,int numsize)
{
    //注意--numsize，防止越界
    for(int last=--numsize;numsize>0;numsize=last)//设定区间[0,n),n=last
    {
        for(int i=last=0;i<numsize-1;i++)//设定最后交换位置为0，遍历区间[0,n)
        {
            if(num[i]>num[i+1]){//发现逆序对，则交换
                swap(&num[i],&num[i+1]);
                last=i;//设定最后交换位置为i
            }
        }
    }
}
```
&nbsp; 2)选择排序：选择排序思想与冒泡排序一致，但利用参数确定最小值位置，每次设定区间只进行一次交换，减少交换次数，在常数项上降低复杂度
```c
//经典算法：设定least参数，每次设定区间交换一次，则i++后，每次设定时[0,i)为有序序列
void SelectionSort(int *num,int numsize)
{
    int least=0;
    //注意numsize-1，防止越界
    for(int i=0;i<numsize-1;i++,least=i)//设置区间(i,numsize),最小值设为元素i
    {
        for(int j=i+1;j<numsize;j++)//遍历元素i的后驱
        {
            if(num[least]>num[j])//发现比元素least更小的元素，则重置least位置
                least=j;   
        }
        swap(&num[i],&num[least]);//交换i与least
    }
}
```
&nbsp; 3)归并排序：
```c
//待补充
```

#### **7.有序向量：二分查找与跳跃去重**  
&nbsp; 1)二分查找：递归思想，取区间中点，对比目标元素与中点元素，在进入左右区间，递归对比
```c
//接口
Rank Search(pVec p,int e)
{
    return TYPESearch(_val,0,_size,e);
}

//经典算法：每次需进行1或2次对比，命中则返回秩，最坏情况一直递归至空集，未找到返回-1
//O(1.5logn)
Rank BinSearch(int *num,int lo,int hi,int e)
{
    while(hi>lo)//递归进行[lo,mi)中搜索,当hi=lo时退出
    {
        Rank mi=(lo+hi)>>1;//取中点
        if(e<num[mi]) hi=mi;//如果e小于中点元素，进入[lo,mi)
        else if(mum[mi]<e) lo=mi+1;//如果e大于中点元素，进入[mi+1,hi)
        else return mi;//如果e等于中点元素，返回mi
    }
    return -1;//找不到返回-1
}

//改进1：只进行一次对比，但不出现立即命中情况，一直需要递归至只剩一个元素，最好情况变差，最坏情况变好
Rank BinSearch(int *num,int lo,int hi,int e)
{
    while(hi-lo>1)//递归进行[lo,hi)搜索，当lo+1=hi时退出
    {
        Rank mi=(lo+hi)>>1;//取中点
        if(e<num[mi]) hi=mi;//如果e小于中点元素，进入[lo,mi)
        lo=mi;//如果e不小于中点元素，进入[mi,hi)
    }
    return e==num[lo]?lo:-1;//若递归后lo元素命中则返回lo，否则返回-1
}

//改进2：只进行一次对比，直至空集，
//O(logn)
Rank BinSearch(int *num,int lo,int hi,int e)
{
    while(hi>lo)//递归进行[lo,hi)搜索，当lo=hi时退出
    {
        Rank mi=(lo+hi)>>1;//取中点
        if(e<num[mi])   hi=mi;//如果e小于中点元素，进入[lo,mi):不大于e的区间
        lo=mi+1;//如果e不小于中点元素，进入[mi+1,hi)：不小于e的区间
    }
    return lo-1;//返回lo前一个元素
}
```
#### **8.遍历**
&nbsp; 将向量中所有元素进行visit函数
```c
void Traverse(pVec p,void (*visit)())
{
    ...
    for(int i=0;i<_size;i++)
        visit(_val[i]);
    ...
}
```
