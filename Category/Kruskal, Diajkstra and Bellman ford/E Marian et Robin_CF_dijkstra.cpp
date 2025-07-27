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


#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define all(x) x.begin(), x.end()
#define loop(IV,INIT,NV) for(int IV=INIT;IV<=NV;IV++)
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
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 1e9+10;
const ll MOD = 1e9 +7;// Prime


void solve(int ks){
    //cout<<"Case "<<ks<<": ";

    int n,m,h;
    cin>>n>>m>>h;
    int hr[n+5]={0};
    for(int i=1;i<=h;i++){
        int x;cin>>x;
        hr[x]=1;
    }
    vector<pair<int,int>>adj[n+2];
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    minHeap<array<ll,4>>mr,rb;
    vector<vector<ll>>mdis(n+2,vector<ll>(2,1e14)),rdis(n+2,vector<ll>(2,1e14));
    mdis[1][0]=0;
    mr.push({0,0,1});
    while(mr.size()){
        array<ll,4>it =mr.top();
        mr.pop();
        int u=it[2];
        int mount=it[1];
        ll udis=it[0];

        if(udis>mdis[u][mount])continue;
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first;
            int w=adj[u][i].second;
            mount|=hr[u];
            ll newdis=udis+w;
            if(mount)newdis-=(w/2);
            if(mdis[v][mount]>newdis){
                mdis[v][mount]=newdis;
                mr.push({newdis,mount,v});

            }
        }
    }
    rdis[n][0]=0;
    rb.push({0,0,n});
    while(rb.size()){
        array<ll,4>it =rb.top();
        rb.pop();
        int u=it[2];
        int mount=it[1];
        ll udis=it[0];

        if(udis>rdis[u][mount])continue;
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first;
            int w=adj[u][i].second;
            mount|=hr[u];
            ll newdis=udis+w;
            if(mount)newdis-=(w/2);
            if(rdis[v][mount]>newdis){
                rdis[v][mount]=newdis;
                rb.push({newdis,mount,v});

            }
        }
    }

    ll mn=1e14;
    for(int i=1;i<=n;i++){
        mn=min(mn,max(min(mdis[i][0],mdis[i][1]),min(rdis[i][0],rdis[i][1])));
    }
    if(mn>=1e14){
        cout<<-1<<"\n";
    }else{
        cout<<mn<<"\n";
    }
    
    
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