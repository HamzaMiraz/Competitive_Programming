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

    double in[10];      //index_type/Key_type: integer, value_type = double

    map<int, double>mp;
    mp[5] = 3;
    mp[-22] = 7;
    mp[2147483947] = -1;

    int v = mp[5];

    deb(v);
    deb(mp[2147483947]);
    deb(mp.size());

    if(mp.find(-22) != mp.end())
    {
        puts("Exist");
    }
    else puts("Not Exist!");

    map<string, double>sm;

    sm["hamza"] = 23.4;///mp.insert(make_pair("hamza",23.4));
    sm["maria"] = -23.9;
    sm.insert(make_pair("nabil",41));
    deb(sm["hamza"]);
    deb(sm.size());
    mp.clear();

    deb(sm.size());
    puts("++++++++++++++++++++++++");
    sm["z"] = 5;
    sm["c"] = 2;
    sm["b"] = 4.1;
    deb(mp.size());
    deb(sm.size());
    puts("Using Auto:");
    for(auto it = sm.begin(); it!=sm.end(); it++)
        debug(it->first, it->second);       ///Like pointer of pair.

    puts("Using Iterator:");
    for(map<string,double>::iterator it = sm.begin(); it!=sm.end(); it++)
    {
        debug(it->first, it->second);       ///Like pointer of pair.
    }


    return 0;
}
