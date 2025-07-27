#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <map>
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
const double EPS = 1e-7; ///1*10^-7

int map[10][10];
int visit[10][10];
int dist[10][10];
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};
char a[5];
int x2,y2;
struct node
{
	int x,y;
};
queue<node>q;
int bfs(node T)
{
	if(T.x==x2&&T.y==y2)
	{
		return dist[T.x][T.y];
	}
	else
	{
		while(!q.empty())
		{
			node m = q.front();
			q.pop();
			if(m.x==x2&&m.y==y2)
				return dist[m.x][m.y];
			for(int i=0; i<8; i++)
			{

				int xx = m.x+dx[i];
				int yy = m.y+dy[i];
				if(!visit[xx][yy]&&xx>0&&yy>0&&xx<=8&&yy<=8)
				{
					node n ;
					n.x = xx;
					n.y = yy;
					q.push(n);
					dist[xx][yy] = dist[m.x][m.y]+1;
					visit[xx][yy] = 1;
				}
			}
		}
	}
}
int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

	int x1,y1,i,j;
	while(gets(a))
	{
		y1 = a[0]-'a'+1;
		x1 = a[1]-'0';
		y2 = a[3]-'a'+1;
		x2 = a[4]-'0';
		//printf("%d %d %d %d\n",x1,y1,x2,y2);
		node T;
		T.x = x1;
		T.y = y1;
		memset(dist,0,sizeof(dist));
		memset(visit,0,sizeof(visit));
		q.push(T);
		bfs(T);
		printf("To get from %c%c to %c%c takes %d knight moves.\n",a[0],a[1],a[3],a[4],dist[x2][y2]);
		while(!q.empty())
		{
			q.pop();
		}
	}
	return 0;
}
