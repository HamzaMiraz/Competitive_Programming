#include<bits/stdc++.h>
using namespace std;

//For Debugging
#define debug(a...)          {cout<<__LINE__<<" #--> ";dbg,a; cout<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using iset=tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update> ;///exmp= iset<double>st
///who is k'th position= *(set.find_by_order(k)),index of v = set.order_of_key(v);

typedef long long ll;/// 1e18;
//typedef __int128_t LL;/// 1e32;
template <typename T>
T BIGMOD(T base,T power,T Mod=1e9+7){T ans = 1;
while(power){if(power & 1)ans = (ans * base) % Mod;
base = (base * base) % Mod;power = power >> 1;}return ans;}

template <typename T>
T INV(T base,T mod=1e9+7){//defult mod=1e9+7
    return BIGMOD(base%mod,mod-2,mod)%mod;///base^-1
}

template <typename T>
T nCr(T n, T r){T res=1;for (T i=0;i<r;i++){
res *= (n-i);res /= (i+1);}return res;}/// NCR

template <typename T>
T fact(T n){if(n<=1)return 1;return n*fact(n-1);}

template <typename T>
T nPr(T n, T r){return fact(n)/fact(n-r);}///NPR

template <typename T>
vector<T>BigFactorial(T n){vector<T> dg;dg.push_back(1);
for (T f=2;f<=n;f++) {T c = 0;for (T i= 0;i<dg.size();i++){
T p=dg[i]*f+c;dg[i]=p%10;c=p/10;}while(c){dg.push_back(c%10);c/=10;}}
reverse(dg.begin(),dg.end());return dg;}

#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define all(x) x.begin(), x.end()
#define lbv(vec,x) lower_bound(all(vec),x)-vec.begin()//retrun index
#define ubv(vec,x) upper_bound(all(vec),x)-vec.begin()
#define lba(ar,n,x) lower_bound(ar,ar+n,x)-&ar[0];//return index
#define uba(ar,n,x) upper_bound(ar,ar+n,x)-&ar[0];
#define lb(mp,x) mp.lower_bound(x);///for set,map
#define ub(st,x) st.upper_bound(x);///return pointer address
#define GCD(a,b)  __gcd(a,b)
#define LCM(a,b)  (a*b)/__gcd(a,b)
#define sqr(a)    ((a)*(a))
#define deg(n)  n*PI/180 /// redian to degree
#define sp(n,d)  fixed << setprecision(d) <<n
#define pb emplace_back
#define F  first
#define S  second
#define ss " "
#define nn printf("\n");
#define el cout<<"\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";

template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 1e9+10;
const ll MOD = 1e9 +7;// Prime

const int nodes=10008;
int timer;
int vis[nodes],tin[nodes],tlow[nodes];
vector<int>adj[nodes];
set<int>ad[nodes];
vector<pair<int,int>>bridge;
int com_cnt;
int comp_no[nodes];
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
                bridge.push_back({node,v});
                ad[node].erase(v);
                ad[v].erase(node);
            }
        }else{
            tlow[node]=min(tlow[v],tlow[node]);
        }
    }
}
void dfs_cc(int u){
    vis[u]=1;
    comp_no[u]=com_cnt;
    for(auto v : ad[u]){
        if(vis[v]==0)dfs_cc(v);
    }
}
void init(int V){
    for(int i=0;i<V+5;i++){
        vis[i]=0;
        adj[i].clear();
        ad[i].clear();
    }
    timer=1;
    bridge.clear();
    com_cnt=0;
}

int ks;
void solve(){
    cout<<"Case "<<++ks<<": ";
    int V,E;
    cin>>V>>E;
    init(V);
    int u,v;

    for(int i=0;i<E;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ad[u].insert(v);
        ad[v].insert(u);
    }

    bridge_dfs(0,-1);
    for(int i=0;i<V+5;i++)vis[i]=0;

    for(int i=0;i<V;i++){
        if(vis[i]==0){
            com_cnt++;
            dfs_cc(i);
        }
    }
    int cnt=0;
    map<int,int>no_of_bridg_in_compo;
    for(auto [u,v] : bridge){
        no_of_bridg_in_compo[comp_no[u]]++;
        no_of_bridg_in_compo[comp_no[v]]++;
    }
    for(int i=1;i<=com_cnt;i++){
        if(no_of_bridg_in_compo[i]==1)cnt++;
    }
    cout<<(cnt+1)/2<<"\n";


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
