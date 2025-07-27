#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
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
    pair<string,int>p1("showeb",10);
    cout<<p1.first<<" "<<p1.second<<endl;

    pair<int,string>p2;
    p2=make_pair(27,"abdullah");
    cout<<p2.first<<" "<<p2.second<<endl;

    ///vectore pair

    vector<pair<int,string>>vec;
    vector<pair<int,string>>::iterator it;

    vec.push_back(make_pair(123,"sami"));
    vec.push_back(make_pair(45,"naim"));
    vec.push_back(make_pair(54,"lia"));
    vec.push_back(make_pair(47,"maria"));

    cout<<vec[0].second<<endl;

    cout<<"\n\niterator:"<<endl;
    for(it=vec.begin();it!=vec.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<"\n\nauto:"<<endl;
    for(auto s:vec){
        cout<<s.first<<" "<<s.second<<endl;
    }

    return 0;
}

