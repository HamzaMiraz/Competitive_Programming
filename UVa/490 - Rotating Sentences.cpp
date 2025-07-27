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
//    freopen("490.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    char st1[105],st2[105];
    while(scanf("%[^\n] %[^\n]",st1,st2)==2){

        int len1=strlen(st1);
        int len2=strlen(st2);
        int len=max(len1,len2);
        for(int i=0;i<len;i++){
            if(i<len2)
                printf("%c",st2[i]);
            if(i<len1)
                printf("%c",st1[i]);
            cout<<endl;
        }
    }

    return 0;
}

