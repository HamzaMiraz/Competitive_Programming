
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
/** ---- Paknami Ends ----*/

/*
    if(st.find(val)!=st.end())
    {

    }
*/


typedef long long LL;
const LL MOD = 1000000007;
const double EPS = 1e-7; ///1*10^-7
const int Size = 755;

int N,L;
int X[Size];
int Y[Size];
int par[Size];
int rnk[Size];

struct Nod
{
    int u,v;
    double w;
};
struct res{
    int p,q;
};
vector<Nod>V;
vector<res>R;
void init()
{
    V.clear();
    R.clear();
    for(int i=1; i<=N;i++)
    {
        par[i]=i;
        rnk[i]=0;
    }
}

int findSet(int a)
{
    if(a != par[a])
        par[a]=findSet(par[a]);

    return par[a];
}

int makeLink(int a, int b)
{
    int u=findSet(a);
    int v=findSet(b);

    if(u != v){
        if(rnk[u] > rnk[v])
            par[v]=u;
        else
        {
            par[u]=v;
            if(rnk[u]== rnk[v])
                rnk[v]++;
        }
        return 1;
    }
    return 0;
}

bool comV(Nod a, Nod b)
{
    return a.w < b.w;
}
bool comR(res a, res b)
{
    if(a.p != b.p)
        return a.p < b.p;
    return a.q < b.q;
}
double dis(int n,int m)
{
    int x=(X[n]-X[m]);
    int y=(Y[n]-Y[m]);

    return sqrt(x*x+y*y);
}

int main()
{
//    freopen("f1.txt","r",stdin);
//    freopen("341 - Non-Stop Travel.in","w",stdout);

    int tks,ks;
    scanf("%d",&tks);
    ks=tks;
    while(tks)
    {
        if(tks!=ks)
            printf("\n");
        tks--;
        scanf("%d",&N);
        init();
        for(int i=1; i<=N;i++)
            scanf("%d%d",&X[i],&Y[i]);

        scanf("%d",&L);
        int c=0;
        for(int i=0; i<L; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            c+=makeLink(u,v);
        }
        if(N-1==c)
        {
            printf("No new highways need\n");
            continue;
        }
        for(int i=1;i<=N;i++)
            for(int j=1+i;j<=N;j++)
            {
                double W=dis(i,j);
                V.push_back({i,j,W});
            }
        sort(V.begin(),V.end(),comV);

        for(auto it:V){
            if(makeLink(it.u,it.v))
                R.push_back({it.u,it.v});
            }

        sort(R.begin(),R.end(),comR);
        for(auto it:R)
            printf("%d %d\n",it.p,it.q);

//        printf("Case %d: ",ks++);
    }

    return 0;
}
