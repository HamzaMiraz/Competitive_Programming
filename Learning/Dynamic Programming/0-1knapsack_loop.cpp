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

int val[1010];
int wt[1010];

// Total number of distinct items `n`
// Knapsack capacity `W`
int knapsack(int n, int W)
{
    // `dp[i][j]` stores the maximum value that can be attained with
    // weight less than or equal to `j` using items up to first `i` items
    int dp[n+1][W+1];

    for (int j = 0; j <= W; j++) {
        dp[0][j] = 0;
    }
    // memset (dp[0], 0, sizeof dp[0]);

    // do for i'th item
    for (int i = 1; i <= n; i++)
    {
        // consider all weights from 0 to maximum capacity `W`
        for (int j = 0; j <= W; j++)
        {
            // don't include the i'th element if `j-w[i-1]` is negative
            if (wt[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                // find the maximum value by excluding or including the i'th item
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
            }
        }
    }
    return dp[n][W];
}

// 0–1 Knapsack problem
int main()
{

//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int itm,cpt;///itm=number of itm,cpt=capacity
    while(cin>>itm>>cpt){

        for(int i=0;i<itm;i++){
            cin>>val[i]>>wt[i];
        }
        cout << "Knapsack value is " << knapsack(itm, cpt);
    }

    return 0;
}
