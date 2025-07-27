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

char c[10000];
int main()
{
    int n,i,j,b;

    while(gets(c))
    {
        n=strlen(c);
        b=-1;
        for(i=0;i<n;i++)
        {
            if(c[i]==' ')
            {

                for(j=i-1;j>b;j--)
                {
                    printf("%c",c[j]);
                }

                printf(" ");
               b=i;

            }

        }

        for(i=n-1;i>b;i--)
        {
            printf("%c",c[i]);
        }
        printf("\n");
    }
    return 0;
}
