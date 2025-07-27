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
#define sqr(a)    ((a)*(a))
typedef long long LL;
const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 2e9+10;

char Text[1000010];
char Pattern[1000010];
int Prefix[1000010];

void Compute_Prefix_Function(int m)///j....i,prefix matching j to i
{
    int i,j;
    j = 0;
    Prefix[0]=0;
    for(i=1;i<m;i++)
    {
        while((j>0) && (Pattern[j] != Pattern[i]))
            j = Prefix[j-1];

        if(Pattern[j] == Pattern[i])
            j = j + 1;

        Prefix[i]=j;
    }
}

int KMP(int m,int n)
{
    int i,j;
    j = 0;
    for(i=0;i<n;i++)
    {
        while((j>0) && (Pattern[j] != Text[i]))
            j = Prefix[j-1];

        if(Pattern[j]==Text[i])
        {
            j = j + 1;///j = number of characters have been matched so far

        }
        else
            j = Prefix[j];
    }
    return j;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int m,n,t;
    scanf("%d",&t);
    getchar();
    for(int i=1;i<=t;i++)
    {
        scanf("%s",Text);

        strcpy(Pattern,Text);

        n = strlen(Pattern);

        reverse(Pattern,Pattern+n);
        Compute_Prefix_Function(n);

        int match = KMP(n,n);///number of pattern's character matched with Text's character

        printf("Case %d: %d\n",i,2*n-match);
    }

    return 0;
}
