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
///    int ar[5]={2,-1,6,10,3};
///    set<int>s(ar,ar+5);
    set<int>s;
    s.insert(10);
    s.insert(5);
    s.insert(5);
    s.insert(57);
    s.insert(1);
    s.insert(10);

    for(auto SET : s){
        cout<<SET<<" ";///set can sort all elements and it also contain unique value
    }
    cout<<"\n"<<endl;

    set<string>str;
    set<string>::iterator it;
    str.insert("hamza");
    str.insert("hamza");
    str.insert("sami");
    str.insert("xaowad");
    str.insert("lia");
    str.insert("shibly");
    str.insert("xasir");
    str.insert("shibly");
    str.insert("abdullah");


    for(auto SET : str){
        cout<<SET<<" ";///set can sort all elements and it also contain unique value
    }
    cout<<"\n"<<endl;

    /// find set
    if(str.find("SHOWEB")!=str.end()){
        cout<<"Found"<<endl;
    }
    else cout<<"NOT FOUND\n"<<endl;

    ///find value by count
    if(str.count("hamza")){
        cout<<"FOUND"<<endl;
    }
    else cout<<"NOT FOUND\n"<<endl;

    cout<<"erase hamza:"<<endl;
//    it=str.find("hamza");
//    str.erase(it);
    str.erase(str.find("hamza"));

    for(auto SET : str){
        cout<<SET<<" ";
    }
    cout<<"\n"<<endl;

    ///pair set ,set contain  two value . one is any value other is bool

    pair<set<string>::iterator,bool>p;

    p=str.insert("shibly");
    if(p.second==false)
        cout<<"can't insert"<<endl;///becouse "shibly" is alrady inserted
    else
        cout<<"inserted"<<endl;

    p=str.insert("showeb");
    if(p.second==false)
        cout<<"can't insert"<<endl;
    else
        cout<<"inserted"<<endl;

    for(auto SET : str){
        cout<<SET<<" ";
    }
    cout<<"\n"<<endl;

    str.erase(str.begin(),str.find("shibly"));///all element erase before shibly
    for(auto SET : str)cout<<SET<<" ";cout<<"\n"<<endl;


    str.erase(str.find("showeb"),str.find("xasir"));///showeb to xasir-1 all delet
    for(auto SET : str)cout<<SET<<" ";cout<<"\n"<<endl;


    return 0;
}
