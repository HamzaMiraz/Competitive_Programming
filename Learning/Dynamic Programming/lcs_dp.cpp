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
const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 2e9+10;

string txt,pat;
string ans;
int n,m;
int memo[100][100];
int lcs(int t,int p){
    if(t==n || p==m){
        return 0;
    }
    if(memo[t][p]!=-1)return memo[t][p];

    if(txt[t]==pat[p]){
        memo[t][p]=1+lcs(t+1,p+1);
    }
    else{
        memo[t][p]=max(lcs(t+1,p),lcs(t,p+1));
    }
    return memo[t][p];
}
void path(int t,int p){
    if(t==n || p==m)return;
    if(txt[t]==pat[p]){
        ans+=txt[t];
        path(t+1,p+1);
    }
    else if(memo[t+1][p]>memo[t][p+1]){
        path(t+1,p);
    }
    else {
        path(t,p+1);
    }
}
int main()
{
    while(cin>>txt>>pat){
        ans+="";
        memset(memo,-1,sizeof memo);
        n=txt.size();
        m=pat.size();
        cout<<"LCS = "<<lcs(0,0)<<endl;
        path(0,0);
        cout<<ans<<endl;
        txt.clear();pat.clear();
        ans.clear();
    }
    return 0;
}
// input:
//dacbk  dck
