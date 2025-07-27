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
int N;

int myMove[100],m;

LL memo[10000];  ///memoization

LL go(int c)
{
    if(c==N)return 1;
    if(c>N) return 0;

    if(memo[c] != -1)return memo[c];
    memo[c] = 0;

    for(int i=0;i<m;i++)
    {
        //deb(myMove[i]);
        memo[c]+=go(c + myMove[i]);///joto rookomer permutation possible and number gulo one more time thakte parbe
    }

    return memo[c];
}
int main()
{
//    freopen("dp1.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int n;
    int v;

    while(cin>>n>>m)
    {
        N = n;
        memset(memo, -1, sizeof memo);
        for(int i=0;i<m;i++)
        {
            cin>>myMove[i];
        }
        cout<<go(0)<<endl;
    }

    return 0;
}

