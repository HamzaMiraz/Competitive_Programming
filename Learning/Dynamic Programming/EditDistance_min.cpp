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
#define el         "\n"
#define dec(n,x)  fixed << setprecision(x) <<n
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
string s1,s2;
int memo[100][100];
int EditDistance(int i,int j){
    if(i<0)return j+1;
    if(j<0)return i+1;

    if(memo[i][j]!=-1)return memo[i][j];

    if(s1[i]==s2[j])
        return memo[i][j]= EditDistance(i-1,j-1);

    /// any move cost 1
    int Insert = 1 + EditDistance(i,j-1);
    int Delete = 1 + EditDistance(i-1,j);
    int Remove = 1 + EditDistance(i-1,j-1);

    return memo[i][j]=min({Insert,Delete,Remove});
}
int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
//    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin>>s1>>s2)
    {
        memset(memo,-1,sizeof memo);
        cout<<EditDistance(s1.size()-1,s2.size()-1)<<el;
        s1.clear();
        s2.clear();
    }
    return 0;
}
/**
/// first make 0 base then make iterative
int main()
{
//   freopen("in.in", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
//    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin>>s1>>s2)
    {
        int n=s1.size();
        int m=s2.size();
        int dp[n+2][m+2];
        memset(dp,0,sizeof dp);
        /// base case
        for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int j=0;j<=m;j++)dp[0][j]=j;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

            if(s1[i-1]==s2[j-1]){
                dp[i][j]= dp[i-1][j-1];
            }
            else{
                int Insert = 1 + dp[i][j-1];
                int Delete = 1 + dp[i-1][j];
                int Remove = 1 + dp[i-1][j-1];
                dp[i][j]=min({Insert,Delete,Remove});
            }
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
**/

/**
/// space optimize
int main()
{
///   freopen("in.in", "r", stdin);  ///To read from a file.
    //freopen("out.txt", "w", stdout);  ///To write  a file.
    //ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin>>s1>>s2)
    {
        int n=s1.size();
        int m=s2.size();
        vector<int>prev(m+1,0),cur(m+1,0);
        /// base case
        for(int i=0;i<=n;i++)cur[0]=i;
        for(int j=0;j<=m;j++)prev[j]=j;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(s1[i-1]==s2[j-1]){
                    cur[j]= prev[j-1];
                }
                else{
                    int Insert = 1 + cur[j-1];
                    int Delete = 1 + prev[j];
                    int Remove = 1 + prev[j-1];
                    cur[j]=min({Insert,Delete,Remove});
                }
            }
            prev=cur;
        }
        cout<<cur[m]<<endl;
    }
    return 0;
}
**/
