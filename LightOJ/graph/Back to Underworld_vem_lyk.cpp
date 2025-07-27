#include<bits/stdc++.h>
using namespace std;

#define lyk 2
#define vem 3
const int SIZE=20005;

vector<int>graph[SIZE];
int vis[SIZE];
int vempayer,lyken;

void BFS(int s)
{
    queue<int>Q;
    vis[s]=vem;
    vempayer++;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];

            if(vis[v] != 0)
                continue;

            if(vis[u]==vem){
                vis[v]=lyk;
                lyken++;
            }
            else{
                vis[v]=vem;
                vempayer++;
            }
            Q.push(v);
        }
    }
}

int main()
{
//    freopen("in.tst", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    int E,i,j,u,v,ts;
    scanf("%d",&ts);
    for(int t=1;t<=ts;t++)
    {
        scanf("%d",&E);
        for(i=0;i<20005;i++)
        {
            graph[i].clear();
        }
        memset(vis,0,sizeof vis);

        for(i=0;i<E;i++)
        {
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int ans=0;
        for(int i=1;i<20005;i++){
            vempayer=0;
            lyken=0;
            if(vis[i]==0 && graph[i].size()>0){
                BFS(i);
            }
            ans+=max(lyken,vempayer);
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}