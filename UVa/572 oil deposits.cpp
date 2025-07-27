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
int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};

int bfs(int x,int y)
{
    if(x >= 0 && x <m && y >= 0 && y < n)
    {
        if(str[x][y] == '@')
        {
            str[x][y] = '*';
            for(int i=0;i<8;i++)
            {

                int r=x+dx[i];
                int c=y+dy[i];
                //printf("r=%d c=%d\n",r,c);


                bfs(r,c);

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
                  bfs(i,j);
                  c++;
                }
            }
        }
        printf("%d\n",c);
    }
    return 0;
}

