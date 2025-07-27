#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
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
    /// map contain unique keys,and make values lexxico graphical order
    map<string,int>m;
    map<string,int>::iterator it;

    m.insert(make_pair("hamza",20));
    m.insert(make_pair("hamza",17));
    m.insert(make_pair("hamza",56));
    m.insert(make_pair("Hamza",76));
    m.insert(make_pair("jisan",21));
    m.insert(make_pair("emon",34));
    m.insert(make_pair("arafat",42));
    m.insert(make_pair("Robin",50));
    cout<<"using auto:\n"<<endl;
    for(auto s : m){

        cout<<s.first<<" "<<s.second<<endl;
    }

    cout<<"\n\nusing iterator:\n"<<endl;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<"\n"<<endl;
    ///find
    if(m.find("Robin")!=m.end()){///m.count("Robin")
        cout<<"Found\n"<<endl;
    }
    else
        cout<<"Not Found\n"<<endl;

    m.erase(m.begin(),m.find("emon"));///erase before key of emon
    for(auto s : m){
        cout<<s.first<<" "<<s.second<<endl;
    }
    cout<<"\n"<<endl;

    //m.erase(m.find("emon"));///erase  emon
    m.erase("emon");
    for(auto s : m){
        cout<<s.first<<" "<<s.second<<endl;
    }
    return 0;
}
