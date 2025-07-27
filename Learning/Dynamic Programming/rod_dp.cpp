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

int n,m,ar[100];
int memo[100];
int go(int x){
    if(x==0)return 0;
    if(x<0)return -oo;

    if(memo[x]!=-1)return memo[x];
    memo[x]=-oo;

    for(int i=1;i<=m;i++){
        memo[x]=max(memo[x],go(x-i)+ar[i]);
    }
    return memo[x];

}
int main()
{
    while(cin>>n>>m){
        memset(memo,-1,sizeof memo);
        for(int i=1;i<=m;i++)cin>>ar[i];

        cout<<"value :"<<go(n)<<endl;
    }
	return 0;
}

