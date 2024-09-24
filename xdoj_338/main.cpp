#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[106]={};

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int la=a[0];
    int j=n-1;
    for(int i=0;i<j;){
        while(i<j&&a[j]>=la)j--;
        int k;
        k=a[i];
        a[i]=a[j];
        a[j]=k;
        while(i<j&&a[i]<=la)i++;
        k=a[i];
        a[i]=a[j];
        a[j]=k;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
