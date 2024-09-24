#include <iostream>
using namespace std;

int num[100][100];
int vis[100];
int n=0;
int dfs(int  i){
    vis[i]=1;
    for(int j=0;j<n;j++){
        if(vis[j]==0&&num[i][j]==1){
            cout<<j+1<<" ";
            dfs(j);
        }
    }
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        for(int o=0;o<n;o++){
            cin>>num[i][o];
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(vis[i]==0){

            cout<<i+1<<" ";
            count++;
            dfs(i);
        }
    }
    cout<<endl<<count;
    return 0;
}
