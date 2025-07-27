#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include<map>
#include<sstream>
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

using namespace std;

char maps[111][111];
int  used[111][111];

int dx [] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy [] = {0, 1, 0, -1, 1, 1, -1, -1};
int dfs(int x, int y, int n, int m)
{
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (maps[x][y] != 'W' || used[x][y]) return 0;
	used[x][y] = 1;
	int sum = 1;
	for (int i = 0 ; i < 8 ; ++ i)
		sum += dfs(x+dx[i], y+dy[i], n, m);
	return sum;
}

int main()
{
	int T,x,y,temp;
	scanf("%d",&T);getchar();
	for (int t = 1 ; t <= T ; ++ t)
    {
		temp = getchar();
		while (temp != 'W' && temp != 'L')
			temp = getchar();
		int count = 0;
		while (temp == 'W' || temp == 'L' )
        {
			ungetc(temp, stdin);
			gets(maps[count ++]);
			temp = getchar();
		}
		int length = strlen(maps[0]);
		while (temp >= '0' && temp <= '9')
        {
			ungetc(temp, stdin);
			scanf("%d%d",&x,&y);getchar();
			memset(used, 0, sizeof(used));
			printf("%d\n",dfs(x-1, y-1, count, length));
			temp = getchar();
		}
		if (t < T) printf("\n");
	}
	return 0;
}
