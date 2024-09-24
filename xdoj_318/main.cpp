#include <iostream>
#include<cstdlib>
#include <cstring>
typedef struct tree{
    char data;
    struct tree *lchild,*rchild;
}tree,BiTree;
BiTree* serch(char *pre,char *in,int n){
    int i;
    char lpre[60], rpre[60];
    char lin[60], rin[60];
    int n1 = 0, n2 = 0;//n1记录前序遍历序列的左子树长度,n2则记录前序遍历序列的右子树长度
    int m1 = 0, m2 = 0;//m1记录中序遍历序列的左子树长度,m2记录中序遍历序列右子树长度
    if (n == 0)
    {
        return NULL;
    }
    BiTree* T = (BiTree*)malloc(sizeof(BiTree));//创立节点
    T->data = pre[0];                    // 当前根节点
    for (i = 0; i < n; i++)
    {
        if (i <= n1 && in[i] != pre[0])
        {                                 //中序遍历被根节点分开的左子树的点
            lin[n1++] = in[i];//获得中序遍历的左子树
        }
        else if (in[i] != pre[0])
        {                                 //右子树的点,注意是else if，因为这个时候i是大于n1的
            rin[n2++] = in[i];
        }
    }
    //分前序遍历序列,注意！这里从1开始循环，因为0号元素作为根
    for (i = 1; i < n; i++)
    {
        if (i<(n1 + 1))               // 这里n1+1是因为编号是从1开始的，共有n1个左子树
        {
            lpre[m1++] = pre[i];
        }
        else
        {
            rpre[m2++] = pre[i];     //  其余为右子树
        }
    }
    T->lchild = serch(lpre, lin, n1);
    T->rchild = serch(rpre, rin, n2);
    //通过若干次递归最后实现二叉树的还原
    return T;

}
void post_visit(BiTree *T){
    if(T==NULL) return;

    post_visit(T->lchild);
    post_visit(T->rchild);
    printf("%c",T->data);

}
int main() {
    char c_pre[100],c_in[100];
    BiTree *T=NULL;

    gets(c_pre);
    gets(c_in);
    T= serch(c_pre,c_in, strlen(c_pre));
    post_visit(T);
    return 0;
}