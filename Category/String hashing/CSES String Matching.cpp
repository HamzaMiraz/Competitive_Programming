
//#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <ctype.h>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <utility>
#include <functional>
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <assert.h>

#include <unordered_set>
#include <unordered_map>

using namespace std;

#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//For Debugging
#define debug(a...)          {cout<<__LINE__<<" #--> ";dbg,a; cout<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;



#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define GCD(a,b)  __gcd(a,b)
#define LCM(a,b)  (a*b)/__gcd(a,b)
#define sqr(a)    ((a)*(a))
typedef long long LL;
LL BIGMOD(LL b,LL power,LL Mod){LL ans = 1;
while(power){if(power & 1)ans = (ans * b) % Mod;
b = (b * b) % Mod;power = power >> 1;}return ans;}

vector<int>primeFactors(int n){vector<int>PRIME;int c=2;while///prime factor
(n>1){if(n%c==0){PRIME.push_back(c);n/=c;}else c++;}return PRIME;}

LL nCr(LL n, LL r){LL res=1;for (LL i=0;i<r;i++){
res *= (n-i);res /= (i+1);}return res;}/// NCR

LL fact(LL n){if(n<=1)return 1;return n*fact(n-1);}
LL nPr(LL n, LL r){return fact(n)/fact(n-r);}///NPR

const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 2e9+10;
const int MOD = 1e9+7;
const int MAX = 1e6 + 10;
const LL base = 31;
LL p[MAX], rev_p[MAX], hsh[MAX];

LL InverseMod(LL a, LL b) {
  LL res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res % MOD;
}

void pre() {
  p[0] = 1;
  rev_p[0] = 1;
  LL rev_base = InverseMod(base, MOD-2);
  for (int i = 1; i < MAX; i++) {
    p[i] = p[i - 1] * base % MOD;
    rev_p[i] = rev_p[i - 1] * rev_base % MOD;
  }
}

int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
//    ios_base::sync_with_stdio(0); cin.tie(0);
    pre();
    string txt,pat;
    while(cin>>txt>>pat)
    {
        int n=txt.size();
        int m=pat.size();

        for(int i=0;i<n;i++){
            hsh[i+1]=(hsh[i]+(txt[i]*p[i])%MOD)%MOD;
        }
        LL pat_hsh=0;
        for(int i=0;i<m;i++){
            pat_hsh = (pat_hsh+(pat[i]*p[i])%MOD)%MOD;
        }
        LL res=0;
        for(int i=0;i+m<=n;i++){
            LL cur_hsh=((hsh[i+m]-hsh[i]+MOD)*rev_p[i])%MOD;
            if(cur_hsh==pat_hsh)++res;
        }
        cout<<res<<endl;
    }
    return 0;
}
