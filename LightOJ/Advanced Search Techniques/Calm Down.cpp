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
#define sp(n,x)  fixed << setprecision(x) <<n
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
    int t;
    double R,n,r,ans,m;
    cin>>t;
    while (t--) {
        cin>>R>>n;
        /// formula sin((2*PI)/(2*n))=r/(R-r)
        ans=sin(PI/n);
        double l=0;
        double h=R;
        int i=70;
        while(i--){
         m=(l+h)/2;
            if(m/(R-m) < ans){
                l=m;
            }else{
                h=m;
            }
        }
        cout<<"Case "<<++ks<<": "<<sp(m,7)<<nn;
    }
    return 0;
}
