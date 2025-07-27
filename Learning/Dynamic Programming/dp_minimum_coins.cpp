#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

//For Debugging
#define debug(a...)          {cout<<__LINE__<<"#--> ";dbg,a; cout<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;
/*
    if(st.find(val)!=st.end())
    {

    }
*/

typedef long long LL;
const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 1e8+0.5;

#define MAX_COIN 20
#define MAX_W 10000

int C[MAX_COIN];
int memo[MAX_COIN][MAX_W];
int NC;///NC = number of coin
int n;
int way(int i, int W) {///coin number = i
    if (W < 0) return oo;
    if (i == NC) {
        if (W == 0) return 0;
        return oo;
    }
    int &rf=memo[i][W];
    if (rf != -1) {
        return rf;
    }
//    int res_1 = 1 + way(i, W - C[i]);///we  can take a coin again and again
    int res_1 = 1 + way(i + 1, W - C[i]);///we  can't take a coin again
    int res_2 = way(i + 1, W);

    rf = min(res_1, res_2);

    return rf;
}
int main()
{
//    freopen("dp1.in","r",stdin);
//    freopen("out.txt","w",stdout);

    while(cin>>n>>NC)///NC = number of coin
    {
        memset(memo, -1, sizeof memo);

        for(int i=0;i<NC;i++)
        {
            cin>>C[i];
        }
        cout<<way(0,n)<<endl;
    }

    return 0;
}

