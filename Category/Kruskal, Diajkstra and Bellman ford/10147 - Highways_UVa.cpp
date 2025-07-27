#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <utility>
#include <functional>
#include <deque>544 - Heavy Cargo
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <assert.h>544 - Heavy Cargo

#include <unordered_set>
#include <unordered_map>

// #include <bits/stdc++.h>
using namespace std;


#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define PrintConP(mp)    {cout<<#mp<<" #=> ";for(auto &it: mp){cout<<it.first<<":"<<it.second<<", ";} cout<<endl;}
#define PrintCon(mp)    {cout<<#mp<<" #=> ";for(auto &it: mp){cout<<it<<", ";} cout<<endl;}
#define deb(a)      cout<<__LINE__<<"#-> "<<#a<<"  "<<a<<endl

#define debug(a...)          {cout<<" #--> ";dbg,a; cout<<endl;}
struct debugger
{
    ///Collected from rudradevbasak
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;

int smap[755][755];

struct Edge{
    int u, v;
    double  w;

    Edge(int ui, int vi, double wi){
        u = ui;
        v = vi;
        w = wi;
    }
};

const int Vertex_N = 101;

vector<Edge>edgeList;
int rnk[Vertex_N];
int par[Vertex_N];

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

void MST_Kruskal(){

    sort(edgeList.begin(), edgeList.end(), com);

    for(auto edg: edgeList){
        int setU = findSet(edg.u);
        int setV = findSet(edg.v);

        if(setU != setV){
            makeLink(setU, setV);
            printf("%d %d\n",edg.u,edg.v);
        }
    }
}

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int V,t,m,x,y,a,b,cnt=0;
    double w;
    vector<double>X,Y;
    //int X[1000],Y[1000];
    cin>>t;
    while(t--)
    {
        cin>>V;
        init(V);

        for(int i=0;i<V;i++){

            cin>>x>>y;
            X.push_back(x);
            Y.push_back(y);
            //X[i]=x;
            //Y[i]=y;
        }
        cin>>m;
        while(m--){
            cin>>a>>b;
            makeLink(a,b);
            ++cnt;
        }
        if(cnt==V-1)printf("No new highways need");

        else
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++)
            {
                w = sqrt((X[j]-X[i])*(X[j]-X[i]) + (Y[j]-Y[i])*(Y[j]-Y[i]));

            edgeList.push_back({i+1,j+1,w});
            }
        }
        MST_Kruskal();


        X.clear();
        Y.clear();
        edgeList.clear();
        if(t)puts("");
    }

    return 0;
}
