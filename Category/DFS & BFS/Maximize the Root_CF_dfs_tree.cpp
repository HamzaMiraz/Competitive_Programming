#include<bits/stdc++.h>
using namespace std;

vector<int>adj[200005];
int val[200005];
int vis[200005];
int chz;
void dfs(int u){
    vis[u]=1;
    bool iscld=true;
    int mn=1e9;
    for(auto v: adj[u]){
        if(!vis[v]){
            iscld=false;
            dfs(v);
            mn=min(mn,val[v]);

        }
    }
    if(!iscld && u!=1){
        if(val[u]>=mn){
            val[u]=mn;
        }else{
            val[u]=(val[u]+mn)/2;
        }
    }

}
void solve(int ks){
    //cout<<"Case "<<ks<<": ";
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        adj[i].clear();
        vis[i]=0;
        chz=1;
    }
    for(int i=1;i<=n;i++)cin>>val[i];

    for(int i=2;i<=n;i++){
        int u;cin>>u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    dfs(1);
    int ans=val[1];
    int mn=1e9;
    for(auto v : adj[1]){
        mn=min(mn,val[v]);
    }

    cout<<val[1]+mn<<"\n";
    




}

signed main()
{
#ifndef ONLINE_JUDGE
     freopen("inputf.in", "r", stdin);  ///To read from a file.
//    freopen("outputf.in", "w", stdout);  ///To write  a file.
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int tks=1;
    cin>>tks;
    for(int ks=1;ks<=tks;ks++){
        solve(ks);
    }
    //cerr<<"\nTime:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
///invisible =  