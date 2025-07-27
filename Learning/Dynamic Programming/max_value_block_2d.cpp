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
const int Size = 10000;
char ar[Size][Size],n,m;
LL memo[Size][Size];
int go(int p,int q){

    if(p >= n || q >= m)return 0;

    LL &rf = memo[p][q];

    if(rf!=-1)return rf;
    if (ar[p][q]==0)
        return -1;
    int a = go(p+1,q)+ar[p][q];
    int b = go(p,q+1)+ar[p][q];

    rf=max(a,b);
    return rf;

}
int main()
{
//    freopen("mx2D.in", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    while(scanf("%d%d",&n,&m) == 2)
    {
        for(int i =0;i<n;++i)
            for(int j=0;j<m;j++)
                cin>>ar[i][j];

        memset(memo,-1,sizeof memo);
        int a = go(0,0);

        cout<<a<<endl;
    }
    return 0;
}
/**

4 3
-5 4 6
9 4 1
-8 5 1
10 7 3


      ****
 **    **
  ** ******
   ********
      ****
**/
