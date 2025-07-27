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
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <assert.h>

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


struct Nod{
    int u;
    double dis;

    Nod(int iU, double iDis){
        u = iU;
        dis = iDis;
    }

    bool operator<(const Nod& b) const{

        return dis > b.dis;
    }
};

struct Edge{
    int u, v;
    double w;

    Edge(int ui, int vi, double wi){
        u = ui;
        v = vi;
        w = wi;
    }
};

const int Vertex_N = 101;

vector<Edge>edgeList;
int rnk[Vertex_N];
int parent[Vertex_N];

const int oo = 1e8+0.5;

double dist[Vertex_N];
int par[Vertex_N];
vector<int>graph[Vertex_N];
vector<double>weight[Vertex_N],temp[Vertex_N];

void init(int n){
    edgeList.clear();
    for(int i=1;i<=n;i++){
        rnk[i] = 0;
        parent[i] = i;///call by make func in DSU

        dist[i] = oo;
        par[i] = -1;
        graph[i].clear();
        weight[i].clear();
        temp[i].clear();
    }
}

double dijkstra(int source, int destination,double mx_tmp){
    priority_queue<Nod>pq;

    dist[source] = 0;
    pq.push(Nod(source, 0));///pq.push({source, 0});

    while(!pq.empty()){
        Nod cur = pq.top();
        pq.pop();

        int u = cur.u;
        double uDist = cur.dis;

        if(dist[u] < uDist) {
            continue;
        }
        
        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            double edgeWeight = weight[u][i];
            if(temp[u][i]>mx_tmp)continue;

            if(dist[v] > uDist + edgeWeight){
                dist[v] = uDist + edgeWeight;
                par[v] = u;
                pq.push({v, dist[v]});
            }
        }
    }

    return dist[destination];
}

vector<int> getPaht(int source, int destination){
    int v = destination;
    vector<int>path;

    while(source != v){
        path.push_back(v);
        v = par[v];
    }

    path.push_back(source);

    reverse(path.begin(), path.end());

    return path;
}


int findSet(int u){   ///find parent of the set/group
    if(u != parent[u]){
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

void makeLink(int setU, int setV) ///Link + Union
{                                 ///connect two vartex + connect two set/group of vertex
    if(rnk[setU]> rnk[setV]){     ///set/group means a bunch of nodes they r connected
        parent[setV] = setU;
    }
    else {
        parent[setU] = setV;
        if(rnk[setU]== rnk[setV]){
            rnk[setV]++;
        }
    }
}

bool com(Edge &a, Edge &b){
    return a.w < b.w;
}

double MST_Kruskal(int source, int destination){
    int sum = 0;

    sort(edgeList.begin(), edgeList.end(), com);

    for(int i=0;i<edgeList.size();i++){

        ///if two vertex or groups root parent r same
        ///then it will be creat a cycle
        ///Then we won't add them
        ///else ↓
        if(findSet(edgeList[i].u) != findSet(edgeList[i].v)){
            makeLink(findSet(edgeList[i].u), findSet(edgeList[i].v));
            if(findSet(source)==findSet(destination)){
                double mx_tmp=edgeList[i].w;
                return mx_tmp;
            }

        }
    }
}

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int V, E,src,dst;

    while(cin>>V>>E)
    {
        init(V);
        cin>>src>>dst;
        for(int i=0;i<E;i++){
            int u,v;
            double t,d;

            cin>>u>>v>>t>>d;
            edgeList.push_back({u,v,t});//edgeList.push_back(Edge{u,v,t});
            graph[u].push_back(v);
            graph[v].push_back(u);
            temp[u].push_back(t);
            temp[v].push_back(t);
            weight[u].push_back(d);
            weight[v].push_back(d);
        }

        double mxtamp = MST_Kruskal(src,dst);
        double destination =dijkstra(src,dst,mxtamp);
        vector<int>path = getPaht(src, dst);

        for(int i=0;i<path.size();i++){
            cout<<path[i];
            if(i<path.size()-1)cout<<" ";
        }

        printf("\n%.1f %.1f\n",destination,mxtamp);
    }

    return 0;
}




