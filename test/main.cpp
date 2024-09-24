#include<iostream>
using namespace std;
int main(){
    int (*fp)(char *);
    int *f(char*);
    char *a;
    char c='a';
    a=&c;
}
void g(const char *p){
    char c[100];
    p=c;
}