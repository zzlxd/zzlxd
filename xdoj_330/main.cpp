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
        else{
            init(T->lchild,n,T->data);
        }
    }
    else{
        T=(BiTree) malloc(sizeof (BiTNode));
        T->rchild=NULL;
        T->lchild=NULL;
        T->data=n;
        cout<<data<<endl;

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
            cout<<-1<<endl;

        }
        else{
            init(T,s,T->data);
        }
    }
    return 0;
}
