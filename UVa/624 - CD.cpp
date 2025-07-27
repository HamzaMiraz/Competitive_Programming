#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
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

int tc[21];
bool col[21],cl[21];

LL N,ans,tmp,trk;

void bt(int d)
{
    if(d==trk)
    {
         tmp=0;
        for(int i=0;i<trk;i++)
        {
            if(col[i]) tmp +=tc[i];
        }
        if(tmp<=N)
        {
            if(ans<tmp)
            {
                ans = tmp;
                for(int i=0;i<trk;i++)
                {
                    cl[i]=col[i];
                }
            }
        }
        return;
    }
    col[d] = true;
    bt(d+1);
    col[d] = false;
    bt(d+1);
}
int main()
{
//    freopen("lottlo.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    while(cin>>N){
        scanf("%d",&trk);
        for(int i=0;i<trk;i++)
        {
            scanf("%d",&tc[i]);
        }
        ans=0;
        memset(cl, false, sizeof cl);
        bt(0);

        for(int i=0;i<trk;i++)
        {
            if(cl[i])printf("%d ",tc[i]);
        }
        cout <<"sum:" <<ans << endl;
    }
	return 0;
}
