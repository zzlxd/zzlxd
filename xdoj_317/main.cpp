#include <iostream>
#include<stdlib.h>
using namespace std;
typedef struct node{
    int n;
    struct node *lchild,*rchild;
}Bitree;

int main() {
    int n[1000];
    int io[100][1000]={0};
    int de[1000];
    for(int i=0;;i++){
        int count=1;
        scanf("%d",&n[i]);
        if(n[i]==0){
            break;
        }
        for(int o=0;o<n[i];o++){
            scanf("%d",&io[i][o]);
        }
        scanf("%d",&de[i]);
        for(int o=1;o<de[i];count*=2,o++);
        int dev=count-1;//dev代表前面所有元素，count代表当前层元素个数
        if(n[i]<dev){
            printf("EMPTY\n");
        }
        else{
            for(int o=0;o<count;o++){
                if(io[i][dev+o]==0){
                    break;
                }
                else {

                    printf("%d ",io[i][dev+o]);
                }

            }
            printf("\n");
        }

    }


    return 0;
}
