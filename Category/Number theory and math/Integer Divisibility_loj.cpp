#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int ks;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    int n,d; cin >> n>>d;
    int cur=0,len=0;
    while(1){
        cur=(cur*10+d)%n;
        len++;
        if(cur==0)break;
    }
    cout<<"Case "<<++ks<<": "<<len<<"\n";
  }
  
  
  return 0;
}