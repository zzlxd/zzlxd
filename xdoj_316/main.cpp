#include <iostream>
#include <stdlib.h>
#define M 2147483647
//typedef struct node{
//    char data;
//    struct node *lchild,*rchild;
//}Bitree;
int main() {

    int x[100],y[100];int c=0;
    for(int i=0;;i++){
        scanf("%d %d",&x[i],&y[i]);
        if(x[i]==0&&y[i]==0){
            break;
        }c++;
    }

    for(int i=0;i<c;i++){
        for(;;){
            if(x[i]<y[i]){
                if(y[i]%2==0){
                    y[i]/=2;
                }
                else{
                    y[i]=(y[i]-1)/2;
                }
            }
            else if(x[i]==y[i]){
                printf("%d\n",y[i]);
                break;
            }
            else{
                if(x[i]%2==0){
                    x[i]/=2;
                }
                else{
                    x[i]=(x[i]-1)/2;
                }
            }
        }

    }
    return 0;
}
