#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
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

const int SIZE = 1000010;

vector<int>adj[SIZE];
queue<int>Q;

int k,V,E;
int inDegree[SIZE],TS[SIZE];

void BFS()
{
    int temp,u;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            temp = adj[u][i];
            inDegree[temp]--;
            if(inDegree[temp]==0)
            {
                TS[k++]=temp;
                Q.push(temp);
            }
        }
    }
//    for(int i=1;i<=V;i++)
//        if(inDegree[i]!=0)
//            TS[k++]=i;
}
int main(){
    int i,u,v;
    while(2==scanf("%d%d",&V,&E) && (V || E)){
        k = 0;
        for(i=0;i<=V;i++){
            inDegree[i]=0;
            TS[i]=0;
            adj[i].clear();
        }
        for(i=0;i<E;i++){
            scanf("%d%d",&v,&u);
            adj[v].push_back(u);///v->u
            inDegree[u]++;
        }
        for(i=1;i<=V;i++){
            if(inDegree[i] == 0){
                Q.push(i);
                TS[k++]=i;
            }
        }
        BFS();
    /// below code for spcific problem
        if(k == V){
            for(i=0;i<k;i++){
                printf("%d\n",TS[i]);
            }
        }
        else printf("IMPOSSIBLE\n");

    }
    return 0;
}

