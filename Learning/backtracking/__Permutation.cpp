#define LOCAL


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


#define popcount(a) (__builtin_popcountll(a))
#define SZ(a)       ((int)a.size())
#define pb          push_back

#define fs           first
#define sc           second
#define MP          make_pair

#define ll          long long
#define ld          long double

#define SS          stringstream
#define VS          vector<string>
#define VI          vector<int>
#define CON(a,b)  ((a).find(b)!=(a).end())
#define mem(a,b)    memset(a,b,sizeof(a))
#define memc(a,b)   memcpy(a,b,sizeof(b))
#define Accu(a,b,c) accumulate((a),(b),(c))
#define Unique(a)   a.erase(unique(a.begin(),a.end()),a.end())

#define fi(i,a,b)   for(int i=a;i<b;i++)
#define fii(a,b)    for(int i=a;i<b;i++)
#define fij(a,b)    for(int j=a;j<b;j++)
#define fik(a,b)    for(int k=a;k<b;k++)
#define fil(a,b)    for(int l=a;l<b;l++)
#define ri(i,a)     for(int i=0;i<a;i++)
#define rii(a)      for(int i=0;i<a;i++)
#define rij(a)      for(int j=0;j<a;j++)
#define rik(a)      for(int k=0;k<a;k++)
#define ril(a)      for(int l=0;l<a;l++)

#define ERR         (1e-7)
#define EQ(a,b)     (fabs((a)-(b))<ERR)
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
#define p2(a)       (1LL<<a)
#define EX(msk,a)   (msk&p2(a))
#define isInRange(v,l,h) (min(l,h)<=v && v<=max(l,h))

#define _d(a)       scanf("%d",&a)
#define _lld(a)     scanf("%lld",&a)
#define _lf(a)      scanf("%lf",&a)
#define _s(a)       scanf("%s",a)
#define _pd(a)      printf("%d\n",a)
#define _plld(a)    printf("%lld\n",a)
#define _plf(a)     printf("%lf\n",a)
#define _ps(a)     printf("%s\n",a)
#define _nl         printf("\n")

// #include <chrono>
// #include <thread>
// void Sleep(int ms){std::this_thread::sleep_for(std::chrono::milliseconds(ms));}

#ifdef LOCAL

#define PrintConP(mp)    {cout<<#mp<<" #=> ";for(auto &it: mp){cout<<it.first<<":"<<it.second<<", ";} cout<<endl;}
#define PrintCon(mp)    {cout<<#mp<<" #=> ";for(auto &it: mp){cout<<it<<", ";} cout<<endl;}
#define deb(a)      cout<<__LINE__<<"#-> "<<#a<<"  "<<a<<endl
#define debug(a...)          {cout<<" #--> ";dbg,a; cout<<endl;}

#else

#define MapPrint(mp)
#define ConPrint(mp)
#define deb(a)
#define debug(a...)

#endif

struct debugger
{
    ///Collected from rudradevbasak
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;


const double pi=acos(-1.0);
const double eps=1e-7;

template<class TT>void printV(vector<TT>&v, string t=""){cout<<t<<" => ";for(auto&i:v)    cout<<i<<", ";cout<<endl;}
template<class TT>TT sqr(TT a){return a*a;}
template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
typedef pair<int,int> pii;

// const LL MD = 1000000009;
const ll MD = 1000000007;

const int S = 15;

int n,r;
int color[S];
int sto[S];

void go(int d)
{
    char c;
     //scanf("%c",&c);
    // c = getchar();

    //deb(d);
    if(d==r){

        for(int i=0;i<r;i++)
        cout<<sto[i]; cout<<endl;
        return;
    }


//    for(int i=1;i<=n;i++)
//        if(color[i])
//            cout<<i<<", " ;
//    cout<<endl;

    for(int i=1;i<=n;i++){
        if(color[i])
        {
            sto[d] = i;

            color[i] = false;
           // debug(i, "Start");
            go(d+1);
            //debug(i, "End");
            color[i] = true;
        }
    }
}


// #define FILEINPUT
int main()
{
#ifdef FILEINPUT
 //     freopen("0.in","r",stdin);
//    freopen("out.out","w",stdout);
#endif // FILEINPUT

    while(cin>>n>>r){
        mem(color, true);
        go(0);
    }

    return 0;
}




