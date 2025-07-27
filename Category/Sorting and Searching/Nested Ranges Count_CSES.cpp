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
///who is k'th position= set.find_by_order(k),index of v = set.order_of_key(v);
 
typedef long long ll;/// 1e18;
typedef __int128_t LL;/// 1e32;
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
const int oo = 2e9+10;
const ll MOD = 1e9+7;// Prime
 
bool com(array<ll,3>a,array<ll,3>b){
    if(a[0]==b[0])return a[1]>b[1];
    return a[0]<b[0];
}
 
int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
 //   ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin>>n)
    {
        vector<array<ll,3>>v;
        for(int i=0;i<n;i++){
            ll x,y;
            cin>>x>>y;
            v.push_back({x,y,i});
        }
        sort(v.begin(),v.end(),com);
 
        // for(auto [x,y,z] : v){
        //     cout<<x<<" "<<y<<"\n";
        //
 
        ll ar[n+5];
        ll br[n+5];
        iset<pair<ll,int>>st1;
        iset<pair<ll,int>>st2;
        for(int j=n-1,i=0;j>=0;j--,i++){
            //cout<<v[j][0]<<" "<<v[j][1]<<" "<<v[j][2]<<"\n";
            ar[v[j][2]]=st1.order_of_key({v[j][1],i});
            st1.insert({v[j][1],i});
        }
        for(int i=0;i<n;i++)cout<<ar[i]<<" ";el
        for(int i=0;i<n;i++){
            //cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<"\n";
            br[v[i][2]]=(i-st2.order_of_key({v[i][1],-1}));
            st2.insert({v[i][1],i});
        }
    
        for(int i=0;i<n;i++)cout<<br[i]<<" ";el
    }
    return 0;
}
///invisible =  