#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct BiTNode{
    int data=0;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
BiTree init(BiTree &T,int n,int data){
    if(T){
        if(T->data<n){
            init(T->rchild,n,T->data);
        }
        if(T->data>n){
            init(T->lchild,n,T->data);
        }
    }
    else{
        T=(BiTree) malloc(sizeof (BiTNode));
        T->rchild=NULL;
        T->lchild=NULL;
        T->data=n;

    }



}
void pre(BiTree& T){
    if(T){
        cout<<T->data<<" ";
        pre(T->lchild);
        pre(T->rchild);
    }
}
void mid(BiTree& T){
    if(T){
        mid(T->lchild);
        cout<<T->data<<" ";
        mid(T->rchild);
    }
}
void tra(BiTree& T){
    if(T){

        tra(T->lchild);
        tra(T->rchild);
        cout<<T->data<<" ";
    }
}
int main() {
    BiTree T;

    T=(BiTree) malloc(sizeof (BiTNode));
    T->lchild=NULL;
    T->rchild=NULL;
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int s=0;
        cin>>s;
        if(i==0){
            T->data=s;
        }
        else{
            init(T,s,T->data);
        }
    }
    pre(T);
    cout<<endl;
    mid(T);
    cout<<endl;
    tra(T);
    return 0;
}
