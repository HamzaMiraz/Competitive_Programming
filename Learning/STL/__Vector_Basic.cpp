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
#define accu(a,b,c) accumulate((a),(b),(c))

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

#define MapPrint(mp)    {cout<<#mp<<" #-> ";for(auto &it: mp){cout<<it.first<<":"<<it.second<<", ";} cout<<endl;}
#define ConPrint(mp)    {cout<<#mp<<" #-> ";for(auto &it: mp){cout<<it<<", ";} cout<<endl;}
#define deb(a)      cout<<"#"<<__LINE__<<" -> "<<#a<<"  "<<a<<endl
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

template<class TT>TT sqr(TT a){return a*a;}
template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
typedef pair<int,int> pii;

// const LL MD = 1000000009;
const ll MD = 1000000007;

void VectorInput(int n){
    vector<int>v(100);
    int val;
    for(int i=0;i<n;i++)
    {
        ///scanf("%d", &v[i]); //Wrong
        scanf("%d", &val);
        v[i] = val;
    }
}

void VectorInput2(int n){
    vector<int>v;
    int val;
    for(int i=0;i<n;i++)
    {
        ///scanf("%d", &v[i]); //Wrong
        scanf("%d", &val);
        v.push_back(val);
    }
}

void printVector(vector<int>&v, string s="")
{
    cout<<s<<" # Size: "<<v.size()<<" => {";

    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<"}"<<endl;
}

void Basic()
{


    vector<int> a;
    printVector(a, "FirstTime");

    a.push_back(10);
    printVector(a, "Second");
    a.push_back(15);
    printVector(a, "Third");

    a.clear();
    printVector(a, "AfterClear");
    for(int i=0;i<10;i++)
    a.push_back(i);
    printVector(a, "Repushing");


    int length = 9;
    int initialValue = -11;


    vector<int> b(length);
    debug(b.size(), b[5]);
    printVector(b,"B Vector");


    vector<int> c(length, initialValue);

    debug(c.size(), c[5]);
    printVector(c,"C Vector");

    vector<int> d{4, 5, 9, 10};
    printVector(d, "Vector D");
}


void Code1(){
    int a[100];
    vector<int> v(100);

    int* p = a; //a == &a[0];
    // int * pv = v;    //Error
}



//#define FILEINPUT
int main()
{
#ifdef FILEINPUT
      freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);
#endif // FILEINPUT
    // ios::sync_with_stdio(false);cin.tie(0);
    //std::srand ( unsigned ( std::time(0) ) );

    Basic();

    return 0;
}




