#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

#include <map>

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

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    vector<string>vec = {"abc","a","a","bca","abc","abc","a","abc"};
    map<string,int>mp;
    for(auto s: vec)        ///for(int i=0;i<vec.size();i++)     s = vec[i];
    {
        cout<<s<<", ";
        mp[s]++;
    }
    cout<<endl;

    for(auto i: mp)
    {
        debug(i.first, i.second);       ///Like pair
    }

    deb(mp.size());

    return 0;
}
