#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
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

template<class TT>
void printVector(vector<TT>&v, string s="")
{
    cout<<s<<" # Size: "<<v.size()<<" => {";

    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<"}"<<endl;
}


bool com(string a, string b)
{
    if(a.size()!= b.size()) return a.size()<b.size();
    return a<b;
}

int main()
{
    vector<string>v = {"abc", "def", "ac", "abc", "123", "ab", "99"};
    vector<int>iv = {3, 5, 9};
    printVector(iv, "iv");

    printVector(v, "v");

    v[1][1] = 'x';
    printVector(v, "v");

    sort(v.begin(), v.end());       /// O(N log N)
    printVector(v, "Sorted (Aesc)");

    sort(v.rbegin(), v.rend());
    printVector(v, "Sorted (Desc)");

    sort(v.begin(), v.end(), com);

    printVector(v, "Sorted using Comp");

    return 0;
}
