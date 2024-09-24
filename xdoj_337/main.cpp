#include <iostream>
using namespace std;
int main() {
    int n;
    int m;
    int mm[100];
    cin>>n>>m;
    for(int i=0;i<n+m;i++){
        cin>>mm[i];
    }
    for(int i=0;i<n+m;i++){
        for(int j=0;i+j+1<n+m;j++){
            if(mm[j]>mm[j+1]){
                int k;
                k=mm[j];
                mm[j]=mm[j+1];
                mm[j+1]=k;
            }
        }
    }
    for(int i=0;i<m+n;i++){
        cout<<mm[i]<<" ";
    }
    return 0;
}
