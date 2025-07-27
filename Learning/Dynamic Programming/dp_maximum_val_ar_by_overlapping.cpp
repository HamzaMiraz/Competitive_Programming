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
const int Size = 100000;
LL ar[Size],n;
LL memo[Size];
int go(int p){

    if(p>=n)return 0;

    LL &rf = memo[p];

    if(rf!=-1)return rf;

    int a = go(p+1)+ar[p];
    int b = go(p+2)+ar[p];

    rf=max(a,b);
    return rf;

}
int main()
{
//  freopen("mxN.in", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    while(scanf("%d",&n) == 1)
    {
        for(int i =0;i<n;++i)
            cin>>ar[i];
        memset(memo,-1,sizeof memo);
        int a = go(0);
        memset(memo,-1,sizeof memo);
        int b = go(1);
        int ans = max(a,b);
        cout<<ans<<endl;
    }
    return 0;
}
/*

10
-1 2 -9 10 8 2 -11 -12 2 5

*/
