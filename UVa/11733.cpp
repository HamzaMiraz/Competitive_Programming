#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=100010;

struct node
{
    int u,v,cost;
}a[maxn];

int n,m,A,cnt,par[maxn],visited[maxn];
vector <int > v;

bool cmp(node p,node q)
{
    return p.cost<q.cost;
}

int Find(int x)
{
    if(x!=par[x]){
        par[x]=Find(par[x]);
    }
    return par[x];
}

void input()
{
    scanf("%d %d %d",&n,&m,&A);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].cost);
    }
    sort(a,a+m,cmp);
}

void initial()
{
    memset(visited,0,sizeof(visited));
    for(int i=0;i<=n;i++){
        par[i]=i;
    }
    v.clear();
    cnt=0;
}

void kru()
{
    for(int i=0;i<m;i++)
    {
        int p=Find(a[i].u),q=Find(a[i].v);
        if(p!=q)
        {
            par[p]=q;
            v.push_back(a[i].cost);
        }
    }
    for(int i=1;i<=n;i++){
        if(!visited[Find(i)]){
            visited[Find(i)]=1,cnt++;
        }
    }
}

void solve(int co)
{
    kru();
    int len=v.size(),t=len,sum=0;
    for(int i=0;i<len;i++)
    {
        if(v[i]>=A)
        {
            t=i;
            break;
        }
        sum+=v[i];
    }
    int num=cnt+len-t;
    sum+=num*A;
    printf("Case #%d: %d %d\n",co,sum,num);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int co=1;co<=T;co++)
    {
        input();
        initial();
        solve(co);
    }
    return 0;
}
