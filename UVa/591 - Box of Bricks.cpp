#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

int fun(int n,int ar[50])
{
    int avg,i;
    int m=0;
    int sum=0;

    for(i=0;i<n;i++)
    {
        sum=sum+ar[i];
    }
    avg = sum/n;

    for(i=0;i<n;i++)
    {
        if(avg>ar[i])
        {
            m=m+avg-ar[i];
        }
    }

    return m;
}


int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    int n,avg,i,j,ar[50],m;
    int s=1;

    while(scanf("%d",&n) ==1 && n>0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }

        m=fun(n,ar);

        printf("Set #%d\nThe minimum number of moves is %d.\n\n",s++,m);
    }

    return 0;
}
