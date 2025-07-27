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
/*
    if(st.find(val)!=st.end())
    {

    }
*/

typedef long long LL;
const int Size = 7500;
const double EPS = 1e-7; ///1*10^-7
int N;

int myMove[10]={50,25,10,5,1};

int memo[Size][6];  ///memoization

int go(int dif_move,int crnt_pos)
{
    if(crnt_pos==N)return 1;
    if(crnt_pos>N) return 0;

    int &rf=memo[crnt_pos][dif_move];
    if(rf != -1)return rf;
    rf = 0;
    for(int i=dif_move;i<5;i++)
    {
        rf+=go(i,crnt_pos + myMove[i]);
    }
    return rf;
}
int main()
{
//    freopen("dp1.in","r",stdin);
//    freopen("out.txt","w",stdout);
    while(cin>>N)
    {
        memset(memo, -1, sizeof memo);

        cout<<go(0,0)<<endl;
    }

    return 0;
}

