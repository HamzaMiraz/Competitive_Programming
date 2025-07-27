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

void fun(string a)
{
    a = "maksud";
}

void funRef(string& a)
{
    a = "maksud";
}

string concatenation(string a, string b)
{
    return a+"+"+b;
}

int main()
{
    string a = "abc";
    fun(a);
    deb(a);
    funRef(a);
    deb(a);

    string s = concatenation("maksud", "Hossain");
    deb(s);

    return 0;
}
