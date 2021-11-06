#include <stdio.h>
#include "bintree.h"

void Print(TreeNode node)
{
    printf("%d -> ",node->_value);
}

int main() {
    BinTree p=InitBinTree();
    TreeNode node;
    int a[9] = {4, 2, 5, 8, 1, 6, 3, 7, 9};
    if(p!=NULL) {
        p->root=CreateBinTree(a,0,8);
        printf("root value: %d\n", p->root->_value);
        printf("_size: %d\n", size(p->root));
        travPre(p,0,Print);
        printf("\n");
        travPre(p,1,Print);
        printf("\n");

        travIn(p,0,Print);
        printf("\n");
        travIn(p,1,Print);
        printf("\n");

        travPost(p,0,Print);
        printf("\n");
        //travIn(p,1,Print);
        //printf("\n");

        sTravPre(p->root,Print);
        printf("\n");

        sTravIn(p->root,Print);
        printf("\n");

        sTravPost(p->root,Print);
        printf("\n");


    }
    return 0;
}
