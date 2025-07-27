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
    int n;
    double r1, r2, r3, t1,t2,t3;
    double area, a, b, c, s, A,k1,k2,k3;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf %lf %lf",&r1,&r2,&r3);

        a = r1+r2, b = r2+r3, c = r3+r1;
        s = (a+b+c)/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));

        t1 = acos((a*a+c*c-b*b)/(2*a*c));
        t2 = acos((a*a+b*b-c*c)/(2*a*b));
        t3 = acos((c*c+b*b-a*a)/(2*c*b));

        k1=r1*r1*t1/2;
        k2=r2*r2*t2/2;
        k3=r3*r3*t3/2;

        A=area-k1-k2-k3;
        printf("%0.6lf\n",A);

    }
    return 0;
}

