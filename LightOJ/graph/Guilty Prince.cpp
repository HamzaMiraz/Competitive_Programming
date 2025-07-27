#include<bits/stdc++.h>

using namespace std;

char grid[20][20];
int vis[20][20];
int W,H;
int ans;
int dy[]={+1,0,-1,0};
int dx[]={0,+1,0,-1};
void dfs(int y,int x)
{
    ++ans;
    vis[y][x]=1;
    for(int i=0;i<4;i++){
        int Y=y+dy[i];
        int X=x+dx[i];
        if(X<W && X>=0 && Y<H && Y>=0 && grid[Y][X]!='#' && !vis[Y][X]){
            dfs(Y,X);
        }
    }
}

int main()
{
//    freopen("dfs.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int t,cs=0;
    cin>>t;
    while(t--){
        scanf("%d%d",&W,&H);
        memset(vis,0,sizeof vis);
        ans=0;
        for(int i=0;i<H;i++)
            scanf("%s",grid[i]);
        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++){
                if(grid[i][j]=='@'){
                    dfs(i,j);
                    break;
                }
            }
            printf("Case %d: %d\n",++cs,ans);

    }

    return 0;
}
