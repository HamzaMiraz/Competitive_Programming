#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <set>
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
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    ///muliset can contain multi duplikate values
    multiset<int>s;
    s.insert(10);
    s.insert(5);
    s.insert(5);
    s.insert(57);
    s.insert(1);
    s.insert(10);
    s.insert(10);

    for(auto SET : s){
        cout<<SET<<" ";
    }
    cout<<"\n"<<endl;

    multiset<string>str;

    str.insert("sami");
    str.insert("hamza");
    str.insert("hamza");
    str.insert("xaowad");
    str.insert("lia");
    str.insert("shibly");

    for(auto SET : str){
        cout<<SET<<" ";
    }
    cout<<"\n"<<endl;

    /// find set

    cout<<"erase hamza:"<<endl;

    str.erase(str.find("hamza"));

    for(auto SET : str){
        cout<<SET<<" ";
    }
    cout<<"\n"<<endl;

    return 0;
}
