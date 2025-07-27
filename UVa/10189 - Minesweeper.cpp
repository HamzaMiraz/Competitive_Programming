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


    int i,j,m,n,set=1;
    int value[104][104];
    char place[104][104],ch;
    while(scanf("%d%d%c",&n,&m,&ch)==3)
    {
        if(m==0 && n==0)
            break;
        if(set!=1)
            printf("\n");
        for(i=0;i<n;i++)
            gets(place[i]);
        memset(value,0, sizeof(value));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(place[i][j]=='*')
                {
                    value[i-1][j-1]+=1;
                    value[i-1][j]+=1;
                    value[i-1][j+1]+=1;
                    value[i][j+1]+=1;
                    value[i+1][j+1]+=1;
                    value[i+1][j]+=1;
                    value[i+1][j-1]+=1;
                    value[i][j-1]+=1;
                }
            }
        }
        printf("Field #%d:\n",set);
            set+=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(place[i][j]=='*')
                    printf("*");
                else
                    printf("%d",value[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
