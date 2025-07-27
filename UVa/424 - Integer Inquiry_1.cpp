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
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    string ar;
    long long l,carry=0,c,mx,i,br[200]={0};

    while(cin>>ar)
    {
        if(ar=="0")
            break;
        c=0;
        carry=0;
        mx=0;
        l=ar.length();
        for(i=l-1; i>=0; i--)
        {
            br[c]= ar[i]-'0'+carry+br[c];
            carry=br[c]/10;
            br[c]=br[c]%10;

            c++;
            if(mx<c)mx=c;
        }

        if(carry>0)
        {
            br[c++]+=carry%10;
            carry/=10;
            if(mx<c)mx=c;
        }

    }
        for(int i=mx-1; i>=0; i--)
            cout<<br[i];
        cout<<endl;

    return 0;
}
