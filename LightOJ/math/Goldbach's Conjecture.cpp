#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9;
bitset<N> not_prime;
vector<int> primes;
void sieve(){
    not_prime[1] = true;
    for (int i = 2; i * i <= N; i++) {
        if (!not_prime[i]) {
          for (int j = i * i; j <= N; j += i) {
            not_prime[j] = true;
          }
        }
    }
    for (int i = 2; i <= N; i++) {
        if (!not_prime[i]) { 
          primes.push_back(i);
        }
    }
}
int ks,n;
int32_t main() {
    ///zero based
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t;cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        for(int i=0;primes[i]<=n/2;i++){
            if(!not_prime[n-primes[i]])ans++;

        }
        cout<<"Case "<<++ks<<": "<<ans<<'\n';
    }



  return 0;
}
