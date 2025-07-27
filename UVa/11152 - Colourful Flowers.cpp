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
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    int a, b, c;
    while(scanf("%lld %lld %lld", &a, &b, &c) == 3)
    {
        double roses, violets, sunflowers,tringle;
        double r, R, s = (a+b+c)/2.0;
        tringle = sqrt(s*(s-a)*(s-b)*(s-c));
        r = tringle*2/(double)(a+b+c);
        roses = r*r*PI;
        R = a*b*c/(4.0*tringle);
        sunflowers = R*R*PI - tringle;
        violets = tringle - roses;
        printf("%.4lf %.4lf %.4lf\n", sunflowers, violets, roses);

    }
    return 0;
}
