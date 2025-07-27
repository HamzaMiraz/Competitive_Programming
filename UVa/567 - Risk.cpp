#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//For Debugging
#define debug(a...)          {cout<<" #--> ";dbg,a; cout<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;


#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
typedef long long LL;

vector<int>graph[21];

void bfs(int s, int d)
{
    queue< int >q;
    int col[50]={0};
    int dis[50];
    col[s]=1;
    dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        for(int l=0; l<graph[u].size(); l++)
        {
            int v = graph[u][l];
            if(!col[v])
            {
                col[v]=1;
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
        q.pop();
    }
   printf("%2d to %2d: %d\n", s, d, dis[d]);
}

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    int x, y, set=0;
    while(scanf("%d",&x)==1)
    {
        for(int j=0; j<x; j++)
        {
            scanf("%d",&y);
            graph[1].push_back(y);
            graph[y].push_back(1);
        }
        for(int i=2; i<=19; i++)
        {
            scanf("%d",&x);
            for(int j=0; j<x; j++)
            {
                scanf("%d",&y);
                graph[i].push_back(y);
                graph[y].push_back(i);
            }
        }
        int st, fin, n;
        scanf("%d",&n);
        printf("Test Set #%d\n",++set);
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&st, &fin);
            bfs(st,fin);
        }
       printf("\n");
       for(int i=0; i<21; i++)
       {
           graph[i].clear();
       }
    }
    return 0;
}
