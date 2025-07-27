#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//For Debugging
#define debug(a...)          {cout<<" #--> ";dbg,a; cout<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;


#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
typedef long long LL;
const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7

int main()
{
//    freopen("1.in", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    double r1,r2,r3,a,b,c,A,B,C,s,area;
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        a=r1+r2;
        b=r2+r3;
        c=r3+r1;
        s =(a+b+c)/2;
        C = acos((a*a+b*b-c*c)/(2*a*b));
        A = acos((b*b+c*c-a*a)/(2*b*c));
        B = acos((c*c+a*a-b*b)/(2*c*a));
        area =sqrt(s*(s-a)*(s-b)*(s-c))-(r1*r1*B+r2*r2*C+r3*r3*A)/2;
        printf("%.6lf\n",area);
    }
    return 0;
}
