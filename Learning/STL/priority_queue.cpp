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


    priority_queue<int>pq;///priority queue is just like queue ,but it will make all value descending order

    ///priority_queue<int ,vector<int>,greater<int>>pq;///acending order

    pq.push(20);
    pq.push(120);
    pq.push(24);
    pq.push(42);
    pq.push(111);
    pq.push(34);
    pq.push(45);

    while(!pq.empty()){

        cout<<pq.top()<<endl;

        pq.pop();
    }
    cout<<"\n"<<endl;

    ///for string value at will make values lexico graphical order

    priority_queue<string>sk;

    sk.push("hamza");
    sk.push("hamza");
    sk.push("sami");
    sk.push("xaowad");
    sk.push("naim");
    sk.push("shibly");

    while(!sk.empty()){

        cout<<sk.top()<<endl;

        sk.pop();
    }
    return 0;
}
