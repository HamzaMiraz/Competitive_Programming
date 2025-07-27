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
const int oo = 2e9+10;

double  ab,ac,bc,Ratio;
double isRatio(double ad){
    double ae,de,s1,s2,area1,area2,trapezium;
        ae=(ad*ac)/ab;
        de=(ad*bc)/ab;
        s1=(ad+ae+de)/2;///s for ADE
        s2=(ab+ac+bc)/2;///s for ABC
        area1=sqrt(s1*(s1-ad)*(s1-de)*(s1-ae));///area of ADE
        area2=sqrt(s2*(s2-ab)*(s2-bc)*(s2-ac));///area of ABC
        trapezium=area2-area1;///area of DECB
    return area1/trapezium;
}

double binarysearch(){
    double left=0,right=ab,mid;
    double ad=(left+right)/2;
    while(fabs(isRatio(ad)-Ratio)>1e-7){
        ad=mid=(left+right)/2;
        if(isRatio(ad)>Ratio)
            right=mid;
        else
            left=mid;
    }
    return ad;
}
int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int cs,i=0;
    scanf("%d",&cs);
    while(cs--)
    {
        scanf("%lf%lf%lf%lf",&ab,&ac,&bc,&Ratio);
        printf("Case %d: %.7lf\n",++i,binarysearch());
    }
    return 0;
}
