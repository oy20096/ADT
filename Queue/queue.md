# **队列**
####**1.构造与析构**
&nbsp;队列的构造与析构均沿用列表
```c
typedef struct Node{
    int value;
    struct Node *Prev;
    struct Node *Next;
}pNode;
typedef struct{
    pNode head;
    pNode tail;
    int _size;
} DList, *pQue;

pQue InitQueue(){
    return InitList();
}
void DestroyQueue(){
    DestroyList();
}
```
####**2.基本操作**
&nbsp;1)size/empty，利用list函数完成
```c
int size(pQue p)
{
    return Getsize(p);
}
int empty(pQue p)
{
    return isEmpty(p);
}
```
&nbsp;2)Enqueue/Dequeue;Front/Rear,同样利用list函数完成
```c
void Enqueue(pQue p, int val)
{
    //入队，即从插入末元素
    InsertLast(p,CreateNode(val));
}
int Dequeue(pQue p)
{
    //出队，删除首元素并返回值
    int temp=GetFirst(p)->value;
    RemoveNode(p,GetFirst(p));
    return temp;
}

int Front(pQue p)
{
    //返回队首元素
    return GetFirst(p)->value;
}

int Rear(pQue p)
{
    return GetLast(p)->value;
}
```
