#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxn=10000+10;
ll par[mxn+10];
ll dis[mxn+10];
ll vis[mxn+10],cnt;
set<ll>newgraph[mxn];
bool flg;
ll timer;
ll tin[mxn],tlow[mxn];
vector<ll>adj[mxn];
void bridge_dfs(int node,int parent){
    vis[node]=1;
    tin[node]=tlow[node]=timer;
    timer++;
    for(auto v : adj[node]){
        if(v==parent)continue;
        if(vis[v]==0){
            bridge_dfs(v,node);
            tlow[node]=min(tlow[v],tlow[node]);
            if(tlow[v]>tin[node]){
                newgraph[v].erase(node);
                newgraph[node].erase(v);
            }
        }else{
            tlow[node]=min(tlow[v],tlow[node]);
        }
    }
}
void odd_cycle_find(ll u){
    cnt++;
    vis[u]=1;
    for(auto v:newgraph[u]){
        if(vis[v]==0){
            par[v]=u;
            dis[v]=dis[u]+1;
            odd_cycle_find(v);
        }
        else if(vis[v]==1&&v!=par[u] && abs(dis[v]-dis[u])%2==0){///if(vis[v]==1) for directed graph
            flg=true;
        }
    }
    vis[u]=2;/// u nodes all adj nodes r visited
}
int ks;
void solve()
{
    ///for undirected = minimum three nodes make a cycle for this code
    ///for directed = also one node can be make a cycle for this code
    ll V,E,u,v;
    cin>>V>>E;
    for(int i=0;i<=V;i++){
        vis[i]=0;
        par[i]=-1;
        adj[i].clear();
        newgraph[i].clear();
        timer=1;
    }
    for(ll i=0; i<E; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);///off the line for directed graph
        newgraph[u].insert(v);
        newgraph[v].insert(u);
    }
    for(ll i=0;i<V;i++){
        if(vis[i]==0)bridge_dfs(i,-1);
        vis[i]=0;
    }
        
    ll ans=0;
    for(ll i=0;i<V;i++)
    {
        flg=false;
        cnt=0;
        if(vis[i]==0){
            dis[i]=0;
            odd_cycle_find(i);
        }
        if(flg)ans+=cnt;
        
    }
    cout<<"Case "<<++ks<<": ";

    cout<<ans<<"\n";

}
int main()
{
#ifndef ONLINE_JUDGE
     freopen("inputf.in", "r", stdin);  ///To read from a file.
//    freopen("outputf.in", "w", stdout);  ///To write  a file.
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    //cerr<<"\nTime:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
///invisible =  
