#include <iostream>
#include <stdlib.h>
#include<time.h>
#include<fstream>
#include<algorithm>
using namespace std;
const string a=R"(D:\Ccode\Clion\sort_test\intfile.dat)";
void bubble(int a[],int n){
    clock_t start,finish;int compare=0;
    int duration;
    start=clock();
    int exchange=0;
    for(int i=0;i<n;i++){
        for(int j=0;i+j+1<n;j++){
            compare++;
            if(a[j]>a[j+1]){exchange++;
                int k=a[i];
                a[i]=a[i+1];
                a[i+1]=k;
            }
        }
    }
    finish=clock();
    duration=(int)(1000*finish-1000*start)/CLOCKS_PER_SEC;
    cout<<"bubble:"<<duration<<"ms"<<endl;
    cout<<"compare:"<<compare<<endl;
    cout<<"exchange"<<exchange<<endl;
}
void select(int a[],int n){
    clock_t start,finish;
    int duration;int exchange=0;int compare=0;
    start=clock();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            compare++;
            if(a[i]>a[j]){exchange++;
                int k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    finish=clock();
    duration=(int)(1000*finish-1000*start)/CLOCKS_PER_SEC;
    cout<<"select:"<<duration<<"ms"<<endl;
    cout<<"compare:"<<compare<<endl;
    cout<<"exchange"<<exchange<<endl;
}
void insert(int a[],int n){
    clock_t start,finish;
    int duration;
    start=clock();
    int temp;
    int j;
    int compare=0;
    int exchange=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            temp=a[i];
            for(j=i-1;j>=0&&temp<a[j];j--)
            {
                compare++;
                a[j+1]=a[j];exchange++;
            }
            a[j+1]=temp;
        }

    }
    finish=clock();
    duration=(int)(1000*finish-1000*start)/CLOCKS_PER_SEC;
    cout<<"insert:"<<duration<<"ms"<<endl;
    cout<<"compare:"<<compare<<endl;
    cout<<"exchange"<<exchange<<endl;
}
int main() {
    int n[10000];
    srand(time(0));
    for(int i=0;i<10000;i++){
        n[i]=rand();
    }
    ofstream outfile;
    ofstream clear;
    clear.open(a,ios::trunc);
    outfile.open(a,ios::out);
    for(int i=0;i<10000;i++){
        outfile<<n[i]<<endl;
    }
    int n_1[10000];
    for(int i=0;i<10000;i++){
        n_1[i]=n[i];
    }
    int n_2[10000];
    for(int i=0;i<10000;i++){
        n_2[i]=n[i];
    }
    outfile.close();
    bubble(n,10000);
    select(n_1,10000);
    insert(n_2,10000);


}
