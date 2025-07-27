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

double dis(double w,double l,double x)
{

    double a=((cos(x)*l)/(1+cos(x)));

    double b=sin(x)*(l-a);

    return w-b+(2*l)-(2*a);
}
int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    double w,l,a1,a2;
    while(cin>>l>>w)
    {
        if(l==0 && w==0)break;

        double L,R,m1,m2;
        L=.01;
        R=PI/2;
        //R and L both  r theta value

        while(fabs(dis(w,l,L)-dis(w,l,R))>0.000001)
        {
            m1=L+(R-L)/3.0;
            m2=R-(R-L)/3.0;

            double d1=dis(w,l,m1);///d1=dis(w,l,L);

            double d2=dis(w,l,m2);///d1=dis(w,l,R);

            if(d1>d2)
            {
                L=m1;
            }
            else
            {
                R=m2;
            }
        }
        printf("%.4f\n",dis(w,l,L));
    }

    return 0;
}
/*
11 23
7 13
0 0
*/

