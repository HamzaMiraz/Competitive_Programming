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

vector<int>Order;
vector<int>VV[105];
int col[105];
int V,E;

enum Color
{
    WHITE,
    GRAY,
    BLACK
};
void init()
{
    for(int i=1;i<=V;i++)
    {
        col[i]=WHITE;
        VV[i].clear();
    }
    Order.clear();
}

void DFS(int s)
{
    col[s]=GRAY;
    for(auto i:VV[s])
        if(col[i]==WHITE)
            DFS(i);
    col[s]=BLACK;
    Order.push_back(s);
}

int main()
{
//    freopen("10305.in", "r", stdin);  ///To read from a file.
//    freopen("out.txt","w",stdout);

    while(cin>>V>>E)
    {
        //if(V==0||E==0)break;
        init();
        int x,y;
        for(int i=0; i<E; i++)
        {
            cin>>x>>y;
            VV[y].push_back(x);
        }
        for(int i=1;i<=V; i++)
            if(col[i]==WHITE)
                DFS(i);
        for(auto i:Order)
            printf("%d ",i);
        printf("\n");
    }

    return 0;
}
