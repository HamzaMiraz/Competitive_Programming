#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <map>
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

int ar[110],N;

int go(int pos)
{
    if(pos>=N)
        return 0;

    int a = go(pos+1)+ar[pos];
    int b = go(pos+2)+ar[pos];

    return max(a,b);
}

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    while(scanf("%d",&N) ==1)
    {
        for(int i=0;i<N;i++)
            scanf("%d",&ar[i]);

        int a = go(0);
        int b = go(1);

        printf("Result is = %d\n",max(a,b));
    }
    return 0;
}
