#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 2e9+10;
const int MOD = 1e9+7;
const int Size = 10008;
struct node{
    int idx,st,fin;
};
node Time[Size];
vector<int>adj[Size];
vector<int>radj[Size];
vector<int>component[Size];
int vis[Size],scc[Size],ti,compo_idx;

bool com(node a,node b){
    return a.fin>b.fin;
}
bool comidx(node a,node b){
    return a.idx<b.idx;
}

void dfs(int u){
    Time[u].st=ti++;
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(vis[v]==0){
            dfs(v);
        }
    }
    Time[u].fin=ti++;
}
void rdfs(int u,int compo_idx){

    vis[u]=1;
    scc[u]=compo_idx;///scc[u] is compo_idx'th component who is carring nod u
    component[compo_idx].push_back(u);
    for(int i=0;i<radj[u].size();i++){
        int v=radj[u][i];
        if(vis[v]==0){
            rdfs(v,compo_idx);
        }
    }

}
int ks;
int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int V,E,u,v;
    int t;cin>>t;
    while(t--)
    {
        cin>>V>>E;
    /// SCC works only for directional graph
        for(int i=0;i<=V+5;i++){
            adj[i].clear();
            radj[i].clear();
            component[i].clear();
            vis[i]=0;
        }
        for(int i=1;i<=E;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            radj[v].push_back(u);/// for reverce edges direction
        }
        ti=1;
        for(int i=1;i<=V;i++){/// 1 based graph
            Time[i].idx=i;
            if(vis[i]==0){
                dfs(i);
            }
        }
        // cout<<"[Start time,Finish Time]:\n";
        // for(int i=1;i<=V;i++){
        //     cout<<"Nod "<<i<<" :["<<Time[i].st<<","<<Time[i].fin<<"]\n";
        // }
        memset(vis,0,sizeof vis),compo_idx=1;///compo_idx = n'th component[1 based]
        sort(&Time[1],&Time[V+1],com);///precedency by finish time
        for(int i=1;i<=V;i++){
            if(vis[Time[i].idx]==0){
                rdfs(Time[i].idx,compo_idx),compo_idx++;///dfs traverce for reverse direction
            }
        }
        //sort(&Time[1],&Time[V+1],comidx);
        int indegree[compo_idx+5]={0};///component indegree
        
        for(int u=1;u<=V;u++){
            for(auto v : adj[u]){
                if(scc[v] != scc[u]){
                    indegree[scc[v]]++;
                }
            }
        }
        int hit=compo_idx-1;
        for(int i=1;i<compo_idx;i++){
            if(indegree[i]!=0)hit--;
        }
        cout<<"Case "<<++ks<<": "<<hit<<"\n";

    }
    return 0;
}

