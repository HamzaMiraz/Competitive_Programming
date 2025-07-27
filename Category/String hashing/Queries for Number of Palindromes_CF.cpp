#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F  first
#define S  second
const int MAX = 5010;// string max size
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll base1 = 269;//31,//53
const ll base2 = 277;//31,//53
pair<ll,ll> pw[MAX], inv_pw[MAX];

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
ll compute_prehash(string const &s){///O(string size)
    pair<ll,ll> hash_value={0,0};
    for(int i=0;i<s.size();i++){
        hash_value.F = (hash_value.F + (s[i]*pw[i].F)%MOD1)%MOD1;
        hash_value.S = (hash_value.S + (s[i]*pw[i].S)%MOD2)%MOD2;
    }return (hash_value.F*MOD2 + hash_value.S);
}
vector<pair<ll,ll>>prehsh,sufhsh;
int len;
string s;
void hashing(string const &s){///make a hash array in O(string size)
    len=s.size();
    prehsh.resize(len+4);
    sufhsh.resize(len+4);

    for(int i=0;i<len;i++){
        prehsh[i].F= (1LL*s[i]*pw[i].F) %MOD1;
        prehsh[i].S= (1LL*s[i]*pw[i].S) %MOD2;
        if(i){
            prehsh[i].F= (prehsh[i].F + prehsh[i-1].F) %MOD1;
            prehsh[i].S= (prehsh[i].S + prehsh[i-1].S) %MOD2;
        }
        sufhsh[i].F= (1LL*s[i]*pw[len-i-1].F) %MOD1;
        sufhsh[i].S= (1LL*s[i]*pw[len-i-1].S) %MOD2;
        if(i){
            sufhsh[i].F= (sufhsh[i].F + sufhsh[i-1].F) %MOD1;
            sufhsh[i].S= (sufhsh[i].S + sufhsh[i-1].S) %MOD2;
        }
    }
}
ll substring_hash(int i,int j){///O(1)
    assert(i<=j);
    pair<ll,ll>hs({0,0});
    hs.F=prehsh[j].F;
    hs.S=prehsh[j].S;
    if(i){
        hs.F=(hs.F- prehsh[i-1].F +MOD1)%MOD1;
        hs.S=(hs.S- prehsh[i-1].S +MOD2)%MOD2;
    }
    hs.F= (1LL* hs.F * inv_pw[i].F)%MOD1;
    hs.S= (1LL* hs.S * inv_pw[i].S)%MOD2;
    
    return (hs.F*MOD2 + hs.S);
}
ll GetPrefixHash(int i,int j){
    return substring_hash(i, j);
}
ll GetSuffixHash(int i,int j){
    assert(i<=j);
    pair<ll,ll>hs({0,0});
    hs.F=sufhsh[j].F;
    hs.S=sufhsh[j].S;
    if(i){
        hs.F=(hs.F- sufhsh[i-1].F +MOD1)%MOD1;
        hs.S=(hs.S- sufhsh[i-1].S +MOD2)%MOD2;
    }
    hs.F= (1LL* hs.F * inv_pw[len-j-1].F)%MOD1;
    hs.S= (1LL* hs.S * inv_pw[len-j-1].S)%MOD2;
    
    return (hs.F*MOD2 + hs.S);
}
int IsPallindrome(int l , int r) {
    return (GetPrefixHash(l , r) == GetSuffixHash(l , r));
}
int dp[5010][5010];
int number_of_palindrome(int i,int j){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=IsPallindrome(i,j)+
        number_of_palindrome(i+1,j)+number_of_palindrome(i,j-1)-number_of_palindrome(i+1,j-1);
}
int main() {
    ///zero based
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    pow_clc();
    int q;
    cin>>s;
        cin>>q;
        hashing(s);
        memset(dp,-1,sizeof dp);
        while(q--){
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<number_of_palindrome(l,r)<<"\n";
        }
    
    return 0;
}