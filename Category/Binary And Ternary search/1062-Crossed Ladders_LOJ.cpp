
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

vector<int>primeFactors(int n){vector<int>PRIME;int c=2;while
(n>1){if(n%c==0){PRIME.push_back(c);n/=c;}else c++;}return PRIME;}

const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 2e9+10;
const int MOD = 1e9+7;

double x,y,H;

double hight(double d){
    double h1=sqrt((x*x)-(d*d));
    double h2=sqrt((y*y)-(d*d));

    double h=(h1*h2)/(h1+h2);///1/h = 1/h1 +1/h2;
    return h;
}

int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    int cs=1;
    while(t--)
    {
        cin>>x>>y>>H;
        double l,r,m;
        l=0.0,r=min(x,y);
        m=(l+r)/2;

        while(fabs(hight(m)-H)>.0000001){
            m=(l+r)/2;

            if(hight(m)<H)r=m;
            else l=m;
        }
        printf("Case %d: %0.6f\n",cs++,m);
    }
    return 0;
}
