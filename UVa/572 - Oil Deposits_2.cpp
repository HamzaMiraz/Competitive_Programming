#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
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
int m,n;
char str[1005][1005];

int dx[]={1,1,1,-1,-1,-1,0,0};
int dy[]={1,0,-1,1,0,-1,1,-1};

void DFS(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        int X=x+dx[i];
        int Y=y+dy[i];
        if(X >= 0 && X <m && Y >= 0 && Y < n)
        {
            if(str[X][Y] == '@')
            {
                str[X][Y] = '*';
                DFS(X,Y);
            }
        }
    }
}
int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int c;
    while(scanf("%d %d",&m,&n) == 2)
    {
        if(m == 0 && n == 0)break;
        for(int i = 0; i < m;i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> str[i][j];
            }
        }
        c = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(str[i][j] != '*')
                {
                  str[i][j]='*';
                  DFS(i,j);
                  c++;
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}
