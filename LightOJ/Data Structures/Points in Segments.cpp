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
#define ss " "
#define nn "\n"
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;
const int sz=2e5+10;
const ll mod=1e9+7;
const double PI = acos(-1);
 ll cil(ll x,ll y){
    if(x%y)return x/y +1;
    return x/y;
}
int ks;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n,q;
    cin>>t;
    while (t--) {
        cin>>n>>q;
        ll ar[n+1];
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        cout<<"Case "<<++ks<<":\n";
        while(q--){
            int l,r;
            cin>>l>>r;
            int lw=lower_bound(ar,ar+n,l)-&ar[0];
            int up=lower_bound(ar,ar+n,r)-&ar[0];
            if(up==n || ar[up]!=r)up--;

            cout<<up-lw+1<<nn;

        }
    }
    return 0;
}
