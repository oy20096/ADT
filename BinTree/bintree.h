//
// Created by Boston on 2020/7/9.
//

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

typedef struct TreeNode{
    int _value;
    struct TreeNode* lc;
    struct TreeNode* rc;
}*TreeNode;

typedef struct BinTree{
    int _size;
    TreeNode root;
    int _height;
    int _depth;
}*BinTree;

typedef int side_t;

enum SIDE{
    LS,
    RS
};

BinTree InitBinTree(void);

TreeNode CreateBinTree(int *a,int lo, int hi);

void DestroyBinTree(BinTree p);

TreeNode MakeNode(int val);

TreeNode root(BinTree p);

int size(TreeNode node);

TreeNode insertAsLC(TreeNode pnode,TreeNode node);

TreeNode insertAsRC(TreeNode pnode,TreeNode node);

TreeNode attachAsRC(TreeNode pnode, BinTree tree);

TreeNode attachAsLC(TreeNode pnode, BinTree tree);

int removeTree(TreeNode pnode,side_t);

//BinTree secedeTree(TreeNode pnode,side_t s);

void travLevel(BinTree p);

void travPre(BinTree p, int type, void (*visit)());

void travIn(BinTree p, int type, void (*visit)());

void travPost(BinTree p, int type, void (*visit)());

void sTravPre(TreeNode node,void (*visit)());

void sTravIn(TreeNode node,void (*visit)());

void sTravPost(TreeNode node,void (*visit)());






#endif //BINTREE_BINTREE_H
