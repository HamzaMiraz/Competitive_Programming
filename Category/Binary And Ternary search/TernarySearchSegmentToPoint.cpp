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

// #include <bits/stdc++.h>
using namespace std;


#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define PrintP(mp)    {cout<<__LINE__<<"# "<<#mp<<" #=> ";for(auto &it: mp){cout<<it.first<<":"<<it.second<<", ";} cout<<endl;}
#define Print(mp)    {cout<<__LINE__<<"# "<<#mp<<" #=> ";for(auto &it: mp){cout<<it<<", ";} cout<<endl;}
#define deb(a)      cout<<__LINE__<<"#-> "<<#a<<"  "<<a<<endl

#define debug(a...)          {cout<<" #--> ";dbg,a; cout<<endl;}
struct debugger
{
    ///Collected from rudradevbasak
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;

template<class TT>TT sqr(TT a){return a*a;}

struct P{
    double x;
    double y;

    P(double xi=0, double yi=0){
        x = xi;
        y = yi;
    }

    int scan(){
        return scanf("%lf%lf",&x,&y);
    }

    double distance(P b){
        return sqrt(sqr(b.x-x)+sqr(b.y-y));
    }
};
int main()
{
    // freopen("0.in","r",stdin);
    // freopen("0.out","w",stdout);
    // ios::sync_with_stdio(false);cin.tie(0);

    int tks=1, ks = 1;

    // scanf("%d",&tks);
    // while(tks--){}
    P left, right, target;

    while(2 == left.scan()){
        right.scan();
        target.scan();

        P leftPivot, rightPivot;
        const double eps = 1e-7;    //eps might change based on the decimal precission asked in problem statement.
        int numberOfIteration = 0;

        while(left.distance(right)>eps)
        {
            leftPivot = P((2*left.x +right.x) / 3,(2*left.y +right.y) / 3);
            rightPivot = P((left.x+ 2*right.x) / 3, (left.y+ 2*right.y) / 3);

            double leftPivotDistance = leftPivot.distance(target);
            double rightPivotDistance = rightPivot.distance(target);

            if(leftPivotDistance < rightPivotDistance){
                right = rightPivot;
            }
            else {
                left = leftPivot;
            }
            numberOfIteration++;
        }
        printf("Closest Point: (%f , %f) after %d iteration\n", left.x, left.y, numberOfIteration);
    }


    return 0;
}


/*
INPUT:
0 10
10 0
1 1

2 2
10 7
1 1

OUTPUT:
Closest Point: (5.000000 , 5.000000) after 47 iteration
Closest Point: (2.000000 , 2.000000) after 46 iteration


*/



