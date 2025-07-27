
//#include<bits/stdc++.h>
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

using namespace std;

#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//For Debugging
#define debug(a...)          {cout<<__LINE__<<" #--> ";dbg,a; cout<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;



#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define GCD(a,b)  __gcd(a,b)
#define LCM(a,b)  (a*b)/__gcd(a,b)
#define sqr(a)      ((a)*(a))
typedef long long LL;
const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 1e8+0.5;
int cost[100005][4],n;
int memo[100005][4];
int go(int i,int j){
    if(i>=n&&j>=3)return oo;
   // if(j>3 || i>n ||j<1)return oo;
    if(i==n &&j==2)return cost[i][j];

    int &rf=memo[i][j];
    if(rf!=-1)return rf;

    int a=oo,b=oo,c=oo,d=oo;

    if(j<3)a=go(i,j+1)+cost[i][j];
    if(i<n)b=go(i+1,j)+cost[i][j];
    if(i<n&&j<3)c=go(i+1,j+1)+cost[i][j];
    if(i<n&&j>1)d=go(i+1,j-1)+cost[i][j];

    return rf=min(min(a,b),min(c,d));
}
int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int t=1;
    while(scanf("%d",&n) ==1)
    {
        if(n==0)break;
        memset(memo,-1,sizeof memo);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
                scanf("%d",&cost[i][j]);

        printf("%d. %d\n",t++,go(1,2));
    }
    return 0;
}

