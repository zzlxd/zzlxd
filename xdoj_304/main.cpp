#include<stdio.h>
struct E
{
    int u;
    int v;
    int w;
}Edge[101];
int main()
{
    int n,m,i,vest[50],j,count,sv,su;
    E t;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        vest[i]=i;
    for(i=1;i<=m;i++)
        scanf("%d %d %d",&Edge[i].u,&Edge[i].v,&Edge[i].w);
    for(i=1;i<=m;i++)//将边按权值大小顺序排列
        for(j=1;j<m;j++)
            if(Edge[j].w>Edge[j+1].w)
            {
                t=Edge[j];
                Edge[j]=Edge[j+1];
                Edge[j+1]=t;
            }
    count=1;j=1;
    while(count<n)
    {
        if(vest[Edge[j].u]!=vest[Edge[j].v])
        {
            count++;
            if(Edge[j].u>Edge[j].v)
                printf("%d %d %d\n",Edge[j].v,Edge[j].u,Edge[j].w);
            else
                printf("%d %d %d\n",Edge[j].u,Edge[j].v,Edge[j].w);
            su=vest[Edge[j].u];sv=vest[Edge[j].v];
            for(i=1;i<=n;i++)
            {
                if(vest[i]==sv)
                    vest[i]=su;//两个集合统一编号
            }
        }
        j++;//扫描下一个边
    }
    return 0;
}
