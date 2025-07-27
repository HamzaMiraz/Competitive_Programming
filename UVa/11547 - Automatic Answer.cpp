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
    int t,n,i,sum;
    while(scanf("%d",&t) ==1)
    {
        for(i=0;i<t;i++)
        {
            scanf("%d",&n);
            sum=abs(((((((n*567)/9)+7492)*235)/47)-498)/10)%10;

            printf("%d\n",sum);


        }

    }
    return 0;
}
