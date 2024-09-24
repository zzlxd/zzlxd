//
// Created by 86177 on 2023-10-14.
//
#include<stdio.h>
typedef struct{
    char data[100];
    int top=0;
}sqstack;//栈定义
int main(){
    sqstack input;//定义一个栈
    for(char c;c!='\n';){
        scanf("%c",&c);
        if(c=='\n') break;
        if(c==')'||c=='('||c=='['||c==']'||c=='{'||c=='}') {//如果不是括号直接跳过
            input.data[input.top]=c;
            if(c==')'){
                if(input.data[input.top-1]=='(')  input.data[input.top-1]='\0',input.top-=2;
                else {
                    printf("no");return 0;//如果右括号不与左括号 配对说明一定不配对
                }
            }
            else if(c==']'){
                if(input.data[input.top-1]=='[')  input.data[input.top-1]='\0',input.top-=2;
                else {
                    printf("no");return 0;
                }
            }
            else if(c=='}'){
                if(input.data[input.top-1]=='{')  input.data[input.top-1]='\0',input.top-=2;
                else {
                    printf("no");return 0;
                }
            }
            input.top++;
        }


    }
    if(input.top==0){//如果栈中无元素说明配对成功了
        printf("yes");
    }
    else if(input.top>0) printf("no");
    return 0;
}


