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
int ks;
int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n ; cin>>t;
    while(t--)
    {
        cin>>n;
        int height[n+6];
        for(int i=1;i<=n;i++){
            cin>>height[i];
        }
        int leftsmall[n+6], rightsmall[n+6];
        stack<int>st;
        for(int i=1;i<=n;i++){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            if(st.empty()){
                leftsmall[i]=1;
            }else{
                leftsmall[i]=st.top()+1;
            }
            st.push(i);
        }    
        stack<int>ST;
        for(int i=n;i>=1;i--){
            while(!ST.empty() && height[ST.top()]>=height[i]){
                ST.pop();
            }
            if(ST.empty()){
                rightsmall[i]=n;
            }else{
                rightsmall[i]=ST.top()-1;
            }
            ST.push(i);
        }
        int mx=-1;
        for(int i=1;i<=n;i++){
            mx=max(mx,(rightsmall[i]-leftsmall[i]+1)*height[i]);
        }
        cout<<"Case "<<++ks<<": "<<mx;el

    }
    return 0;
}
///invisible =  