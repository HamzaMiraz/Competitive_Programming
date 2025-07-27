#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 2e9+10;
const int MOD = 1e9+7;
const int Size = 20005;
struct node{
    int idx,st,fin;
};
node Time[Size];
vector<int>adj[Size];
vector<int>radj[Size];
vector<int>component[Size];
int vis[Size],scc[Size],ti,compo_no;
int outdegree[Size];
int indegree[Size];

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
void rdfs(int u,int compo_no){

    vis[u]=1;
    scc[u]=compo_no;///scc[u] is compo_no'th component who is carring nod u
    component[compo_no].push_back(u);
    for(int i=0;i<radj[u].size();i++){
        int v=radj[u][i];
        if(vis[v]==0){
            rdfs(v,compo_no);
        }
    }

}

int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    ios_base::sync_with_stdio(0); cin.tie(0);
    int V,E,u,v,t,ks=0;
    cin>>t;
    while(t--)
    {

        cin>>V>>E;
        cout<<"Case "<<++ks<<": ";
    /// SCC works only for directional graph
        for(int i=0;i<=V+5;i++){
            adj[i].clear();
            radj[i].clear();
            component[i].clear();
            vis[i]=0;
            indegree[i]=0;
            outdegree[i]=0;
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
        memset(vis,0,sizeof vis),compo_no=0;///compo_no = n'th component[1 based]
        sort(&Time[1],&Time[V+1],com);///precedency by finish time
        for(int i=1;i<=V;i++){
            if(vis[Time[i].idx]==0){
                compo_no++;         /// compo_no also compo index which is 1 based
                rdfs(Time[i].idx,compo_no);///dfs traverce for reverse direction
            }
        }
        if(compo_no==1){
            cout<<"0\n";
            continue;
        }
        for(int u=1;u<=V;u++){
            for(auto v : adj[u]){
                if(scc[u]!=scc[v]){
                    ++indegree[scc[v]];
                    ++outdegree[scc[u]];
                }
            }
        }
        int cnt1=0,cnt2=0;
        for(int i=1;i<=compo_no;i++){
            if(indegree[i]==0)cnt1++;
            if(outdegree[i]==0)cnt2++;
        }
        cout<<max(cnt1,cnt2)<<"\n";

    }
    return 0;
}
/**
exmp two inputs :
8 9

1 2
2 3
3 4
4 1
3 5
5 6
6 7
7 5
7 8

8 10

1 2
2 3
3 1
3 4
4 5
5 6
5 8
6 7
7 5
7 8

**/
