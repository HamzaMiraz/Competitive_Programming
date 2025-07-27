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

struct Edge{
    double u, v, w;

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

double MST_Kruskal(){
    double sum = 0;

    sort(edgeList.begin(), edgeList.end(), com);

    for(auto edg: edgeList){
        int setU = findSet(edg.u);
        int setV = findSet(edg.v);

        if(setU != setV){
            sum += edg.w;
            makeLink(setU, setV);
        }
    }

    return sum;
}

int main()
{
// freopen("10034.in", "r", stdin);  ///To read from a file.
// freopen("out.txt", "w", stdout);  ///To write  a file.
    int V,t;
    double x,y,w;
    //vector<double>X,Y;
    double X[1000],Y[1000];
    cin>>t;
    while(t--)
    {
        cin>>V;
        init(V);

        for(int i=0;i<V;i++){

            cin>>x>>y;
//            X.push_back(x);
//            Y.push_back(y);
            X[i]=x;
            Y[i]=y;
        }

        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++)
            {
                w = sqrt((X[j]-X[i])*(X[j]-X[i]) + (Y[j]-Y[i])*(Y[j]-Y[i]));
//                printf("i=%d,j=%d,w=%.2lf\n",i,j,w);
//                printf(",X[j]=%.2lf-X[i]=%.2lf,Y[j]=%.2lf-Y[i]=%.2lf\n",X[j],X[i],Y[j],Y[i]);

            edgeList.push_back({i+1,j+1,w});
            }
        }

        double mstCost = MST_Kruskal();

        printf("%.2lf\n", mstCost);
//        X.clear();
//        Y.clear();
        edgeList.clear();
        if(t)puts("");
    }

    return 0;
}
