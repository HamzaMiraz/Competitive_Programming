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
 unordered_map<int, int> ma;
 unordered_map<int, int> mb;
 ll cil(ll x,ll y){
    if(x%y)return x/y +1;

    return x/y;
}
ll nCr(ll n, ll r){ll res=1;for (ll i=0;i<r;i++){
res *= (n-i);res /= (i+1);}return res;}/// NCR
ll fact(ll n){if(n<=1)return 1;return n*fact(n-1);}

int ks;
ll t,n,k;
ll memo[35][35][31*31];
ll rec(ll r,ll c,ll k){
    if(k==0) return 1;
    if(k>r || k>c)return 0;
    if(c==1)return r;
    if(memo[r][c][k]!=-1)return memo[r][c][k];

    return memo[r][c][k]=r*rec(r-1,c-1,k-1)+rec(r,c-1,k);
}
void solverec(){
    cin>>n>>k;
        memset(memo,-1,sizeof memo);
        cout<<"Case"<<" "<<++ks<<": "<<rec(n,n,k)<<"\n";
}

void solveitretive(){
    cin>>n>>k;
        ll kk=k;
        ll memo[n+2][n+2][k*k +7];
        memset(memo,0,sizeof memo);
        for(int r=0;r<=n;r++)
            for(int c=0;c<=n;c++)
                memo[r][c][0]=1;

        for(int r=1;r<=n;r++){
            for(int c=1;c<=n;c++){
                for(int k=1;k<=kk;k++){
                    if(k>r || k>c)continue;
                    memo[r][c][k]=r*memo[r-1][c-1][k-1]+memo[r][c-1][k];
                    if(c==1)memo[r][c][kk]=r;
                }
            }
        }

        cout<<"Case"<<" "<<++ks<<": "<<memo[n][n][k]<<"\n";
}

void directformula(){
    cin>>n>>k;
    cout<<"Case"<<" "<<++ks<<": "<<nCr(n,k)*nCr(n,k)*fact(k)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>t;
    while(t--){
        //solverec();
        //solveitretive();
        directformula();

    }
    return 0;
}
