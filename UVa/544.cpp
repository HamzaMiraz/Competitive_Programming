#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
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

/*
    if(st.find(val)!=st.end())
    {

    }
*/


typedef long long LL;
const LL MOD = 1000000007;
const double EPS = 1e-7; ///1*10^-7
const int Size = 201;

int N,E;
string S,D;
int tsk=1;
struct Nod
{
  int u;
  int sd;
  Nod(int a,int b)
  {
      u=a;
      sd=b;
  }
  bool operator<(const Nod&b)const{
    return sd < b.sd;
  }
};

map<string,int>mp;
vector<int>V[Size];
vector<int>W[Size];
int dis[Size];
int par[Size];
bool vis[Size];

void Init()
{
    mp.clear();
    for(int i=1; i<=N;i++)
    {
        dis[i]=-1;
        par[i]=0;
        vis[i]=false;
        V[i].clear();
        W[i].clear();
    }
}
void Prims(int s)
{
    dis[s]=0;
    priority_queue<Nod>pq;
    pq.push(Nod(s,0));

    while(!pq.empty())
    {
        Nod a=pq.top();
        pq.pop();
        int u=a.u;
        int sd=a.sd;

        if(dis[u]<sd ||vis[u]==true)
            continue;
        vis[u]=true;
        for(int i=0; i<V[u].size();i++)
        {
            int v=V[u][i];
            int w=W[u][i];
            if(vis[v]==false&&dis[v] < w)
            {
                dis[v]= w;
                par[v]= u;
                pq.push({v,dis[v]});
            }
        }
    }

}

int Miniwight(int s,int e)
{
    int c=dis[e];
    while(s!=par[e])
    {
        e=par[e];
        if(c>dis[e])
            c=dis[e];
    }
    return c;
}
int main()
{
//    freopen("544.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    while(cin>>N>>E && N&&E)
    {
        Init();
        int c=1;
        for(int i=0;i<E;i++)
        {
            string u,v;
            int w;
            cin>>u>>v>>w;
            if(mp.find(u)==mp.end())
                mp[u]=c++;

            if(mp.find(v)==mp.end())
                mp[v]=c++;
            int  a=mp[u],b=mp[v];
            V[a].push_back(b);
            V[b].push_back(a);
            W[a].push_back(w);
            W[b].push_back(w);
        }
        cin>>S>>D;
        if(mp.find(S)==mp.end()||mp.find(D)==mp.end())
        {
            printf("Scenario #%d\n",tsk++);
            printf("0 tons\n");
            printf("\n");
            continue;

        }
        int  s=mp[S],d=mp[D];
        Prims(s);

        int Capacity=Miniwight(s,d);

        printf("Scenario #%d\n",tsk++);
        printf("%d tons\n",Capacity);
        printf("\n");
    }

    return 0;
}
