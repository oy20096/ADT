# **list 知识点**  
#### **1.列表的创建与析构**
&nbsp; 1)创建：列表带头尾节点，带头节点，两种构造
```c
#define DOUBLE 1

typedef struct Node{
    int val;//数据
    #if DOUBLE
    struct Node *Prev;//双向列表节点有前驱
    #endif    
    struct Node *Next;//节点后驱
} *pNode;

typedef struct List{
    pNode head;//头节点
    pNode tail;//如果有头尾，则头尾为哨兵；如果没有尾，则末元素为尾元素
    int _size;//元素个数
} DList;

//创建一个空列表，并返回其地址
DList* InitList(void)
{
    ...//为列表，头尾节点声请内存
    if(plist!=NULL&&head!=NULL&&tail!=NULL){
        plist->_size=0;//元素个数为0
        //头尾设置
        plist->head=head;
        plist->tail=tail;
        //头尾相连
        plist->head->Next=tail;
        plist->tail->Prev=head;
    }
    ...
}

//创造节点
pNode CreateNode(int val)
{
    pNode p=(pNode)malloc(sizeof(struct Node));
    if(p==NULL) return p;
    p->val=val;
    p->Prev=NULL;
    p->Next=NULL;
    return p;
}
```
&nbsp; 2)析构，调用ClearList清空列表所有元素，再释放头尾节点指针，最后释放列表指针
```c
//判断空列表
static int isEmpty(DList *plist)
{
    //当元素个数为0，且头尾连接时，为空列表
    if(plist->_size==0&&plist->head->Next==plist->tail&&plist->tail->Prev=plist->head)
        return 1;
    return 0;
}

//
void FreeNode(pNode p)
{
    free(p);
    p=NULL;
}

//清空列表
void ClearList(DList *plist)
{
    //循环删除首节点，直到列表为空
    while(!isEmpty(plist)){
        RemoveNode(plist,GetFirst(plist));
    }
}

//析构列表
void DestroyList(DList *plist)
{
    ClearList(plist);//清空
    FreeNode(plist->head);//释放头节点
    FreeNode(plist->tail);//释放尾节点
    free(plist);//释放列表指针
    plist=NULL;//指向空指针
}
```
#### **2.删除与插入**
&nbsp; 1)删除操作
```c
//删除列表的p元素
int RemoveNode(DList *plist,pNode p)
{
    int ret;
    if(plist!=NULL&&p!=NULL){
        ret=p->val;//拷贝值
        p->Prev->Next=p->Next;//前驱的后驱指向p的后驱
        p->Next->Prev=p->Prev;//后驱的前驱指向p的前驱
        plist->_size--;//列表元素个数-1
    }
    FreeNode(p);//释放p节点
    return ret;//返回拷贝值
}
```
&nbsp; 2)插入操作，分为两类，在节点p前插入及在节点p后插入
```c
//在节点p之前插入节点n
pNode InsertB(DList *plist, pNode p, pNode n)
{
    if(plist!=NULL&&p!=NULL&&n!=null){
        if(p==plist->head) return NULL;//头节点前不可插入
        
        p->Prev->Next=n;//p前驱的后驱指向n
        n->Prev=p->Prev;//n前驱指向p前驱
        
        p->Prev=n;//p前驱指向n
        n->Next=p;//n后驱指向p
        plist->_size++;//列表元素+1
    }
    return n;//返回节点n
}

//在节点p之后插入节点n
pNode InsertA(DList *plist, pNode p, pNode n)
{
    if(plist!=NULL&&p!=NULL&&n!=null){
        if(p==plist->tail)  return NULL;//尾节点后不可插入
        
        p->Next->Prev=n;//p后驱的前驱指向n
        n->Next=p->Next;//n后驱指向p后驱
        
        p->Next=n;//p后驱指向n
        n->Prev=p;//n前驱指向p
        plist->_size++;//列表元素+1
    }
    return n;//返回n节点
}

//衍生两个快速插入首节点与尾节点
//插入首节点
pNode InsertFirst(DList *plist, pNode n)
{
    return InsertB(plist,GetFirst(plist),n);
}

//插入尾节点
pNode InsertLast(DList *plist, pNode n)
{
    return InsertA(plist, GetLast(plist),n);
}
//其中
pNode GetFirst(DList *plist)
{
    return plist->head->Next;
}
pNode GetLast(DList *plist)
{
    return plist->tail->Prev;
}
```
#### **3.无序列表：查找与去重**
&nbsp; 1)查找，子函数为在节点p的前n个元素中查找值为e的元素，返回节点，未找到返回NULL  
全局查找，在列表中所有元素中查找值为e的元素  
以上皆返回其最后出现的位置
```c
//区间查找，使用条件，p!=head,0<n<=_size
pNode FindNode(pNode p,int n,int e)
{
    if(p!=NULL){
        while(n--)//直到n=0
        {
            if(e==(p=p->Prev)->val) return p;//p指向p的前驱，发现e则返回
        }   
    }
    return NULL;
}
//全局查找
pNode FindInAll(DList *plist,int e)
{
    if(plist!=NULL&&!isEmpty(plist))
    {
        return FindNode(plist->tail,plist->_size,e);//调用区间查找，节点为尾节点，查找个数为_size
    }
    return NULL;
}
```
&nbsp; 2)去重，去重算法与无序向量思想一致，在节点p的所有前驱中都没有重复，则p指向后驱，直到尾节点
```c
//返回删除的元素个数
int Deduplicate(DList *plist)
{
    if(plist==NULL||isEmpty(plist)) return 0;//如果列表为空则返回0
    pNode p=GetFirst(plist);//声明节点p指向首节点
    int size=plist->_size;//拷贝未去重前的元素个数
    //在p的前i个元素中，查找与p元素值相同的元素，并删除；若未发现，则p向后移，区间同样后移
    for(int i=0,pNode q=NULL;p!=plist->tail;p=p->Next,FindNode(p,i,p->val))
    {
        q==NULL?i++:RemoveNode(plist,q);
    }      
    
    return size-plist->_size;//返回前后列表元素个数差
}
```
#### **4.有序列表：查找与去重**
&nbsp; 1)查找：与无序列表一样，需要挨个对比查找，但返回定义不一样
```c
//在节点p的前n个元素中查找与e相等的元素，返回值不大于e的最后一个元素的位置
//使用条件：p!=head,0<n<=_size
pNode SearchNode(pNode p,int n,int e)
{
    do{
        p=p->Prev;//#p指向p前驱
        n--;
    }while(n>-1&&p->val>e);//直到越界或找到不大于e值的元素
    return p;//返回该节点
}
//在列表所有元素中查找
pNode SearchInAll(DList *plist,int e)
{
    if(plist!=NULL&&!isEmpty(plist)){
        //调用区间查找查找e
        return SearchNode(plist->tail,plist->_size,e);
    }
}
```
&nbsp; 2)去重：与有序向量一样，区间去重
```c
int Uniquify(DList *plist)
{
    int i=0;
    pNode p,temp;
    if(plist!=NULL&&!isEmpty(plist))
    {
        p=GetFirst(plist);//从首节点开始
        temp=p->Next;//temp始终指向p后驱
        while(temp!=plist->tail)//直到越界
        {
            if(p->val==temp->val){
                //如果p与p后驱值相同
                temp=temp->next;//指向p后驱的后驱
                RemoveNode(plist,temp->prev);//删除p的后驱
                i++;//删除元素+1
            }
            else{
                //不相同，则跳跃区间
                p=temp;//p指向p后驱
                temp=temp->Next;//temp指向p后驱
            }   
        }   
    }
    return i;
}
```
#### **5.无序列表->有序列表：列表的排序**
&nbsp; 对于列表而言，BubbleSort, SelectionSort同样使用，交换时只需交换节点的值；  
对于列表，插入排序是一种不适用于向量，但适用于列表的排序  
插入排序思想：扑克牌思想，p节点前缀为有序，后缀无序，从后缀中依次拿出一个元素，插入到有序前缀中相应的位置
```c
int disordered(DList *plist)
{
    int ret=0;
    pNode p=GetFirst(plist);
    while(p!=GetLast(plist)){
        if(p->val>p->Next->val)
            ret++;//逆序对+1
        p=p->Next;
    }
    return ret;
}

//排序接口
void SortList(DList *plist,int type)
{
    if(plist!=NULL&&!isEmpty(plist)){
        switch(type){
        case ...:
       ...break;
        case InsertType:
        InsertSort(plist);
        break;
        }
    }
}

//插入排序
void InsertSort(DList *plist)
{
    pNode p=GetFirst(plist)->Next;
    for(int i=1;p!=plist->tail;i++)//直到越界
    {
        //在p的前i个元素中查找值不大于p元素值的的节点，将p元素值作为新元素插入该节点后
        InsertA(plist,SearchNode(p,i,p->val),CreateNode(p->val));
        p=p->Next;//p指向p后驱
        Remove(plist,p->Prev);//删除已插入元素p
    }
}
```