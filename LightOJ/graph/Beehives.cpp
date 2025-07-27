#include <bits/stdc++.h>
using namespace std;
const int oo=2e9+7;
vector<int>g[510];

int ks;

int bfs(int s,int nodes){
    queue<int>Q;
    vector<int>dist(nodes+1,oo);
    vector<int>par(nodes+1,-1);
    dist[s]=0;
    Q.push(s);
    int ans=oo;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(auto v : g[u]){
            if(dist[v]==oo){
                par[v]=u;
                dist[v]=dist[u]+1;
                Q.push(v);
            }else if(v!=par[u]){
                ans=min(ans,dist[u]+dist[v]+1);
            }
        }
    }
    return ans;

}

int main()
{
    
    ios_base::sync_with_stdio(0); cin.tie(0);
   
    int V,E,u,v;
    int t;cin>>t;
    while(t--){
        cin>>V>>E;
        for(int i=0;i<V+5;i++){
            g[i].clear();
        }
        for(int i=0;i<E;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans=oo;
        for(int i=0;i<V;i++){
             ans=min(ans,bfs(i,V)); 
        }
        cout<<"Case "<<++ks<<": ";

        if(ans==oo){
            cout<<"impossible\n";
        }else{
            cout<<ans<<"\n";
        }

    }
    return 0;
}
