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

using namespace std;

int par[200005];
int rnk[200005];

struct edge{
    int from, to, weight;

    Edge(int ui, int vi, int wi){
        from = ui;
        to = vi;
        weight = wi;
    }
};

vector<edge> edges;

void init(int V)
{
    int i;
    for(i = 0; i <= V; i++)
    {
        par[i] = i;
        rnk[i] = 0;
    }
    edges.clear();
}

int find_set(int u)
{
    if(u != par[u])
        par[u] = find_set(par[u]);
    return par[u];
}

void makelink(int setU, int setV)        /// Link + Union
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
bool com(edge &a, edge &b){
    return a.weight < b.weight;
}
int kruskal()
{
    int total;
    int u, v;
    int i;
    sort(edges.begin(), edges.end(),com);
    total = 0;
    for(i = 0; i < edges.size(); i++)
    {
        u = find_set(edges[i].from);
        v = find_set(edges[i].to);
        if(u != v)
        {

            total += edges[i].weight;
             makelink(u,v);
        }
    }
    return total;
}

int main()
{
//    freopen("1.in", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int V;
    int E;
    while(scanf("%d %d", &V, &E))
    {
        if(V==0 && E==0)break;

        long long total_cost = 0;
        init(V);
        for(int i=0;i<E;i++){
            int u,v,w;

            cin>>u>>v>>w;
            total_cost+=w;
            edges.push_back({u,v,w});
        }
        cout<<total_cost - kruskal()<<endl;
    }
    return 0;
}
