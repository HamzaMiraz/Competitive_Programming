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
double memo[104],ar[104];
int n;
double go(int l){
    if(l==n)
    return ar[l];

    double &rf=memo[l];
    if(rf!=-1)return rf;
    int k=min(6,n-l);
    rf =0;
    for(int i=l+1;i<=l+k;i++){
        rf += go(i)/k;
    }
    rf+=ar[l];
    return rf;
}

int main()
{
//    freopen("exvl.in", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int t,cas=1;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lf",&ar[i]);
            memo[i]=-1;
        }
        double ans = go(1);
        printf("Case %d: %.6lf\n", cas++, ans);


    }
    return 0;
}
