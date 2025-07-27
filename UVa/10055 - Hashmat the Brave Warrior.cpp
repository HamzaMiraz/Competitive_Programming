#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

typedef long long LL;

int fun(int a,int b)
{
    int c;
    c=b-a;

    return c;

}


int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int a,b,c;
    while(scanf("%d%d",&a,&b) == 2)
    {
        if(a>=pow(2,32) || b>=pow(2,32) || a>b)
        {
            break ;
        }
        else
        {
            c=fun(a,b);
            printf("%d\n",c);
        }

    }
    return 0;
}

