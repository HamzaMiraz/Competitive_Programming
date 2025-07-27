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

#define lock 1
#define unlock 0

LL memo[70][70][3];
int n,s;
LL way(int pos,int sqr,int prevLock){
    if(pos==n){
        if(sqr==s)return 1;
        else return 0;
    }
    LL &rf =memo[pos][sqr][prevLock];
    if(rf!=-1)return rf;

    if(prevLock==lock){
        rf=way(pos+1,sqr+1,lock)+way(pos+1,sqr,unlock);
    }
    else if(prevLock==unlock){
        rf=way(pos+1,sqr,lock)+way(pos+1,sqr,unlock);
    }
    return rf;
}

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    while(scanf("%d%d",&n,&s) == 2){
        if(n < 0 && s <0 )break;
        memset(memo,-1,sizeof memo);

        cout<<way(0,0,lock)<<endl;
    }
    return 0;
}

