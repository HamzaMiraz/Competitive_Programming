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
int const N_MAX = 15;

#define p2(a)   (1<<(a))

int mat[N_MAX][N_MAX];

int mm[1<<N_MAX][N_MAX];
int N;

int go(int msk, int curPos){
    bitset<4>bt(msk);
    cout<<bt<<endl;
    if(msk == (1<<(N))-1){///2^N -1
        return mat[curPos][0];///starting position
    }
    int &re = mm[msk][curPos];
    if(re>-1)   return re;

    re = 1<<30;
    for(int i=0;i<N;i++)
        if( (msk&(1<<i)) == 0)
        {
            //int newMask = msk | p2(i);
            //int newPosition = i;
            re = min(re, go(msk|(1<<i), i)+ mat[curPos][i]);///new mask = msk | p2(i),newPosition=i
        }

    return re;
}
int main()
{
//   freopen("bit.in", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.


    while(cin>>N)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                cin>>mat[i][j];

        memset(mm, -1, sizeof mm);
        int res = go(1, 0);

        cout<<res<<endl;
    }

}
/*
4
0 10 30 3
10 0 5 40
30 5 0 2
3 40 2 0
*/
