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

char a[10000];

int main()
{

    int i,l,t;
    while(gets(a))
    {
        l=strlen(a);
        t=0;
        for(i=0;i<l;i++)
        {
            if(isalpha(a[i]) && !isalpha(a[i+1]))

            t++;
        }
        printf("%d\n",t);
    }
    return 0;
}


