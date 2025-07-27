#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,l;
ll ks;
void divisors(){
    vector<ll> divs;
    cin >> n>>l;
    n-=l;
    cout<<"Case "<<++ks<<": ";
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0 ) {
            if(l<i)divs.push_back(i);
            if (i != n / i)if(n/i >l) divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    for (auto x: divs) cout << x << ' ';
        if(divs.empty()){
            cout<<"impossible";
        }
        cout<<"\n";
}
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
  int t;cin>>t;
  while(t--){
      divisors();
    }
  
  return 0;
}