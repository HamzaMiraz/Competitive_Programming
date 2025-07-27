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

int p[1100];//object's value/profit
int wt[1100];//object's waight
int m[110];

int knapsack(int n, int W)
{
    int T[n+1][W+1];
 
    for (int j = 0; j <= W; j++) {
        T[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (wt[i-1] > j) {
                T[i][j] = T[i-1][j];
            }
            else {
                T[i][j] = max(T[i-1][j], T[i-1][j-wt[i-1]] + p[i-1]);
            }
        }
    }
    return T[n][W];
}

int main()
{
    
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);a

    int itm,cpt;///itm=number of itm,cpt=capacity
    int t;
    cin>>t;
    while(t--){
        cin>>itm;
        
        for(int i=0;i<itm;i++){
            cin>>p[i]>>wt[i];
        } 
        int sum=0,men;
        cin>>men;
        for(int i=0;i<men;i++){
            cin>>m[i];
            sum += knapsack(itm, m[i]);
        }
        cout<<sum<<endl;
    }
    
    return 0;
}
