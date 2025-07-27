#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

//For Debugging
#define debug(a...)          {cout<<__LINE__<<"#--> ";dbg,a; cout<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;

typedef long long LL;
const int Size = 100;
const double EPS = 1e-7; ///1*10^-7

bool flag[10][10];
int dis[10][10];
queue<pair<int,int>>Q;
pair<int,int>p;
int row[]={-2,2,-2,2,-1,1,-1,1};
int clm[]={-1,-1,1,1,-2,-2,2,2};

void bfs(int a,int b)
{
    flag[a][b]=false;
    dis[a][b]=0;
    Q.push({a,b});
    while(!Q.empty())
    {
       p=Q.front();
        Q.pop();

        for(int i=0;i<8;i++)
        {
            int r=p.first+row[i];
            int c=p.second+clm[i];
            if(flag[r][c]!=true ||r<1||c<1||r>8||c>8)
                continue;

            flag[r][c]=false;
            dis[r][c]=1+dis[p.first][p.second];
            Q.push({r,c});
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int x,y,a,b;
    char n,m;
    while(4==scanf(" %d%d %d%d",&a,&b,&x,&y))
    {
//        getchar();
        for(int i=1;i<=8;i++)
            for(int j=1;j<=8;j++)
            {
                flag[i][j]=true;
                dis[i][j]=0;
            }
        bfs(a,b);
        printf("To get from (%d,%d) to (%d,%d) takes %d knight moves.\n",a,b,x,y,dis[x][y]);
    }

    return 0;
}

