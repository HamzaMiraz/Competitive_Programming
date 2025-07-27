#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
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

bool isBy11Integer(int v){
    return v%11 ==0;
}

bool isBy11Integer(char s[]){

    bool isDivisiable = false;

    //code

    return isDivisiable;
}

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    char c;
//    while(true)
    {
        c = getchar();  ///scanf("%c",&c);



        printf("%c %d\n", c, c);

        int d = c - '0';

        deb(d);
    }
    return 0;
}
