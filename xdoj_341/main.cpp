#include <iostream>
using namespace std;
int main() {
    int n;
    int m[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    if(m[0]>m[1]){
        int k;
        k=m[0];
        m[0]=m[1];
        m[1]=k;
    }
    for(int i=0;i<n;i++){
        cout<<m[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<3;i++) {
        for(int o=0;o+1+i<3;o++){
            if(m[o]>m[o+1]){

                int k;
                k=m[o+1];
                m[o+1]=m[o];
                m[o]=k;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<m[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<4;i++) {
        for(int o=0;o+1+i<4;o++){
            if(m[o]>m[o+1]){

                int k;
                k=m[o+1];
                m[o+1]=m[o];
                m[o]=k;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<m[i]<<" ";
    }

};
