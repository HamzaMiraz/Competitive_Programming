#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
using ll = long long;
int spf[N];
ll sum[N];
int divs[N];
int ar[N];
struct triple{
    int gpf,distinct,primes_cnt;
};
void spf_pre_clc(){///nlog(log(n))
    for(int i=2;i<=N;i++){
        spf[i]=i;
        sum[i]=1;
        divs[i]=1;
    }
    for(int div=2;div<=N;div++){
        for(int i=div;i<=N;i+=div){
            spf[i]=min(spf[i],div);
            sum[i]+=div;
            divs[i]++;
        }
    }
}
triple prime_factors(int n){///log(n)
    set<int>st;
    int cnt=0;
    int mx=0;
    while(n>1){
        st.insert(spf[n]);
        mx=max(mx,spf[n]);
        ++cnt;
        n/=spf[n];
    }
    int unique_prime=st.size();
    //cout<<mx<<"\n";
    return {mx,unique_prime,cnt};
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    spf_pre_clc();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        triple ans = prime_factors(ar[i]);
        cout<<spf[ar[i]]<<" "<<ans.gpf<<" "<<ans.distinct<<" "<<ans.primes_cnt<<" "<<divs[ar[i]]<<" "<< sum[ar[i]]<<"\n";
    }
    

    
  
  return 0;
}