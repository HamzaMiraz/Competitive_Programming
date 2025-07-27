#include<bits/stdc++.h>

using namespace std;


const int SIZE=110;

vector<int>graph[SIZE];
int vis[SIZE];
int dis[SIZE];

vector<vector<int>>LIST;
vector<int>cmpn_adj;
vector<int> BFS(int s)
{
    queue<int>Q;
    vis[s]=1;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();
        cmpn_adj.push_back(u);
        Q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];

            if(vis[v] == 1)
                continue;

            vis[v]=1;
            Q.push(v);
        }
    }
    return cmpn_adj;
}

int main()
{
    int V,E,i,j,u,v;
    while(scanf("%d%d",&V,&E)==2)
    {
        for(i=0;i<V+5;i++)
        {
            graph[i].clear();
            vis[i]=0;
            LIST.clear();
        }

        for(i=0;i<E;i++)
        {
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=1;i<=V;i++)
        {
            if(vis[i]==0)
            {
                cmpn_adj.clear();
                LIST.push_back(BFS(i));
            }
        }
        for(int i=0;i<LIST.size();i++)
        {
            for(int j=0;j<LIST[i].size();j++)
            {
                printf("%d ,",LIST[i][j]);
            }
            printf("\n");

        }
    }
    printf("\n");

    return 0;
}

/**
8 6

1 2
1 3
3 4
4 5
6 7
7 8
*/


