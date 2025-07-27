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
#define sqr(a)   ((a)*(a))
typedef long long LL;
const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 1e8+0.5;

struct point{
    double x,y,z;
};
point p[105],mx,mn,ans;
int n;

double dis(double x,double y,double z){
    double MAX=0;
    for(int i=0;i<n;i++)
        MAX=max(MAX,sqrt(sqr(x-p[i].x)+sqr(y-p[i].y)+sqr(z-p[i].z)));
    return MAX;
}
double z_axis(double x,double y){
    double lz=mn.z,rz=mx.z,lp,rp,dl,dr;
    for(int i=0;i<40;i++){
        lp=lz+((rz-lz)/3);
        rp=rz-((rz-lz)/3);
        dl=dis(x,y,lp);
        dr=dis(x,y,rp);
        if(dl<dr) rz=rp;
        else lz=lp;
    }
    ans.z=lp;
    return dl;
}
double y_axis(double x){
    double ly=mn.y,ry=mx.y,lp,rp,dl,dr;
    for(int i=0;i<40;i++){
        lp=ly+((ry-ly)/3);
        rp=ry-((ry-ly)/3);
        dl=z_axis(x,lp);
        dr=z_axis(x,rp);
        if(dl<dr) ry=rp;
        else ly=lp;
    }
    ans.y=lp;
    return dl;
}
void ternarySearch(){
    double lx=mn.x,rx=mx.x,lp,rp,dl,dr;
    for(int i=0;i<40;i++){
        lp=lx+((rx-lx)/3);
        rp=rx-((rx-lx)/3);
        dl=y_axis(lp);
        dr=y_axis(rp);
        if(dl<dr) rx=rp;
        else lx=lp;
    }
     ans.x=lp;
}
int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    while(cin>>n)
    {
        for(int i=0;i<n;i++){
            cin>>p[i].x>>p[i].y>>p[i].z;
            if(!i){
                mx=p[i];
                mn=p[i];
                continue;
            }
            mx.x=max(mx.x,p[i].x);
            mx.y=max(mx.y,p[i].y);
            mx.z=max(mx.z,p[i].z);

            mn.x=min(mn.x,p[i].x);
            mn.y=min(mn.y,p[i].y);
            mn.z=min(mn.z,p[i].z);
        }
        ternarySearch();
        printf("%.6f %.6f %.6f\n",ans.x,ans.y,ans.z);

    }
    return 0;
}
