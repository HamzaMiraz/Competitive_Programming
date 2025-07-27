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

struct Point{
    double x,y;
};

double dis(double x1,double y1,double x2,double y2)
{
    return sqrt(sqr(x1-x2)+sqr(y1-y2));
}
int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    Point l,r,t,m1,m2;
    while(cin>>l.x>>l.y>>r.x>>r.y>>t.x>>t.y)
    {
        while(dis(l.x,l.y,r.x,r.y)>0.000001)
        {
            m1.x=l.x+(r.x - l.x)/3;
            m2.x=r.x-(r.x - l.x)/3;
            m1.y=l.y+(r.y - l.y)/3;
            m2.y=r.y-(r.y - l.y)/3;

            double lpd=dis(m1.x,m1.y,t.x,t.y);
            double rpd=dis(m2.x,m2.y,t.x,t.y);

            if(lpd<rpd)
            {
                r=m2;
            }
            else
            {
                l=m1;
            }
        }
        cout<<r.x<<" "<<r.y<<endl;
    }
    return 0;
}
/*

0 10
10 0
1 1

2 2
10 7
1 1

*/
