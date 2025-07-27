#include<bits/stdc++.h>
using namespace std;


#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define GCD(a,b)  __gcd(a,b)
#define LCM(a,b)  (a*b)/__gcd(a,b)
#define sqr(a)    ((a)*(a))
#define dec(n,x)  fixed << setprecision(x) <<n
#define pb emplace_back
#define nl printf("\n");
#define el cout<<"\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";

typedef long long LL;

const int oo = 2e9+10;
const int sz = 105;
int ks;
struct Edge{
    int u,v,w;
    Edge(int ui,int vi,int wi){
        u=ui;
        v=vi;
        w=wi;
    }
};
vector<int>adj[sz];
vector<Edge>edgeList;
int parant[sz];
int compoSize[sz];
int vis[sz];
void disjoint(int V){
    edgeList.clear();
    for(int i=0;i<=V+3;i++){
        parant[i]=i;///call by make func in DSU
        compoSize[i]=1;
        adj[i].clear();
        vis[i]=0;
    }
}
int FindRootParant(int node){
    if(node == parant[node])
        return node;
    return parant[node]=FindRootParant(parant[node]);
}
void join_components(int u,int v){

    int u_parant=FindRootParant(u);
    int v_parant=FindRootParant(v);

    if(u_parant==v_parant)///both r alrady joined
        return ;
    if(compoSize[u_parant]>compoSize[v_parant]){
        parant[v_parant]=u_parant;
        compoSize[u_parant]+=compoSize[v_parant];
    }
    else{
        parant[v_parant]=u_parant;
        compoSize[v_parant]+=compoSize[u_parant];
    }
}
bool com_by_waight(Edge a,Edge b){
    return a.w<b.w;
}

int kruskal(){
    int cost=0;
    sort(edgeList.begin(),edgeList.end(),com_by_waight);

    for(int i=0;i<edgeList.size();i++){
        if(FindRootParant(edgeList[i].u) != FindRootParant(edgeList[i].v)){

            join_components(edgeList[i].u , edgeList[i].v);
            cost+=edgeList[i].w;
        }
    }
    return cost;
}
set<int>vis_nods;
void dfs(int u){
    vis[u]=1;
    vis_nods.insert(u);
    for(auto v : adj[u]){
        if(vis[v])continue;
        dfs(v);
    }
}

int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    ios_base::sync_with_stdio(0); cin.tie(0);
    int V,t;cin>>t;
    while(t--)
    {
        cin>>V;
        disjoint(V);///init
        int tot_cable=0;
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                int w;cin>>w;
                tot_cable+=w;
                if(w>0){
                    edgeList.push_back({i,j,w});
                    adj[i].push_back(j);
                    adj[j].push_back(i);

                }
            }
        }
        vis_nods.clear();
        dfs(1);
        cout<<"Case "<<++ks<<": ";
        if(V!=vis_nods.size()){
            cout<<"-1\n";
            continue;
        }

        int min_cable_needed = kruskal();
        int donate=tot_cable-min_cable_needed;
        cout<<donate<<"\n";
    }
    return 0;
}



