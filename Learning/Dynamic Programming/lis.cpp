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

vector<vector<int>>dp;
vector<int>ar;
int n;
int go(int i,int j){
    if(j==n)return 0;
    int &rf=dp[i+1][j];
    if(rf!=-1)return rf;
    rf=go(i,j+1);
    if(i==-1 || ar[i]<ar[j] ){
        rf=max(rf,1+go(j,j+1));
    }
    return rf;

}
void path(int i,int j){
    if(j==n)return;
    if(dp[i+1][j+1]>1+dp[j+1][j+1]){
        path(i,j+1);
    }else{
        if(i==-1 || ar[i]<ar[j]){
            cout<<ar[j]<<" "; 
            path(j,j+1);
        }else{
            path(i,j+1);
        }
    }

}
void lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        ar=nums;
        dp=vector<vector<int>>(n+2,vector<int>(n+2,-1));
        int ans=go(-1,0);
        cout<<ans<<"\n";
        path(-1,0);
    
}


int main()
{
    vector<int>ar={10,9,2,5,3,7,101,18};
    lengthOfLIS(ar);
}
///invisible =  
/*
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int>dp(n+2,1);
    int mx=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        mx=max(dp[i],mx);
    }
    return mx;
}
*/