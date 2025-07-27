#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <list>
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

    int ar[5]={2,-1,6,10,3};

    list<int>myList;

    ///list<int>myList(ar,ar+5); /// array insarting on list

    ///list<int>myList(4,-9);///you can try with this to

    list<int>::iterator it;

    myList.push_back(10);
    myList.push_back(9);
    myList.push_front(5);
    myList.push_back(7);
    myList.push_front(100);

//    for(it=myList.begin();it!=myList.end();it++){
//        cout<<*it<<" ";
//    }
//    cout<<endl;
    for(auto i : myList){///you can use auto or itarator any thing becouse both are same
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"reverse:"<<endl;
    myList.reverse();
    for(auto i : myList){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"myList.begin()"<<endl;
    it=myList.begin();

    cout<<*it<<endl;
    it++;
    cout<<*it<<endl;
    it++;
    cout<<*it<<endl;

    myList.clear();

    return 0;
}
