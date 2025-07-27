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

    vector<string>v = {"abc","a","a","abc","xyz","xyz","abc","abc","a"};

    ///N times use map of size R = O(N log R)
    mp["par"];
    int i = 0;
    for(auto s: v){
        mp[s]++;
        hm[s] = i++;
    }

    for(auto it: mp){
        debug(it.first, it.second);
    }

    for(auto it: hm){
        debug("HM", it.first, it.second);///it's define end of the position of the maps key
    }

    deb(mp.size());
    string key = "par";

    if(mp.find(key) != mp.end()){
        puts("Not Found");
    }
    else {
        puts("Found");
    }

    map<string, int>::iterator it = mp.find(key);

    if(it!=mp.end()){
        debug(it->first, it->second);
    }

    return 0;
}
