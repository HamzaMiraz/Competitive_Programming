#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <map>
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
const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 1e8+0.5;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int adj[100][100],node,edge;
int color[100];
int Time=1;
int startTime[100];
int finishTime[100];

void dfsVisit(int x){
    color[x] = GRAY;

    startTime[x]=Time;
    ++Time;

    for(int i=0;i<node;i++){
        if(adj[x][i]==1)///node x connected to node i
        {
            if(color[i]==WHITE){///node i not visited
                dfsVisit(i);
            }
        }
    }
    color[x]=BLACK;

    finishTime[x]=Time;
    ++Time;
}
void dfs(){
    for(int i =0;i<node;i++){
        color[i]=WHITE;
    }
    for(int i=0;i<node;i++){
        if(color[i]== WHITE)///node i not visited
        {
            dfsVisit(i);
        }
    }
}

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    while(scanf("%d%d",&node,&edge) ==2)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;///adj[v][u] = 1 for underected DFS
    }
    dfs();
    return 0;
}
