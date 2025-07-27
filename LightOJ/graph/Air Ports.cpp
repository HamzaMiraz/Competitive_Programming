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
const int sz = 10005;
int ks;
struct Edge{
    int u,v,w;
    Edge(int ui,int vi,int wi){
        u=ui;
        v=vi;
        w=wi;
    }
};
vector<Edge>edgeList;
int parant[sz];
int compoSize[sz];
void disjoint(int V){
    edgeList.clear();
    for(int i=0;i<=V+3;i++){
        parant[i]=i;///call by make func in DSU
        compoSize[i]=1;
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

int kruskal(int air_cost){
    int cost=0;
    sort(edgeList.begin(),edgeList.end(),com_by_waight);

    for(int i=0;i<edgeList.size() && edgeList[i].w<air_cost ;i++){
        if(FindRootParant(edgeList[i].u) != FindRootParant(edgeList[i].v)){

            join_components(edgeList[i].u , edgeList[i].v);
            cost+=edgeList[i].w;
        }
    }
    return cost;
}
int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    ios_base::sync_with_stdio(0); cin.tie(0);
    int E,V,air_cost,t;cin>>t;
    while(t--)
    {
        cin>>V>>E>>air_cost;
        disjoint(V);///init
        int u,v,w;
        for(int i=0;i<E;i++){
            cin>>u>>v>>w;
            edgeList.push_back({u,v,w});
        }
        int res= kruskal(air_cost);
        set<int>par;
        for(int i=1;i<=V;i++){
            par.insert(FindRootParant(i));
        }
        int no_of_airport=par.size();
        cout<<"Case "<<++ks<<": ";

        cout<<res+no_of_airport*air_cost<<" "<<no_of_airport<<"\n";
    }
    return 0;
}



