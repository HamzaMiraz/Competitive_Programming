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
typedef long long LL;
const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 1e8+0.5;

#define MOVE 50
#define Waight 10000

int myMove[100],m;
int memo[MOVE][Waight];

int go(int i,int W) {
    if (W==0) return 1;
    if (i > m) return 0;

    int &rf=memo[i][W];
    if (rf!=-1) {
        return rf;
    }
    int way_1 = go(i+1,W);
    int way_2 = go(i+1,W-myMove[i]);/// one move can be use for only one time

    rf = way_1 + way_2;
    return rf;
}
int main()
{
//    freopen("dp1.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int n;
    while(cin>>n>>m)
    {
        memset(memo, -1, sizeof memo);
        for(int i=0;i<m;i++)
        {
            cin>>myMove[i];
        }
        cout<<go(0,n)<<endl;
    }

    return 0;
}

