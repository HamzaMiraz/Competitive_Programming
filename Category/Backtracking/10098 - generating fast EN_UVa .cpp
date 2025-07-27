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

int n;
int Q[20];
char str[20];
bool vis[20];

void go(int depth)
{
    int i,j;
    if(depth==n+1)
    {
        for(i=1;i<=depth-1;i++)
            printf("%c",str[Q[i]]);
        printf("\n");
        return;
    }

    char pre[12],cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=1;j<depth;j++)
            if(Q[j]==i)
                break;
        if(j!=depth)
            continue;

        for(j=0;j<cnt;j++)
            if(str[i]==pre[j])
                break;
        if(j!=cnt)
            continue;

        if(vis[i]==false)
        {
            vis[i]=true;
            Q[depth] = i;
            go(depth+1);
            vis[i]=false;
            pre[cnt++]=str[i];
        }
    }
}

int main()
{
//freopen("1.in", "r", stdin);  ///To read from a file.
//freopen("out.txt", "w", stdout);  ///To write  a file.
    int Case;
    scanf("%d",&Case);

    while(Case--)
    {
        scanf("%s",str);
        n = strlen(str);
        sort(&str[0], &str[n]);
        memset(vis, false, sizeof vis);
        go(1);
        printf("\n");
    }
    return 0;
}
