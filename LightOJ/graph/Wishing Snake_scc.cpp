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
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;//exmp:indexed_set st
#define index(s,k) s.find_by_order(k);///  who is k'th position

typedef long long ll;
template <typename T>
T BIGMOD(T base,T power,T Mod=1e9+7){T ans = 1;
while(power){if(power & 1)ans = (ans * base) % Mod;
base = (base * base) % Mod;power = power >> 1;}return ans;}

template <typename T>
T INV(T base,T mod=1e9+7){//defult mod=1e9+7
    return BIGMOD(base%mod,mod-2,mod)%mod;///base^-1
}

template <typename T>
vector<T>primeFactors(T n){vector<T>PRIME;T c=2;while///prime factor
(n>1){if(n%c==0){PRIME.push_back(c);n/=c;}else c++;}return PRIME;}

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
#define sp(n,x)  fixed << setprecision(x) <<n
#define pb emplace_back
#define ss " "
#define nn printf("\n");
#define el cout<<"\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";

template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 2e9+10;
const ll MOD = 1e9+7;// Prime
const int Size = 10005;
struct node{
    int idx,st,fin;
};
node Time[Size];
vector<int>adj[Size];
vector<int>radj[Size];
vector<int>component[Size];
int vis[Size],scc[Size],ti,compo_no,ks;

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
int cnt;
void is_same_compo(int u){
    cnt++;
    vis[u]=1;
    for(auto v : adj[u]){
        if(vis[v]==0)is_same_compo(v);
    }
}

int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
//    ios_base::sync_with_stdio(0); cin.tie(0);
   int t;cin>>t;
    while(t--)
    {
        for(int i=0;i<10005;i++){
            adj[i].clear(),vis[i]=0;
            radj[i].clear();
            component[i].clear();
        }
        set<int>st;
        int n,k;cin>>n;
        for(int i=0;i<n;i++){
            cin>>k;
            for(int i=0;i<k;i++){
                int u,v;cin>>u>>v;
                adj[u].push_back(v);
                radj[v].push_back(u);
                st.insert(u);
                st.insert(v);
            }
        }
        cout<<"Case "<<++ks<<": ";
        cnt=0;
        is_same_compo(0);
        if(cnt!=st.size()){
            cout<<"NO\n";
            continue;
        }
         memset(vis,0,sizeof vis);
        ti=1;
        for(int i=0;i<1000;i++){/// 1 based graph
            Time[i].idx=i;
            if(vis[i]==0){
                dfs(i);
            }
        }
        memset(vis,0,sizeof vis),compo_no=0;///compo_no = n'th component[1 based]
        sort(&Time[0],&Time[1000],com);///precedency by finish time
        for(int i=0;i<1000;i++){
            if(vis[Time[i].idx]==0){
                compo_no++;         /// compo_no also compo index which is 1 based
                rdfs(Time[i].idx,compo_no);///dfs traverce for reverse direction
            }
        }
        int ok=1;
        int component_outdegree[1007]={0};
        for(int u=0;u<1000;u++){
            for(auto v : adj[u]){
                if(scc[v]!=scc[u])
                component_outdegree[scc[u]]++;
            }
            if( component_outdegree[scc[u]]>1){
                ok=0;
                break;
            }
        }
        if(ok){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }



    }
    return 0;
}
///invisible =  