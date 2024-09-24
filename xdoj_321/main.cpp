#include <iostream>
using namespace std;
int vis[1000];int m,n;
int cite[1000][1000];
int dfs(int i){
    vis[i]=1;
    for(int j=1;j<=n;j++){
        if(vis[j]==0&&cite[j][i]==1){
            dfs(j);
        }
    }
}
int main() {

    cin>>n>>m;
    int j,k;
    for(int i=0;i<m;i++){
        cin>>j>>k;
        cite[j][k]=1;
        cite[k][j]=1;
    }
    int s=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){

           dfs(i);s++;
        }
    }
    cout<<s-1;
}
