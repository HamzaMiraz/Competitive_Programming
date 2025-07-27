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
/// dque just like vectore but it have extra function
    int ar[5]={2,-1,6,10,3};
    ///deque<int>dq(ar,ar+4);/// array insert on dq
    deque<int>dq;
    dq.push_back(4);
    dq.push_back(7);
    dq.push_back(7);
    dq.push_front(9);
    dq.push_front(92);

    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<" ";
    }
    cout<<endl;


    /// pop_front(),pop_back();

    cout<<"\ndq.pop_front(),dq.pop_back():"<<endl;

    dq.pop_front(),dq.pop_back();

    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<" ";
    }
    cout<<endl;

    /// front ,back function;

    cout<<"\ndq.front():"<<dq.front()<<endl;
    cout<<"dq.back():"<<dq.back()<<endl;


    ///dq insert and erase

    cout<<"\ndq.insert"<<endl;

    dq.insert(dq.begin()+2,8);///insert 8 at index 2
    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<" ";
    }
    cout<<endl;
    dq.insert(dq.begin()+3,3,5);
    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<" ";
    }
    cout<<endl;
    cout<<"\ndq.erase"<<endl;

    dq.erase(dq.begin()+1);///erase 2nd element;
    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<" ";
    }
    cout<<endl;

    dq.erase(dq.begin()+2,dq.begin()+6);///erase 3rd element to 6th element
    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<" ";
    }
    cout<<endl;

    ///dq.empty
    if(dq.empty())
        cout<<"\nEMPTY"<<endl;
    else
        cout<<"\nNOT EMPTY"<<endl;

    dq.clear();

    return 0;
}
