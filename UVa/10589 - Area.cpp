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

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int N,a,M=0;
    double x,y,A;
    while(scanf("%d %d",&N,&a) == 2)
    {
        if(N==0 && a==0)break;
        for(int i=0;i<N;i++)
        {
            scanf("%lf %lf",&x,&y);
            if(x*x+y*y<=a*a && (x-a)*(x-a)+y*y<=a*a && x*x+(y-a)*(y-a)<=a*a && (x-a)*(x-a)+(y-a)*(y-a)<=a*a) ++M;
        }
        A=(M*a*a)/(double)N;

        printf("%0.5lf\n",A);


    }
    return 0;
}

