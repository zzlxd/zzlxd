#include <iostream>
using namespace std;
int main() {
    int n[100];
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>n[i];
    }
    int swap=0;
    for(int i=0;i<a;i++){
        for(int o=0;a-i-o-1>0;o++){
            if(n[o]>n[o+1]){
                int k=n[o+1];
                n[o+1]=n[o];
                n[o]=k;
                swap++;
            }
        }
    }
    cout<<swap;
    return 0;
}
