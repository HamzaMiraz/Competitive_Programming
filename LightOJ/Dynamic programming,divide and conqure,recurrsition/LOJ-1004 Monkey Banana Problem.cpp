#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#endif
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define vii vector<pair<int,int>>
#define vll vector<pair<ll,ll>>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pql priority_queue<ll>
#define LCM(a,b)  (a*b)/__gcd(a,b)
#define ss ' '
#define nn '\n'
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;
const int sz=2e5+10;
const ll mod=1e9+7;
 ll cil(ll x,ll y){
    if(x%y)return x/y +1;

    return x/y;
}
int ks,n;
ll dp[201][201];
ll ar[201][201];
ll fun(ll i ,ll j){
    if(i==2*n-1)return ar[i][j];
    if(i>2*n-1 || j>n || j<1)return -9999;

    if(dp[i][j]!=-1)return dp[i][j];

    dp[i][j]=-9999;
    dp[i][j]=max(dp[i][j],fun(i+1,j)+ar[i][j]);
    if(i<n)dp[i][j]=max(dp[i][j],fun(i+1,j+1)+ar[i][j]);
    else dp[i][j]=max(dp[i][j],fun(i+1,j-1)+ar[i][j]);

    return dp[i][j];
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        cin>>n;
        memset(dp,0,sizeof dp);
        memset(ar,0,sizeof ar);
        for(int i=1;i<=2*n-1;i++){
            if(i<n){
                for(int j=1;j<=i;j++){
                    cin>>ar[i][j];
                }
            }else{
                for(int j=1;j<=2*n-i;j++){
                    cin>>ar[i][j];
                }
            }
        }
        dp[2*n-1][1]=ar[2*n-1][1];

        for(int i=2*n-1;i>=1;i--){
            for(int j=n;j>=1;j--){
                if(i>2*n-1 || j>n || j<1)continue;
                dp[i][j]=-9999;
                dp[i][j]=max(dp[i][j],dp[i+1][j]+ar[i][j]);
                if(i<n)dp[i][j]=max(dp[i][j],dp[i+1][j+1]+ar[i][j]);
                else dp[i][j]=max(dp[i][j],dp[i+1][j-1]+ar[i][j]);
            }
        }

        cout<<"Case "<<++ks<<": "<<dp[1][1]<<nn;
    }
    return 0;
}