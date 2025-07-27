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

typedef long long LL;
const LL MOD = 1000000007;
const double EPS = 1e-7; ///1*10^-7
const int Size = 1001;
struct Wormhole
{
    int u,v,w;
};

vector<Wormhole>V;
int N,M;
int dis[Size];
const int oo=(1<<25);
bool Negative_Cycal;
void init()
{
    for(int i=0;i<N;i++)
        dis[i]=oo;
    V.clear();
}
bool BellmanFord(int s)
{
    dis[s]=0;
    for(int i=0;i<N;i++)
    {
        Negative_Cycal=false;

        for(auto it:V){
            if(dis[it.u] + it.w < dis[it.v])
            {
                dis[it.v]=dis[it.u] + it.w;
                Negative_Cycal=true;
            }
        }
    }
    return Negative_Cycal;
}
int main()
{
//    freopen("10305 - Ordering Tasks.in","r",stdin);
//    freopen("out.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        init();
        cin>>N>>M;
        int x,y,t;
        for(int i=0;i<M;i++)
        {
            Wormhole e;
            cin>>x>>y>>t;
            e.u=x;
            e.v=y;
            e.w=t;
            V.push_back(e);
        }
         if(!BellmanFord(0))
            printf("not ");
        printf("possible\n");

    }

    return 0;
}
