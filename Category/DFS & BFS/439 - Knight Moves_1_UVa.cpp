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

int q,dx[10]={2,2,-2,-2,1,-1,1,-1},dy[10]={1,-1,1,-1,2,2,-2,-2},ans;
bool vis[11][11];
int x2,y2;
bool in(int x,int y){

    return x>=1&&x<=8&&y>=1&&y<=8;

}
void dfs(int x,int y,int num,int p)
{
	if(p>q) return;
	if(x==x2 && y==y2)
	{
	    if(num<ans)ans=num;
		return;
	}
	for(int i=0;i<8;i++)
	{
		int px=x+dx[i],py=y+dy[i];
		if(!in(px,py) || vis[px][py]) continue;
	//	printf("(%d,%d) -> (%d,%d)\n",x,y,px,py);
		vis[px][py]=true;
		dfs(px,py,num+1,p+1);
		vis[px][py]=false;
	}
	return;
}
int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    int x1,y1;
	char s1[20],s2[20];

	while(scanf("%s%s",s1,s2)==2)
	{
		memset(vis,0,sizeof(vis));
		ans=1<<15;q=0;
		y1=s1[0]-'a'+1; x1=s1[1]-'0';
		y2=s2[0]-'a'+1; x2=s2[1]-'0';
		vis[x1][y1]=true;
		while(ans==1<<15)
		{
			dfs(x1,y1,0,0);
			q++;
		}
		printf("To get from %s to %s takes %d knight moves.\n",s1,s2,ans);
	}
	return 0;
}
