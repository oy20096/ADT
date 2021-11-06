# **栈**
#### **1.构造&析构**
&nbsp;栈的构造与析构均沿用向量
```c
typedef struct Vec{
    int *elem;
    int _size;
    int _cap;
}*pVec, *pStack;

//沿用基于复制的构造
pStack InitStack(int *a, rank lo, rank hi)
{
    return InitVec(a,lo,hi);
}

//析构一致
void DestroyStack(pStack p)
{
    DestroyVec(p);
}
```
#### **2.基本操作**
&nbsp;栈的基本操作包括：push();empty()/size();top();pop()，在使用top或pop前验证其是否为空  
```c
void push(pStack p, int e)
{
    Insert(p,Getsize(p),e);
}

int empty(pStack p)
{
    if(p->_size==0) return 1;
    return 0;
}

int size(pStack p)
{
    return p->_size;
}

int Top(pStack p)
{
    if(!empty(p))
        return (p->elem)[Getsize(p)-1];
    return 0;
}

int Pop(pStack p)
{
    int temp=0;
    if(!empty(p)){
        temp=(p->elem)[Getsize(p)-1];
        Remove(p,Getsize(p)-1);
    }
    return temp;
}
```