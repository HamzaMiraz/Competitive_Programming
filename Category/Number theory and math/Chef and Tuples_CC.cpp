#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void divisors(ll n,int a,int b,int c){
    vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i) divs.push_back(n / i);
        }
    }
    int ans=0;
    for(auto x: divs){
        if(x<=a){
            for(auto y : divs){
                if(y<=b && n%(1ll*x*y)==0){
                    int z=n/(1ll*x*y);
                    if(z<=c && 1LL*x*y*z == n)++ans;
                }
            }
        }
    }
    cout<<ans<<"\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    int a,b,c,t;
    cin>>t;
    while(t--){
    cin >> n>>a>>b>>c;
        divisors(n,a,b,c);
    }
  
  return 0;
}