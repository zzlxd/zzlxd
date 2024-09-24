#include <iostream>
#include<stdlib.h>
typedef struct tree{
    char data;
    struct tree *lchild,*rchild;
}*Bitree;
void visit_pre(Bitree &T){//先序遍历
    if(T){//T为空时则直接跳过
        printf("%c ",T->data);
        visit_pre(T->lchild);
        visit_pre(T->rchild);
    }
}
void visit_in(Bitree &T){//中序遍历
    if(T){
        visit_in(T->lchild);
        printf("%c ",T->data);
        visit_in(T->rchild);
    }
}
void visit_traverse(Bitree &T){//后序遍历
    if(T){
        visit_traverse(T->lchild);
        visit_traverse(T->rchild);
        printf("%c ",T->data);
    }
}
void CreateBitree(Bitree &T){
    char c;
    scanf("%c",&c);
    if(c=='.'){
        T=NULL;
    }
    else{
        T=(Bitree)malloc(sizeof(struct tree));

        T->data=c;
        CreateBitree(T->lchild);
        CreateBitree(T->rchild);
    }
}
int main() {
    Bitree T;
    T=(Bitree)malloc(sizeof (int ));
    CreateBitree(T);
    printf("please input:\n");
    printf("pre_visit:");
    visit_pre(T);//前序
    printf("\n");
    printf("in_visit:");
    visit_in(T);//中序
    printf("\n");
    printf("post_visit:");
    visit_traverse(T);//后序
    return 0;
}
