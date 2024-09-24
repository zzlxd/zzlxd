#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int m[100];
    int in=n/2;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    for(int i=0;i<in;i++){
        int num=0;
        int z[100];
        for(int o=0;i+o*in<n;o++,num++){
            z[num]=m[in*o+i];
//            cout<<o<<endl;
//            cout<<z[num]<<endl;
        }
            for(int ii=0;ii<num;ii++){
                for(int oo=0;ii+oo+1<num;oo++){
                    if(z[oo]>z[oo+1]){
                        int k;
                        k=z[oo];
                        z[oo]=z[oo+1];
                        z[oo+1]=k;
                    }
                }
            }
            for(int ii=0;ii<num;ii++){
                m[in*ii+i]=z[ii];
           //     cout<<ii<<" "<<z[ii]<<endl;
            }

    }
    for(int i=0;i<n;i++){
        cout<<m[i]<<" ";
    }
}
