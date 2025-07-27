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
int N;

vector<int>myMove;

LL memo[Size];  ///memoization

LL go(int c)
{
    if(c==N)    return 1;
    if(c>N) return 0;

    LL &res = memo[c];
    if(res > -1)    return res;

    res = 0;

    for(auto mv: myMove){
        res= (res + go(c + mv)) % MOD;
    }

    return res;
}

int main()
{
//    freopen("dp1.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int n,m;
    int v;

    while(cin>>n>>m)
    {
        N = n;
        myMove.clear();
        memset(memo, -1, sizeof memo);

        for(int i=0;i<m;i++){
            cin>>v;
            myMove.push_back(v);
        }
        cout<<go(0)<<endl;
    }

    return 0;
}
