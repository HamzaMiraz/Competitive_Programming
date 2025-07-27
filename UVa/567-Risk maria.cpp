#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/** ---- Paknami Starts ----*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

//For Debugging
#define debug(a...)          {cout<<__LINE__<<"#--> ";dbg,a; cout<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;
/** ---- Paknami Ends ----*/

typedef long long LL;
const int Size = 100;
const double EPS = 1e-7; ///1*10^-7

vector<int>adj[Size];
int dis[Size];
bool col[Size];
int s,e;

void BFS(int s)
{
    queue<int>Q;

    dis[s]=0;
    col[s]=false;
    Q.push(s);

    while(!Q.empty())
    {
        int a=Q.front();
        Q.pop();
        for(int i=0; i<adj[a].size(); i++)
        {
            int b=adj[a][i];

            if(col[b])
            {
                col[b]=false;
                dis[b]=dis[a]+1;
                Q.push(b);
            }
        }
    }
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int tks=1,u,v,n;
    while(cin>>u)
    {
        printf("Test Set #%d\n",tks++);
        for(int i=1; i<20; i++)
            adj[i].clear();

        for(int i=1; i<20; i++)
        {
            if(i>1)
                cin>>u;
            for(int j=0; j<u; j++)
            {
                cin>>v;
                adj[i].push_back(v);
                adj[v].push_back(i);
            }
        }

        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>s>>e;
            for(int j=1; j<=20; j++)
            {
                col[j]=true;
                dis[j]=0;
            }
            BFS(s);

            printf("%2d to %2d: %d\n",s,e,dis[e]);
        }
        printf("\n");
    }


    return 0;
}
