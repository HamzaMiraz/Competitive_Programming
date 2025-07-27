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

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.


    int t ;cin>>t;
    int ks=0;
    while(t--)
    {
        string ch;
        cin>>ch;
        LL n;cin>>n;
        LL i,j,len,sum,m;

         len = ch.size();
        sum=0;
        m=0;
        if(ch[0]=='-')i=1;
        else i=0;
        for(;i<len; i++)
        {
            sum = m*10 + ch[i]-48;
            m = sum%n;
        }
        if(m==0)
        {
            printf("Case %d: divisible\n",++ks);
        }
        else
        {
            printf("Case %d: not divisible\n",++ks);
        }
    }
    return 0;
}
