
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

struct Edge{
    int u, v, w;

    Edge(int ui, int vi, int wi){
        u = ui;
        v = vi;
        w = wi;
    }
};

const int Vertex_N = 10001;

vector<Edge>edgeList;
int rnk[Vertex_N];
int par[Vertex_N];
int E,C;

void init(int n)
{
    edgeList.clear();

    for(int i=1;i<=n;i++){
        rnk[i] = 0;
        par[i] = i;
    }
}

int findSet(int u){
    if(u != par[u]){
        par[u] = findSet(par[u]);
    }
    return par[u];
}

void makeLink(int setU, int setV)        /// Link + Union
{
    if(rnk[setU]> rnk[setV]){
        par[setV] = setU;
    }
    else {
        par[setU] = setV;
        if(rnk[setU]== rnk[setV]){
            rnk[setV]++;
        }
    }
}

bool com(Edge &a, Edge &b){
    return a.w < b.w;
}

int MST_Kruskal(){
    int sum = 0;

    sort(edgeList.begin(), edgeList.end(), com);

    for(int i=0;i<E&&edgeList[i].w<C;i++){
        int setU = findSet(edgeList[i].u);
        int setV = findSet(edgeList[i].v);

        if(setU != setV){
            sum += edgeList[i].w;
            makeLink(setU, setV);
            ///printf("%d->%d,",edg.u,edg.v);

        }
    }
    return sum;
}
int airport(int n){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(par[i]==i)
            cnt++;
    }
    return cnt;
}


int main()
{
//    freopen("in.in", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int V,t,tc=1;
    cin>>t;
    while(t--){
        cin>>V>>E>>C;
        {
            init(V);

            for(int i=0;i<E;i++){
                int u,v,w;

                cin>>u>>v>>w;
                edgeList.push_back({u,v,w});
            }

            int mstCost = MST_Kruskal();

            printf("Case #%d: %d %d\n",tc, mstCost+C*airport(V),airport(V));
            tc++;
        }
    }

    return 0;
}
