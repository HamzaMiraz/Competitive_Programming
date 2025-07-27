//#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
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
#define sqr(a)      ((a)*(a))
typedef long long LL;
const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 1e8+0.5;
char str[1010];
int memo[1010][1010];
int lngstPlndrm(int l,int r){
    if(l==r)return 1;
    if(l+1==r){
        if(str[l]==str[r])return 2;
        else return 1;
    }
    int &rf=memo[l][r];
    if(rf!=-1)return rf;

    if(str[l]==str[r]){
          rf=2+lngstPlndrm(l+1,r-1);
    }
    else{
          rf=max(lngstPlndrm(l+1,r),lngstPlndrm(l,r-1));
    }
    return rf;
}

int main()
{
//    freopen("11151.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int t;
    scanf("%d",&t);///cin>>t;

    getchar();///getc(stdin);///cin.ignore();
    while(t--)
    {
        gets(str);///getline(cin,str);
        memset(memo,-1,sizeof memo);
        if(strlen(str)==0){
            cout<<"0"<<endl;
            continue;
        }
        cout<<lngstPlndrm(0,strlen(str)-1)<<endl;
    }
    return 0;
}
