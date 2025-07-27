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

int main()
{
//    freopen("in.in", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    char ltr[26], msg[204];
    int frq[26],t, i, j, mx,len;

    scanf("%d",&t);
    gets(msg);

    while(t--)
    {
        gets(msg);
        for(i=0; i<26; i++)
        {
            frq[i]=0;
        }
        for(i=0; i<26; i++)
        {
            ltr[i]=97+i;
        }

        len=strlen(msg);

        for(i=0; i<len; i++ )
        {
            msg[i]=tolower(msg[i]);

            for(j=0; j<26; j++)
            {
                if(msg[i]==ltr[j])frq[j]++;
            }
        }

        mx=0;

        for(i=0; i<26; i++)
        {
            if(frq[i]>mx)mx=frq[i];
        }
        for(i=0; i<26; i++)
        {
            if(frq[i]==mx)printf("%c",ltr[i]);
        }
        printf("\n");

    }
}
