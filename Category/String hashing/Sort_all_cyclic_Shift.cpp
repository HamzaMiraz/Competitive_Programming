#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F  first
#define S  second
const int MAX = 2e6 + 10;// string max size
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll base1 = 269;//31,//53
const ll base2 = 277;//31,//53

pair<ll,ll> pw[MAX], inv_pw[MAX];
string txt,pat;
ll BIGMOD(ll b,ll power,ll Mod){
    ll ans = 1;
    while(power){
        if(power & 1)ans = (ans * b) % Mod;
        b = (b * b) % Mod;power = power >> 1;}
    return ans%Mod;
}

void pow_clc(){
    ll rev_base1=BIGMOD(base1,MOD1-2,MOD1);///base1^-1
    ll rev_base2=BIGMOD(base2,MOD2-2,MOD2);///base2^-1
    pw[0]={1,1};
    inv_pw[0]={1,1};
    for(int i=1;i<MAX;i++){
        pw[i].F = 1LL * pw[i-1].F * base1 % MOD1;
        inv_pw[i].F = 1LL * inv_pw[i-1].F * rev_base1 % MOD1;
        pw[i].S = 1LL * pw[i-1].S * base2 % MOD2;
        inv_pw[i].S = 1LL * inv_pw[i-1].S * rev_base2 % MOD2;
    }
}
vector<pair<ll,ll>>txthsh;
void hashing_txt(string const &txt){///make a hash array in O(string size)
    int len=txt.size();
    txthsh.resize(len+4);
    txthsh[0]={0,0};
    for(int i=0;i<len;i++){
        txthsh[i+1].F = (txthsh[i].F + (txt[i] * pw[i].F)%MOD1)%MOD1;
        txthsh[i+1].S = (txthsh[i].S + (txt[i] * pw[i].S)%MOD2)%MOD2;

    }
}
ll substring_hash(int i,int j,vector<pair<ll,ll>> & hsh){///O(1)
    pair<ll,ll>hs;
    hs.F=(((hsh[j+1].F-hsh[i].F+MOD1)%MOD1)*(inv_pw[i].F%MOD1))%MOD1;
    hs.S=(((hsh[j+1].S-hsh[i].S+MOD2)%MOD2)*(inv_pw[i].S%MOD2))%MOD2;
    return (hs.F*MOD2 + hs.S);
}
int lcp(int i1,int j1,int i2,int j2){
     int l=1,r=min(j1-i1+1,j2-i2+1);
     int ans=0;
     while(l<=r){
         int mid =l+r >>1;
         if(substring_hash(i1,i1+mid-1,txthsh)==substring_hash(i2,i2+mid-1,txthsh)){
             ans=mid;
             l=mid+1;
         }else{
             r=mid-1;
         }
     }
     return ans;
}
int ln;
bool com(pair<int,int>a,pair<int,int>b){
    int ans=lcp(a.F,a.S,b.F,b.S);
    if(ans==ln)return a>b;
    else{
        if(txt[a.F+ans]<txt[b.F +ans])return a>b;
        else{
            return a<b;
        }
    }

}
int main() {
    ///zero based
    //ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    pow_clc();
    while(cin>>txt){
        ln=txt.size();
        txt+=txt;
        hashing_txt(txt);
        vector<pair<int,int>>v;
        for(int i=0;i+ln<txt.size();i++){
            v.push_back({i,i+ln-1});
        }
        sort(v.begin(),v.end(),com);
        for(int i=0;i<v.size();i++){
            cout<<txt.substr(v[i].F,ln)<<"\n";
        }
        
    }
    return 0;
}
