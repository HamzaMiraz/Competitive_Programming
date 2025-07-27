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

    ///list<int>myList;

    list<int>myList(ar,ar+5); /// array insarting on list

    list<int>::iterator it;

    myList.push_back(10);
    myList.push_back(9);
    myList.push_front(5);


//    for(it=myList.begin();it!=myList.end();it++){
//        cout<<*it<<" ";
//    }
//    cout<<endl;


    for(auto i : myList){///you can use auto or itarator any thing becouse both are same
        cout<<i<<" ";
    }
    cout<<"\n"<<endl;


    it=find(myList.begin(),myList.end(),6);
    cout<<"itrator is point on "<<*it<<endl;
    cout<<"7 is insert before 6"<<endl;
    myList.insert(it,7);///7 is insert before 6;
        for(auto i : myList){
        cout<<i<<" ";
    }
    cout<<endl;


    cout<<"remove 5"<<endl;
    it=find(myList.begin(),myList.end(),5);
    myList.erase(it);///erase any element [it=5]
    for(auto i : myList){
        cout<<i<<" ";
    }
    cout<<endl;


    cout<<"pop front or back element"<<endl;
    myList.pop_front();
    myList.pop_back();
        for(auto i : myList){
        cout<<i<<" ";
    }
    cout<<"\n"<<endl;

    cout<<"myList is empty or filled:"<<endl;
    if(myList.empty())
        cout<<"EMPTY"<<endl;
    else
        cout<<"FILLED"<<endl;


    return 0;
}
