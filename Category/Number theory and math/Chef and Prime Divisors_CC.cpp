#include<bits/stdc++.h>
using namespace std;

using ll=long long;
int ks,n;
int32_t main() {
    ///zero based
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll g;
        while((g=__gcd(a,b))!=1)b/=g;
        
        if(b==1)cout<<"Yes\n";
        else{
            cout<<"No\n";
        }

    }



  return 0;
}
