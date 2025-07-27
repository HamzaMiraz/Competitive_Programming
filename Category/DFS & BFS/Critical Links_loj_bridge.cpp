#include<bits/stdc++.h>
using namespace std;
/**
bridge algorithm : if we remove  a edge from the graph
and thats makes the graph to one more parts of graph
thats kind of edges call by Bridge
**/
const int nodes=10005;
int timer;
int vis[nodes],tin[nodes],tlow[nodes];
vector<int>adj[nodes];
vector<pair<int,int>>bridge;
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
                int a=node,b=v;
                if(a>b)swap(a,b);
                bridge.push_back({a,b});
            }
        }else{
            tlow[node]=min(tlow[v],tlow[node]);
        }
    }
}
void init(int V){
    for(int i=0;i<V;i++){
        vis[i]=0;
        adj[i].clear();
    }
    bridge.clear();
}
int ks;
int main(){
    int V,E;
    int t;cin>>t;
    while(t--){
        cin>>V;
        init(nodes);

        int u,v,k;
        string s;
        for(int i=0;i<V;i++){
            cin>>u;
            //cin>>s;
            //k=s[1]-'0';
            scanf(" (%d)",&k);
            for(int j=0;j<k;j++){
                cin>>v;
                //cout<<u<<"->"<<v<<"\n";
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        timer=1;
        for(int i=0;i<V;i++){///zero based;
            if(vis[i]==0){
                bridge_dfs(i,i);
            }
        }
        cout<<"Case "<<++ks<<":\n";
        int nb=bridge.size();
        cout<<nb<<" critical links\n";
        sort(bridge.begin(),bridge.end());
        for(auto it : bridge){
            cout<<it.first<<" - "<<it.second<<"\n";
        }


    }
    return 0;
}
/**
5 5
1 0
0 3
3 4
0 2
1 2

12 14
0 1
0 3
1 2
3 2
3 4
4 5
5 6
6 7
7 8
7 9
9 10
10 11
11 9
8 6

12 14
0 1
0 3
1 2
3 2
3 4
4 5
5 6
6 7
7 8
7 9
9 10
10 11
11 9
8 5

**/
