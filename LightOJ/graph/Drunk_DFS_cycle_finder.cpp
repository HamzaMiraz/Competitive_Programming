#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxn=2e5+10;
vector<ll>g[mxn+10],cyl[mxn+10];
ll par[mxn+10];
ll vis[mxn+10],cnt;

int ks;
void cycle(ll snode,ll enode)
{
    cyl[cnt].push_back(enode);
    while(snode!=enode)
    {
        cyl[cnt].push_back(snode);
        snode=par[snode];
    }
    cyl[cnt].push_back(enode);
    ///reverse(vc[cnt].begin(),vc[cnt].end());
}
int flg;
void DFS(ll u){

    vis[u]=1;
    for(auto v:g[u]){
        if(vis[v]==0){
            par[v]=u;
            DFS(v);
        }
        else if(vis[v]==1){
            flg=1;
            return;
        }
    }
    vis[u]=2;/// u nodes all adj nodes r visited
}

int main()
{
    ///minimum three nodes make a cycle for this code
    ll V,E,u,v;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;E=n;
        for(int i=0;i<=10000+5;i++){
            vis[i]=0;
            par[i]=-1;
            g[i].clear();
            cyl[i].clear();
        }
        cin.ignore();
        int mrk=0;string x,y;
        map<string,ll>mp;
        for(ll i=0; i<E; i++)
        {
            cin>>x>>y;
            if(!mp[x])mp[x]=++mrk;
            if(!mp[y])mp[y]=++mrk;
            u=mp[x],v=mp[y];
            g[u].push_back(v);
            //g[v].push_back(u);
        }
        flg=0;
        for(ll i=1;i<=mrk;i++)
        {
            if(vis[i]==0)
                DFS(i);
            if(flg)break;
        }
        if(!flg)
        {
             cout<<"Case "<<++ks<<": Yes\n";
        }else{
            cout<<"Case "<<++ks<<": No\n";
        }
    }
    return 0;
}
/**
13 15

1 2
2 3
3 4
4 6
4 7
5 6
3 5
7 8
6 10
5 9
10 9
10 11
11 12
11 13
12 13

**/
