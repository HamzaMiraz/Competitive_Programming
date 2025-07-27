#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
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

int ar[1001];
int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    int n,m,i,j,sum,t;
    double avg,p;
    while(scanf("%d",&n) ==1)
    {
        for(i=0;i<n;i++)
        {
            sum=0;
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&ar[j]);

                sum=sum+ar[j];
            }
            avg=sum/(double)m;
            t=0;
            for(j=0;j<m;j++)
            {
                if(ar[j]>avg)
                t++;
            }
            p=(t*100)/(double)m;
            printf("%.3lf%\n",p);

        }

    }
    return 0;
}
