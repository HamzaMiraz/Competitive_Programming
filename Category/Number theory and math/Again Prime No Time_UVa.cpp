#include "bits/stdc++.h"
using namespace std;

#define MAXN 10003

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

map<int,int> prime_Factor_facturial(int n)
{
    map<int,int>mp;
    for(int i=2;i<=n;i++){
        int x=i;
        while (x != 1) {
           mp[spf[x]]++;
            x = x / spf[x];
        }
    }
    return mp;
}
map<int,int> getFactorization(int x)
{
    map<int,int>mp;
    while (x != 1) {
       mp[spf[x]]++;
        x = x / spf[x];

    }
    return mp;
}
int ks;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    int t;cin>>t;
    while(t--){
        cout<<"Case "<<++ks<<":\n";
        int n,m;
        cin>>m>>n;
        if(m<2 || n<2){
            if(m==n){
                cout<<"1\n";
            }else
                cout<<"Impossible to divide\n";
            continue;
        }
        map<int,int>mn=prime_Factor_facturial(n);
        map<int,int>mm=getFactorization(m);
        
        int max_pow=1e9;
        for(auto [f,s]: mm){
            max_pow=min(max_pow,mn[f]/mm[f]);
        }
        if(max_pow==0){
            cout<<"Impossible to divide\n";
            continue;
        }else
            cout<<max_pow<<"\n";

    }
    return 0;
}
