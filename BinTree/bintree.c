//
// Created by Boston on 2020/7/9.
//

#include "bintree.h"
#include "binstack.h"
#include <stdlib.h>

BinTree InitBinTree(void)
{
    BinTree p=(BinTree)malloc(sizeof(struct BinTree));
    TreeNode root=(TreeNode)malloc(sizeof(struct TreeNode));
    if(p!=NULL&&root!=NULL){
        root->_value=0;
        root->lc=NULL;
        root->rc=NULL;

        p->_size=1;
        p->root=root;
        p->_depth=0;
        p->_height=-1;
    }
    return p;
}

TreeNode CreateBinTree(int *a,int lo,int hi)
{
    if(lo>hi)   return NULL;
    TreeNode node=MakeNode(a[(hi+lo)/2]);
    node->lc=CreateBinTree(a,lo,(lo+hi)/2-1);
    node->rc=CreateBinTree(a,(lo+hi)/2+1,hi);
    return node;
}

static void ClearBinTree(TreeNode node)
{
    if(node->lc){
        ClearBinTree(node->lc);
    }
    if(node->rc){
        ClearBinTree(node->rc);
    }
    free(node);
    node=NULL;
}

void DestroyBinTree(BinTree p)
{
    if(p->root)
    {
        ClearBinTree(p->root);
    }
    free(p);
    p=NULL;
}

int size(TreeNode node)
{
    int _size=1;
    if(node->lc)    _size+=size(node->lc);
    if(node->rc)    _size+=size(node->rc);
    return _size;

}

TreeNode MakeNode(int val)
{
    TreeNode node=(TreeNode)malloc(sizeof(struct TreeNode));
    node->lc=NULL;
    node->rc=NULL;
    node->_value=val;
    return node;
}

TreeNode root(BinTree p)
{
    if(p!=NULL)
        return p->root;
    return NULL;
}

//确定左孩子为空
TreeNode insertAsLC(TreeNode pnode,TreeNode node)
{
    if(pnode!=NULL&&node!=NULL)
    {
        if(pnode->lc==NULL){
            pnode->lc=node;
        }
    }
    return pnode->lc;
}

TreeNode insertAsRC(TreeNode pnode,TreeNode node)
{
    if(pnode!=NULL&&node!=NULL)
    {
        if(pnode->rc==NULL){
            pnode->rc=node;
        }
    }
    return pnode->rc;
}

TreeNode attachAsRC(TreeNode pnode, BinTree tree)
{
    if(pnode!=NULL&&tree!=NULL){
        if(pnode->rc==NULL){
            pnode->rc=tree->root;
            tree->root=NULL;
            free(tree);
            tree=NULL;
        }
    }
    return pnode;//返回接入点
}

TreeNode attachAsLC(TreeNode pnode, BinTree tree)
{
    if(pnode!=NULL&&tree!=NULL){
        if(pnode->lc==NULL){
            pnode->lc=tree->root;
            tree->root=NULL;
            free(tree);
            tree=NULL;
        }
    }
    return pnode;//返回接入点
}

static int removeAt(TreeNode node)
{
    if(!node)   return 0;
    int n=1+removeAt(node->lc)+removeAt(node->rc);
    free(node);
    node==NULL;
    return n;
}

int removeTree(TreeNode pnode, side_t s)
{
    int n=0;
    if(pnode!=NULL) {
        if (s == LS && pnode->lc != NULL){
            n=removeAt(pnode->lc);
        } else if (s==RS&&pnode->rc!=NULL){
            n=removeAt(pnode->rc);
        }
    }
    return n;
}


void retravPre(TreeNode node,void (*visit)())
{
    if(!node)   return;
    visit(node);
    retravPre(node->lc,visit);
    retravPre(node->rc,visit);
}

void visitAlongVine(TreeNode node, pStack p, void(*visit)())
{
    while(node){
        visit(node);
        Push(p,MakeStackNode(node->rc));
        node=node->lc;
    }
}

void stacktravPre(TreeNode node, void (*visit)())
{
    pStack s=InitStack();
    while(1)
    {
        visitAlongVine(node,s,visit);
        if(isEmpty(s)) break;
        node=Pop(s)->elem;
    }
}

void travPre(BinTree p, int type, void (*visit)())
{
    switch (type){
        case 0:
            retravPre(p->root,visit);
            break;
        case 1:
            stacktravPre(p->root,visit);
            break;
    }
}

void retravIn(TreeNode node,void (*visit)())
{
    if(!node)   return;
    retravIn(node->lc,visit);
    visit(node);
    retravIn(node->rc,visit);
}

void goAlongVine(TreeNode node,pStack s)
{
    while(node)
    {
        Push(s,MakeStackNode(node));
        node=node->lc;
    }
}

void stacktravIn(TreeNode node, void (*visit)())
{
    pStack s=InitStack();
    while(1){
        goAlongVine(node,s);
        if(isEmpty(s)) break;
        node=Pop(s)->elem;
        visit(node);
        node=node->rc;
    }
}

void travIn(BinTree p,int type, void (*visit)())
{
    switch (type){
        case 0:
            retravIn(p->root,visit);
            break;
        case 1:
            stacktravIn(p->root,visit);
            break;
    }
}

void retravPost(TreeNode node,void (*visit)())
{
    if(!node)   return;
    retravIn(node->lc,visit);
    retravIn(node->rc,visit);
    visit(node);
}

void goHLFL(TreeNode node,pStack s)
{
    while(node)
    {
        Push(s,MakeStackNode(node));
        node=node->lc;
    }
}

void stacktravPost(TreeNode node, void (*visit)())
{
    pStack s=InitStack();
    while(1){
        goAlongVine(node,s);
        if(isEmpty(s)) break;
        node=Pop(s)->elem;
        visit(node);
        node=node->rc;
    }
}

void travPost(BinTree p,int type, void (*visit)())
{
    switch (type){
        case 0:
            retravPost(p->root,visit);
            break;
        case 1:
            stacktravPost(p->root,visit);
            break;
    }
}

void sTravPre(TreeNode node,void (*visit)())
{
    TreeNode stack[15];
    int top=-1;
    TreeNode p=node;
    while(p!=NULL||top!=-1)
    {
        if(p!=NULL){
            stack[++top]=p;
            visit(p);
            p=p->lc;
        }
        else{
            p=stack[top--];
            p=p->rc;
        }
    }
}

void sTravIn(TreeNode node,void (*visit)())
{
    TreeNode stack[15];
    int top=-1;
    TreeNode p=node;
    while(p!=NULL||top!=-1)
    {
        if(p!=NULL){
            stack[++top]=p;
            p=p->lc;
        }
        else{
            p=stack[top--];
            visit(p);
            p=p->rc;
        }
    }
}

void sTravPost(TreeNode node, void (*visit)())
{
    TreeNode stack[15];
    int top=-1;
    int flag[15];
    TreeNode p=node;
    while(p!=NULL||top!=-1)
    {
        if(p!=NULL)
        {
            stack[++top]=p;
            p=p->lc;
            flag[top]=1;
        } else{
            if(flag[top]==1){
                p=stack[top];
                flag[top]=2;
                p=p->rc;
            } else if (flag[top]==2){
                p=stack[top--];
                visit(p);
                p=NULL;
            }
        }
    }
}


