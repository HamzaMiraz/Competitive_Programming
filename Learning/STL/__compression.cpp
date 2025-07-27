#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

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
typedef long long LL;
const double PI = acos(-1);

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    map<string, int>mp, hm;

    vector<string>v = {"abc","a","a","abc","xyz","abc","abc"};

    int ind =0;
    for(auto s: v){
        if(mp.find(s)==mp.end()){
            mp[s] = ind++;
        }
    }

    for(string s: v)
        debug(s, mp[s]);

    deb(mp.size());

    mp.erase("abc");

    deb(mp.size());

    return 0;
}
