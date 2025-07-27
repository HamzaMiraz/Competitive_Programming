#include "bits/stdc++.h"
using namespace std;

#define MAXN 105

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
int ks;
void getFactorization(int n)
{
    cout<<"Case "<<++ks<<": "<<n<<" = ";
    map<int,int>mp;
    for(int x=2;x<=n;x++){
        int xx=x;
        while (xx != 1) {
            ++mp[spf[xx]];
            xx = xx / spf[xx];
        }
    }
    int sz=mp.size();
    int k=1;
    for(auto [p , o] : mp){
        cout<<p<<" ("<<o<<") ";
        if(k<sz)cout<<"* ";
        ++k;
    }
    cout<<"\n";
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
