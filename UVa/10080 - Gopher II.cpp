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
#define pb push_back
typedef long long LL;
const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 2e9+10;


const int SIZE = 100;

struct coordinate
{
    double x,y;
};

coordinate hole[SIZE],gopher[SIZE];
bool colour[SIZE];
vector<int> l[SIZE];
int p[SIZE];

bool DFS(int u)
{
    int i,j;

    for(i=0;i<l[u].size();i++)
        if(colour[l[u][i]])
        {
            colour[l[u][i]] = false;

            if(p[ l[u][i] ]<0 || DFS(p[l[u][i]]))
            {
                p[l[u][i]] = u;
                return true;
            }
        }

    return false;
}

int main()
{
    //freopen("in.txt","r",stdin);

    int i,c,j,n,m;
    double d,s,v;

    while(4==scanf("%d%d%lf%lf",&n,&m,&s,&v))
    {
        d = s*v;

        for(i=0;i<n;i++)
            scanf("%lf%lf",&gopher[i].x,&gopher[i].y);

        for(i=0;i<m;i++)
            scanf("%lf%lf",&hole[i].x,&hole[i].y);

        for(i=0;i<m;i++)
            l[i].clear();

        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if( sqrt(sqr(hole[i].x-gopher[j].x) + sqr(hole[i].y-gopher[j].y) ) < d ||
                   fabs(sqrt(sqr(hole[i].x-gopher[j].x) + sqr(hole[i].y-gopher[j].y)) - d ) < EPS )
                   {
                        l[i].pb(j);
                   }
            }

        c = 0;
        for(i=0;i<100;i++)
            p[i]= -1;

        for(i=0;i<m;i++)
        {
            for(j=0;j<100;j++)
                colour[j]= true;

            if(DFS(i))
                c++;
        }
        printf("%d\n",n-c);
    }

    return 0;
}
