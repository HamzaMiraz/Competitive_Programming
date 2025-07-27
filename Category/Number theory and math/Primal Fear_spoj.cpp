#include<bits/stdc++.h>
using namespace std;

///Nlog(N)
const int N = 1e6+9;
bitset<N> not_prime;
int valid_primecnt[N];
int pre[N];

void sieve(){
    not_prime[1] = true;
    for (int i = 2; i * i <= N; i++) {
        if (!not_prime[i]) {
          for (int j = i * i; j <= N; j += i) {
            not_prime[j] = true;
          }
        }
    }
}

bool isvalid(int x){
    int X=x;
    while(x){
        if(x%10==0)return false;
        x/=10;
    }
    x=X;
    string s=to_string(x);
    int len=s.size()-1;
    int i=1;
    while(len){
        string ss=s.substr(i,len);
        int xx=stoi(ss);
        if(not_prime[xx])return false;
        i++,len--;
    }
    return true;
}
void valid_prime(){
    int mx=0;
    for (int i = 2; i <= N; i++) {
        if (!not_prime[i]) { 
            mx=max(mx,i);
            if(isvalid(i)){
                valid_primecnt[i]=1;
            }
          
        }
    }
   // cout<<mx<<"\n";
    for(int i=2;i<=N;i++){
        pre[i]=valid_primecnt[i]+pre[i-1];
    }
}
int32_t main() {
    ///zero based
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    valid_prime();
    int n,t;cin>>t;
    while(t--){
        cin>>n;
        cout<<pre[n]<<"\n";
    }

  return 0;
}