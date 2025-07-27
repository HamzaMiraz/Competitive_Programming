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
const int oo = 2e9+10;
const ll MOD = 1e9+7;// Prime


int dp[105][100005];
int  ar[109];
int pref[105][100005];
int n;
// int go(int i,int k){
    
//     if(i==n ){
//         if(k==0)return 1;
//         return 0;
//     }

//     int &ans= dp[i][k];
//     if(ans!=-1)return ans;
//     ans=0;
//     for(int c=0;c<=min(ar[i],k);c++){
//         ans=(ans+go(i+1,k-c))%MOD;
//     }
//     return ans%MOD;
// }
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    while(cin>>n>>k)
    {
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        //out<<go(0,k)<<"\n";
        
        for(int i=n;i>=0;i--){
            for(int kk=0;kk<=k;kk++){
                int &ans= dp[i][kk];
                if(i==n){
                    if(kk==0){
                        dp[i][kk]= 1;
                    }
                    else dp[i][kk]= 0;
                }else{
                     ans=0;
                    // for(int c=0;c<=min(ar[i],kk);c++){
                    //     ans=(ans+dp[i+1][kk-c])%MOD;
                    // }
                    int r = kk, l =  kk - min(kk , ar[i]);
                    ans = (pref[i + 1][r] - (l ? pref[i + 1][l - 1] : 0) + MOD) % MOD;
                }
                
            }
            for (int kk = 0; kk <= k; kk++) {
                 pref[i][kk] = ((kk ? pref[i][kk - 1] : 0) + dp[i][kk]) % MOD;
            }
        }
        cout<<dp[0][k]<<"\n";
    }
    return 0;
}
///invisible =  
///https://atcoder.jp/contests/dp/tasks/dp_m?lang=en