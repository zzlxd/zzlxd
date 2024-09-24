#include<stdio.h>
#include<queue>
using namespace std;
#define MaxN 100
int G[MaxN][MaxN]; //邻接矩阵表示图
int inq[MaxN] = {false};  //标记数组
int connection = 0;  //连通分量
queue<int> que;  //队列声明
int n; //结点数

void BFSTrave();
void BFS(int u);

int main(){
    int i,j;
    //建立图
    scanf("%d", &n);
    for(i = 0; i < n; i ++){
        for(j = 0; j < n; j++){
            scanf("%d", &G[i][j]);
        }
    }
    //BFS输出结点及连通分量
    BFSTrave();
    printf("\n%d", connection);
}
void BFSTrave(){
    int u;
    for(u = 0; u < n; u++){
        if(inq[u] == false){  //若当前结点未被访问
            BFS(u);  //遍历其所在连通分量
            connection++; //连通分量数目+1
        }
    }
}
void BFS(int u){
    int v;
    que.push(u); //当前结点入队
    inq[u] = true;  //标记已访问
    printf("%d ", u+1);  //输出结点编号
    while(!que.empty()){
        u = que.front();
        que.pop();
        for(v = 0; v < n; v++){
            if(inq[v] == false && G[u][v] != 0){ //访问u未被访问过的邻接结点
                que.push(v);  //邻接结点入队
                inq[v] = true; //标记已访问
                printf("%d ", v+1); //输出结点编号
            }
        }
    }
}