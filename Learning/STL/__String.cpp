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

void basicIO()
{
    char in[100];

    scanf("%s",in);  ///scanf("%s",&in[0]);
    string s;
    s = in;

    cout<<"pring string using cout: "<<s<<endl;
    printf("pring string using printf: %s\n", s.c_str());

    int len = s.size();
    deb(len);

    string a = s.substr(1, 4);      //substr(Start_Index, Substring_Length);
    deb(a);

    s = "abcdefgdefx";
    deb(s);
    int ind = (int)s.find("def");    ///Return index of first occurrence; else return -1
    deb(ind);

    string x = "pqr";
    ind = (int)s.find(x);
    deb(ind);

    s = "01";
    s = s+'2';
    s +='3';
    s += "45";
    deb(s);

    strcpy(in, s.c_str());  /// copy to null terminated string.
    deb(in);

    string p = "abc";
    string q = "def";

    if(p<q) ///Comparing based dictionary order.
        puts("p<q");
    else
        puts("Not p<q");
}

void Advance()
{
    puts("-------------ADVANCE----------------");
    string s = "defzxcabcZXC";
    debug("Initially => ", s);
    sort(s.begin(), s.end());
    debug("After sorting => ", s);

    sort(s.rbegin(), s.rend());
    debug("After sorting (DESC)=> ", s);

    reverse(s.begin(), s.end());
    debug("After reversing => ", s);
}


int main()
{
    freopen("__String.in", "r", stdin);  ///To read from a file.
    basicIO();
    Advance();
    return 0;
}
