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

int ar[100000];
int Tree[100000*4];

void build(int l,int r,int node_no)
{
    if (l == r) {
        Tree[node_no] = ar[l];
        return;
    }
    int Left = node_no * 2;
    int Right = node_no * 2 + 1;
    int mid = (l + r) / 2;
    build(l,mid,Left);
    build(mid + 1,r,Right);
//    Tree[node_no] = Tree[Left] + Tree[Right];
    Tree[node_no] = min(Tree[Left],Tree[Right]);
//    Tree[node_no] = max(Tree[Left],Tree[Right]);

}

int Query(int l,int r,int node_no,int s,int e)
{
    if(l==s && r==e)
        return Tree[node_no];
    int mid = (l+r)/2;
    if(e<=mid)
        return Query(l,mid,node_no*2,s,e);
    else if(s>mid)
        return Query(mid+1,r,(node_no*2)+1,s,e);
    else
    {
        int q1 = Query(l,mid,(node_no*2),s,mid);
        int q2 = Query(mid+1,r,(node_no*2)+1,mid+1,e);
//        return q1+q2;
        return min(q1,q2);
 //      return max(q1,q2);
    }
}

int main()
{
//    freopen("LO.in","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,e,n,s,x,ans,t,m,cas[500000];
    cin>>t;
    int c=1;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]);

            build(1,n,1);
        for(int i=1;i<=m;i++){
            scanf("%d%d",&s,&e);
            cas[i]= Query(1,n,1,s,e);
        }
        printf("Case %d:\n",c++);
        for(int i=1;i<=m;i++){
            cout<<cas[i]<<endl;
        }
        //cout<<endl;
    }

    return 0;
}
