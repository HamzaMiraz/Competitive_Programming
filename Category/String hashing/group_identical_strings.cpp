#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F  first
#define S  second
const int MAX = 1e6 + 10;// string max size
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
/// find same strings index & insert a group .O(nm +nlogn)
void group_identical_strings(vector<string> const& s) {
    ///example s={"aa","bb","ac","ab","aa","ab","dd","aa"};
    int n = s.size();
    vector<pair<ll, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_prehash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    cout<<"Number of Distinct strings: "<<groups.size()<<"\n";
    cout<<"identical group of strings:\n";///denote by indexs
    for(auto it : groups){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
int main() {
    ///zero based
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    pow_clc();

    vector<string> txt={"aa","bb","ac","ab","aa","ab","dd","aa"};
    group_identical_strings(txt);
    
    return 0;
}