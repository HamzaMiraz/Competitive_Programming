#include<bits/stdc++.h>
using namespace std;
using ll= long long;
/// nlog(n)
#define SIZE_N 10010000///finding all prime number under SIZE_N
bool isprime [SIZE_N];
vector<int>prime;

void sieve()
{
    int i, j, r;
    for ( i = 3; i <= SIZE_N; i += 2 )
        isprime[i] = true ;

    isprime [2] = true ;
    prime.push_back(2);

    for ( i = 3; i <= SIZE_N; i += 2 )
        if ( isprime[i] == true )
        {
            prime.push_back(i);

            if ( SIZE_N/i >= i )
            {
                r = i * 2 ;
                for ( j = i * i; j <= SIZE_N; j += r )
                    isprime[j] = false ;///unprime all nums which is divisible by i
            }
        }
}

void prime_factors(int n,map<int,int>&mp){
    for(int i=0; prime[i]*prime[i]<=n && i<prime.size() ; i++){
        while(n%prime[i]==0){
            mp[prime[i]]++;
            n/=prime[i];
        }
    }
    if(n>1)mp[n]++;
}
long long power(long long b,long long power,long long Mod){
    long long ans = 1;
    while(power){
        if(power & 1)ans = (ans * b) % Mod;
        b = (b * b) % Mod;power = power >> 1;}
    return ans%Mod;
}
int32_t main(){
    sieve();
    int n,m;
    map<int,int>mpA;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        prime_factors(x,mpA);
    }
    map<int,int>mpB;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x;
        prime_factors(x,mpB);
    }
    ll ans=1;
    ll mod=1e9;
    bool gtr_tn_1e9=false;
    for(auto [p,o] : mpA){
        ans*=power(p,min(mpA[p],mpB[p]),mod);
        if(ans>=mod)gtr_tn_1e9=true;
        ans%=mod;
    }
    if(gtr_tn_1e9){
        vector<int>num;
        while(ans){
            num.push_back(ans%10);
            ans/=10;
            if(num.size()>9)break;
        }
        while(num.size()<9){
            num.push_back(0);
        }
        for(int i=8;i>=0;i--){
            cout<<num[i];
        }cout<<"\n";
    }else{
        cout<<ans<<"\n";
    }
  return 0;
}
