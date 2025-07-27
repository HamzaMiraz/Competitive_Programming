#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
int n, k;

ll f(int n, int mask, vector<int>&a, vector<vector<ll>>&dp){
    if(n < 0){
        int cnt = __builtin_popcount(mask);
        return cnt == k;
    }
    ll &res = dp[n][mask];
    if(res != -1)return res;
    res = (f(n-1, mask & a[n], a, dp)+f(n-1, mask, a, dp)) % MOD;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;

    while(tt--){
        cin >> n >> k;
        vector<int>a(n);
        for(auto &it: a)cin >> it;
        vector<vector<ll>>dp(n,vector<ll>(64, -1));
        cout << f(n-1, 63, a, dp) - (k == 6)<< "\n";
    }

}
///https://codeforces.com/contest/1829/problem/H