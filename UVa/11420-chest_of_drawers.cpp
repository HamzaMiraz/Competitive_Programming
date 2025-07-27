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


enum Stpose
{
    UnLocked,
    Locked
};

LL dp [70] [2] [70];
int n, s;

LL way (int pos, Stpose prev, int cntSecure)
{
    //if ( pos == n ) return cntSecure == s ? 1 : 0;
    if(pos==n){
        if(cntSecure==s)return 1;
        else return 0;
    }

    LL &rf=dp [pos] [prev] [cntSecure];
    if ( rf != -1 ) return rf;

    rf = 0;

    if ( prev == UnLocked ) {
        rf += way(pos + 1, UnLocked, cntSecure);
        rf += way(pos + 1, Locked, cntSecure);
    }
    else if ( prev == Locked ) {
        rf += way(pos + 1, UnLocked, cntSecure);
        rf += way(pos + 1, Locked, cntSecure + 1);///drawer jadi eakta lock er por r eakta lock thakle amra secure 1 barabo
    }
    return rf;
}

int main ()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    while ( scanf ("%d %d", &n, &s) ) {
        if ( n < 0 && s < 0 ) break;

        memset(dp, -1,sizeof dp);

        printf ("%lld\n", way (0, Locked, 0));
    }

    return 0;
}
