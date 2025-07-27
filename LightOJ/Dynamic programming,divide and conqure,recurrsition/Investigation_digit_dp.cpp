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
ll ks;
ll k;
ll dp[82][82][10][2][2];

ll go(ll pos,ll st,ll ever_sm,ll digit,ll digsum,int len,string &s){
    if(pos==len){
        return digit%k==0 && digsum%k==0;
    }
    ll &rf=dp[digit][digsum][pos][st][ever_sm];
    if(~rf)return rf;
    rf=0;
    if(!st){
        if(pos){
            for(int i=1;i<=9;i++){
                rf+=go(pos+1,1,1,(10*digit +i)%k,(digsum+i)%k,len,s);
            }
        }else{
             for(int i=1;i<=s[pos]-'0';i++){
                rf+=go(pos+1,1,(ever_sm | (i<(s[pos]-'0'))),(10*digit +i)%k,(digsum+i)%k,len,s);
            }
        }
        rf+=go(pos+1,0,1,0,0,len,s);
    }else{
        if(ever_sm){
            for(int i=0;i<=9;i++){
                rf+=go(pos+1,1,1,(10*digit +i)%k,(digsum+i)%k,len,s);
            }
        }else{
             for(int i=0;i<=s[pos]-'0';i++){
                rf+=go(pos+1,1,(ever_sm | (i<(s[pos]-'0'))),(10*digit +i)%k,(digsum+i)%k,len,s);
            }
        }
    }
    return rf;
}

void solve(){
    cout<<"Case "<<++ks<<": ";
    string l,r;
    ll n,m;
    cin>>n>>m>>k;
    if(k==1){
        cout<<m-n+1<<"\n";
        return;
    }else if(k>81){
        cout<<0<<'\n';
        return;
    }
    n--;
    l=to_string(n);
    r=to_string(m);
    //cout<<l<<" "<<r<<"\n";
    memset(dp,-1,sizeof dp);
    ll right=go(0,0,0,0,0,r.size(),r);
    memset(dp,-1,sizeof dp);
    ll left=go(0,0,0,0,0,l.size(),l);
    cout<<right-left<<"\n";


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