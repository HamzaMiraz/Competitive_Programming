#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/** ---- Paknami Starts ----*/
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
/** ---- Paknami Ends ----*/

/*
    if(st.find(val)!=st.end())
    {

    }
*/

typedef long long LL;
const double EPS = 1e-7; ///1*10^-7
#pragma comment(linker, "/STACK: 2000000")

const LL MOD = 1000000007;
const int Size = 100000;

vector<int>myMove;

LL memo[Size][11];  ///memoization

LL go(int c, int lastIndex)
{
    if(!c) return 1;
    if(c<0) return 0;

    LL &res = memo[c][lastIndex];
    if(res > -1)    return res;

    res = 0;

    for(int i=0;i<myMove.size();i++)
    {
        int mv = myMove[i];
        if(i!=lastIndex){
            res= (res + go(c - mv, i)) % MOD;
        }
    }

    return res;
}

int main()
{
//   freopen("dp_1_last.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int n,m;
    int v;

    while(cin>>n>>m)
    {
        myMove.clear();
        memset(memo, -1, sizeof memo);

        for(int i=0;i<m;i++){
            cin>>v;
            myMove.push_back(v);
        }
        cout<<go(n, m)<<endl;
    }

    return 0;
}
