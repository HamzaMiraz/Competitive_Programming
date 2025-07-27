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
const int oo = 1e8+0.5;

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file
    int ar[5]={2,-1,6,10,3};
    vector<int>vec(3,5);///vectore initlize by three 5 [555]
   /// vector<int>vec(ar,ar+4);///array insert on vector

    vec.push_back(7);
    vec.push_back(3);
    vec.push_back(31);
    vec.push_back(91);
    vec.push_back(9);
    vec.push_back(1);
    vec.push_back(8);
    vec.push_back(31);
    vec.push_back(91);
    vec.push_back(2);

    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n"<<endl;

    sort(vec.begin(),vec.begin() +8 );///sort first 8 element

    for(int i =0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n"<<endl;

    sort(vec.begin(),vec.end());///sort all element

    for(int i =0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n"<<endl;

    vec.clear();

    return 0;
}
