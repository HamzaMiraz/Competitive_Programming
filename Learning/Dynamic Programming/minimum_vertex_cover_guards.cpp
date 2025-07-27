
#include<bits/stdc++.h>
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
typedef long long LL;
const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 1e8+0.5;
#define MAXN 100
#define EMPTY_VALUE -1

int mem[MAXN][2];
int par[MAXN];

vector<int> edges[MAXN];

int f(int u, int isGuard){
    if (mem[u][isGuard] != EMPTY_VALUE) {
        return mem[u][isGuard];
    }

    int answer = isGuard;

    for(auto v: edges[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        if (isGuard == 0) {
            answer += f(v, 1);
        } else {
            answer += min(f(v, 1), f(v, 0));
        }
    }

    return mem[u][isGuard] = answer;
}

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    int n;
    while(scanf("%d",&n) ==1)
    memset(mem, -1, sizeof(mem));
    memset(par, -1, sizeof(par));

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int ans = 0;

    ans = min(f(0, true), f(0, false));
    cout<<ans<<endl;

    return 0;
}
/**
Sample Input->
*
8
0 1
0 2
1 3
1 4
5 2
4 6
4 7
**/
