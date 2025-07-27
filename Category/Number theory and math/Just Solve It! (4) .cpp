#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
ll n,m,l,r;
int32_t main() {
    ///zero based
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>l>>r;
    ll gcd=__gcd(n,m);
    if((r/m) < (n/gcd)){/// lcm > r
        cout<<"0\n";
        return 0;
    }
    ll lcm=(n*m)/gcd;
    l--;
    cout<<(r/lcm)-(l/lcm)<<"\n";
    
    return 0;
}