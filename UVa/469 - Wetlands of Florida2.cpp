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

char m[105][105], u[105][105];
int ans;
void dfs(int x, int y)
{
    if(x < 0 || y < 0 || m[x][y] == 0)return;
    if(u[x][y] != 0 || m[x][y] != 'W')return;
    u[x][y] = 1;
    ans++;
    int i, j;
    for(i = -1; i <= 1; i++)
    {
        for(j = -1; j <= 1; j++)
        {
            dfs(x+i, y+j);

        }

    }

}
int main()
{
    int t, i, j;
    char str[105];
    scanf("%d ", &t);
    while(t--)
    {
        memset(m, 0, sizeof(m));
        int n = 0;
        while(gets(str))
        {
            if(str[0] == '\0')
                break;
            if(str[0] != 'W' && str[0] != 'L')
            {
                sscanf(str, "%d %d", &i, &j);
                memset(u, 0, sizeof(u));
                ans = 0;
                dfs(i-1, j-1);
                printf("%d\n", ans);
            }
            else
            {
                sscanf(str, "%s", m[n]);
                n++;
            }
        }
        if(t)
            puts("");
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
