#include "bits/stdc++.h"
using namespace std;

using ll=long long;
const ll mod=1e9+7;
#define MAXN 50002

int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
void getFactorization(int n)
{
    vector<int>ep(n+2,0);
    for(int x=2;x<=n;x++){
        int xx=x;
        while (xx != 1) {
            ++ep[spf[xx]];
            xx = xx / spf[xx];
        }
    }
    ll ans=1;
    for(auto e : ep){

        ans=1LL*ans*(e+1);
        ans%=mod;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        getFactorization(n);
    }

    return 0;
}
