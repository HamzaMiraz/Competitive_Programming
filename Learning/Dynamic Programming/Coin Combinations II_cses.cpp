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
LL dp[1000007];

int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,s;
    while(cin>>n>>s)
    {
        int c[n+2];
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        memset(dp,0,sizeof dp);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=s;j++){
                if(j-c[i]>=0){
                    dp[j]=dp[j]+dp[j-c[i]]%MOD;
                }
            }
        }
        cout<<dp[s]%MOD<<endl;
    }
    return 0;
}
