#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
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

int n, p[20], sto[10];
void bt(int d, int i)
{
    if(d == 6)
    {
        printf("%d",sto[0]);
        for(i = 1; i < 6; i++)
        {
            printf(" %d", sto[i]);
        }
        puts("");
        return;
    }
    for(; i < n; i++)
    {
        sto[d] = p[i];
        bt(d+1, i+1);
    }


}

int main()
{
//    freopen("lottlo.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    int t = 0, i;
    while(scanf("%d", &n) == 1)
    {
        if(n==0)break;
        if(t>0)
           printf("\n");
        t++;
        for(i = 0; i < n; i++)
        {
            scanf("%d",&p[i]);
        }
        bt(0, 0);

    }
    return 0;
}
