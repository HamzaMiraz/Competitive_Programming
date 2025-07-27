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
int ks;
const int oo = 2e9+10;
struct Edge{
    int u,v,w;
    Edge(int ui,int vi,int wi){
        u=ui;
        v=vi;
        w=wi;
    }
};
vector<Edge>edgeList;
int parant[107];
int compoSize[107];
void disjoint(int V){
    for(int i=0;i<=V+5;i++){
        parant[i]=i;///call by make func in DSU
        compoSize[i]=1;
    }
}
/// finding root node of this component and
/// make root node is parant of the all nodes of this component
int FindRootParant(int node){
    if(node == parant[node])
        return node;
    return parant[node]=FindRootParant(parant[node]);
}
/// joining two components
void join_components(int u,int v){///union/makelink  u nodes component
                                /// to v nodes component and
                                 /// make them as a same component

    int u_parant=FindRootParant(u); /// finding u 's root node
    int v_parant=FindRootParant(v); /// finding v 's root node

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

int kruskal_min(){
    int cost=0;
    sort(edgeList.begin(),edgeList.end(),com_by_waight);

    for(int i=0;i<edgeList.size();i++){
        ///if two vertex or groups root parent r same
        ///then it will be creat a cycle
        ///Then we won't add them
        ///else ↓
        if(FindRootParant(edgeList[i].u) != FindRootParant(edgeList[i].v)){

            join_components(edgeList[i].u , edgeList[i].v);
            cost+=edgeList[i].w;

            ///connecting edges
            //cout<<edgeList[i].u<<"<->"<<edgeList[i].v<<" = "<<edgeList[i].w;el;
        }
    }
    return cost;
}
int kruskal_max(){
    int cost=0;
    sort(edgeList.begin(),edgeList.end(),com_by_waight);
    reverse(edgeList.begin(),edgeList.end());

    for(int i=0;i<edgeList.size();i++){
        ///if two vertex or groups root parent r same
        ///then it will be creat a cycle
        ///Then we won't add them
        ///else ↓
        if(FindRootParant(edgeList[i].u) != FindRootParant(edgeList[i].v)){

            join_components(edgeList[i].u , edgeList[i].v);
            cost+=edgeList[i].w;

            ///connecting edges
           //cout<<edgeList[i].u<<"<->"<<edgeList[i].v<<" = "<<edgeList[i].w;el;
        }
    }
    return cost;
}

int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int V,E,t;cin>>t;
    while(t--)
    {
        cin>>V;

        edgeList.clear();
        disjoint(V);///init

        while(1){
            int u,v,w;
            cin>>u>>v>>w;
            if(u==0 && v==0 && w==0)break;
            edgeList.push_back({u,v,w});
        }
        int min_scheme = kruskal_min();
        
        disjoint(V);

        int max_scheme = kruskal_max();
        
        int ans= max_scheme+min_scheme;
        cout<<"Case "<<++ks<<": ";
        if(ans%2){
            cout<<ans<<"/2\n";
        }else{
            cout<<ans/2<<"\n";
        }

    }
    return 0;
}




