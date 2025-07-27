#include<bits/stdc++.h>
using namespace std;
using ll= long long;
/// nlog(n)
const ll  SIZE_N=1e6;///finding all prime number under SIZE_N
bool isprime [SIZE_N];
vector<ll>prime;
vector<ll>kk[100005];
void sieve()
{
    ll i, j, r;
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
/// it can find 1e18 numbers prime fectors
ll cnt_divs(ll n){
    ll divs=1;
    for(ll i=0; prime[i]*prime[i]<=n && i<prime.size() ; i++){
        ll e=0;
        while(n%prime[i]==0){
            e++;
            n/=prime[i];
        }
        divs*=(2*e  + 1);///2x becouse i^2
    }
    if(n>1)divs*=(2*1  + 1);
    return divs;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    ///only squre numbers have odd divisors
    for(ll i=1;1LL*i*i<=10000000000;i++){
        kk[cnt_divs(i)].push_back(i*i);///finding i^2 s divisors
    }
    ll q,k;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>k>>l>>r;
        auto ans=upper_bound(kk[k].begin(),kk[k].end(),r)-lower_bound(kk[k].begin(),kk[k].end(),l);
        cout<<ans<<"\n";
    }
  return 0;
}