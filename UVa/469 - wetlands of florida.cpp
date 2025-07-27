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

int f[100][100];
int cnt;
char ar[100][100];
int xx[]= {-1,-1,-1,0,0,1,1,1};
int yy[]= {-1,0,1,-1,1,-1,0,1};

void dfs(int i,int j)
{
    int a,b;
    if(ar[i][j]=='W' && i>=0 && i<99 && j>=0 && j<99 && f[i][j]==0)
    {
        f[i][j]=1;
        cnt++;
        for(int k=0; k<8; k++)
        {
            a=i+xx[k];
            b=j+yy[k];
            dfs(a,b);
        }
    }
    return;
}

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
    int t,i,j,k,l;
    char m[104];
    scanf("%d\n\n",&t);

    while(t--)
    {
        gets(ar[0]);
        l=strlen(ar[0]);
        for(i=1; i<l; i++)
            gets(ar[i]);
        while(gets(m))
        {
            if(strlen(m)==0)break;
            cnt=0;
            memset(f,0,sizeof(f));
            sscanf(m,"%d %d",&i,&j);
            if(ar[i-1][j-1]=='W')
                dfs(i-1,j-1);
            printf("%d\n",cnt);
        }
        if(t>0)
            printf("\n");
    }
    return 0;
}
/*
1
LLLLLLLLL
LLWWLLWLL
LWWLLLLLL
LWWWLWWLL
LLLWWWLLL
LLLLLLLLL
LLLWWLLWL
LLWLWLLLL
LLLLLLLLL
3 2
7 5
*/



