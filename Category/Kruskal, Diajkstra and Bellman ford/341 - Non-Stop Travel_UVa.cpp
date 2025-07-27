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

struct Nod{
    int u, dis;

    Nod(int iU, int iDis){
        u = iU;
        dis = iDis;
    }

    bool operator<(const Nod& b) const{
        return dis > b.dis;
    }
};

const int Vertex_N = 101;
const int oo = 1e8+0.5;

int dist[Vertex_N];
int par[Vertex_N];
vector<int>graph[Vertex_N];
vector<int>weight[Vertex_N];

void init(int n){
    for(int i=1;i<=n;i++){
        dist[i] = oo;
        par[i] = -1;
        graph[i].clear();
        weight[i].clear();
    }
}

int dijkstra(int source, int destination){
    priority_queue<Nod>pq;

    dist[source] = 0;
    pq.push(Nod(source, 0));

    while(!pq.empty()){
        Nod cur = pq.top();
        pq.pop();

        int u = cur.u;
        int uDist = cur.dis;

        if(dist[u] < uDist) {
            continue;
        }

        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            int edgeWeight = weight[u][i];

            if(dist[v] > dist[u] + edgeWeight){
                dist[v] = dist[u] + edgeWeight;
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

int main()
{
//    freopen("10034.in", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    int V, E, S, D ,t=1;///S=own vartex,D=terget vartex distence

    while(cin>>V){
        if(V==0)break;
        int u=1;
        init(V);
        for(int i=0;i<V;i++){
            cin>>E;
            for(int i=0;i<E;i++){
                int v,w;

                cin>>v>>w;

                graph[u].push_back(v);
                weight[u].push_back(w);
            }
            u++;
        }
        cin>>S>>D;


        int distance = dijkstra(S, D);

        vector<int>path = getPaht(S, D);
        printf("Case %d: Path =",t++);
        for(auto v: path) cout<<" "<<v;
        printf("; %d second delay\n", distance);
    }


    return 0;
}


