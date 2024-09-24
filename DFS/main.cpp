#include <iostream>
using namespace std;
#define Max 100
int arcs[Max][Max];
int vis[Max];
int n,m;

typedef struct list{
    int node;
    struct list *next;
}list;

int dfs(int i){
    vis[i]=1;
    cout<<i<<" ";
    for(int j=1;j<=n;j++){
        if(vis[j]==0&&arcs[i][j]==1){
            dfs(j);
        }
    }
    return 0;
}

int dfs(int i,list *link[]){
    vis[i]=1;
    cout<<i<<" ";
    while(link[i]->next != nullptr){
        if(vis[link[i]->next->node]==0){
            dfs(link[i]->next->node,link);
        }
        link[i]=link[i]->next;
    }
    return 0;
}

int main() {
    cin>>n>>m;
    list *link[n+1];
    for(int i=1;i<=n;i++){
        link[i] = new list;
        link[i]->node=i;
        link[i]->next = nullptr;
    }
    for(int i=1;i<=n;i++){
        for(int ii=1;ii<=n;ii++){
            cin>>arcs[i][ii];
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    for(int i=1;i<=n;i++){
        list *t=link[i];
        for(int ii=1;ii<=n;ii++){
            if(arcs[i][ii]==1){
                list *k = new list;
                k->node=ii;
                k->next = nullptr;
                t->next=k;
                t=t->next;
            }
        }
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,link);
        }
    }
    return 0;
}
