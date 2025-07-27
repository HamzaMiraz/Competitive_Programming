#include<bits/stdc++.h>
using namespace std;
using ll=long long;

#define LCM(a,b)  (a*b)/__gcd(a,b)

void divisors(ll n){
    vector<ll> divs;
    ll mn=1e13;
    ll a=1,b=1;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ll A=i,B=n/i;
            if(__gcd(A,B)==1){
                if(mn>max(A,B)){
                    mn=max(A,B);
                    a=A,b=B;
                }
            }
        }
    }
    cout<<a<<" "<<b<<"\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n; cin >> n;
  divisors(n);
  
  return 0;
}