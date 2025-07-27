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

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int n;
    while(scanf("%d",&n) == 1)
    {
        if(n==0)
        {
            break;
        }
        printf("%d =",n);
        if(n<0)
        {
            printf(" -1 x");
            n=abs(n);
        }
        while(n%2==0)
        {

            if(n==2) printf(" 2\n");

            if(n!=2) printf(" 2 x");

            n=n/2;
        }
        for(int i=3;i<=sqrt(n);i=i+2)
        {
            while(n%i==0)
            {
                if(n==i) printf(" %d\n",i);
                if(n!=i) printf(" %d x",i);
                n=n/i;
            }
        }
        if(n>2 && n%2==1)
        {
            printf(" %d\n",n);
        }
    }
    return 0;
}
