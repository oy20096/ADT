//
// Created by Boston on 2020/7/2.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

typedef struct Node{
    int value;
    struct Node *Next;
    struct Node *Prev;
} *pNode;

typedef struct{
    pNode head;
    pNode tail;
    int _size;
} DList, *pQue;

pQue InitQueue(void);

void DestroyQueue(pQue);

void Enqueue(pQue, int);

int Rear(pQue);

int Dequeue(pQue);

int Front(pQue);

int empty(pQue);

int size(pQue);


/******************* 列表接口 ***************************/
/* 创建一个列表 */
DList* InitList(void);

/* 使用val值创建节点 */
pNode CreateNode(int val);

/* 释放一个节点 */
void FreeNode(pNode);

/* 获取p节点前驱 */
pNode GetPrev(pNode p);

/* 获取p节点后驱 */
pNode GetNext(pNode p);

/* 获取节点数据 */
int GetValue(pNode);

/* 设置节点数据 */
void SetValue(pNode,int);

/* 清空一个列表 */
void ClearList(DList*);

/* 销毁一个列表 */
void DestroyList(DList*);

/* 返回列表元素个数 */
int GetSize(DList*);

/* 返回首元素 */
pNode GetFirst(DList*);

/* 返回末元素 */
pNode GetLast(DList*);

/* 插入 */
pNode InsertFirst(DList*,pNode);

pNode InsertLast(DList*,pNode);

pNode InsertA(DList*,pNode,pNode);

pNode InsertB(DList*,pNode,pNode);

/* 删除元素 */
int RemoveNode(DList*,pNode);

#endif //QUEUE_QUEUE_H
