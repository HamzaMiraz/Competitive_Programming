#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
using namespace std;

#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

//For Debugging
#define debug(a...)          {cout<<__LINE__<<"#--> ";dbg,a; cout<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;

typedef long long LL;
const int Size = 100;
const double EPS = 1e-7; ///1*10^-7

bool flag[100000];
int prime[1000];
int ara[10001];
int L,U,N;

void sieve(int N)
{
    int c=1;
    flag[2]=true;
    for(int i=3;i<=N;i+=2)
        flag[i]=true;

    prime[c++]=2;
    for(int i=3;i<=N;i+=2)
        if(flag[i])
        {
            prime[c++]=i;
            if(N/i>=i)
            {
                int r=i*2;
                for(int j=i*i;j<N;j+=r)
                    flag[j]=false;
            }
        }
}

int Divisors(int n)
{
    int d=1,c;
    for(int j=1;prime[j]<=(n/prime[j]);j++)
    {
        c=0;
        while(n%prime[j]==0)
        {
            c++;
            n=n/prime[j];
        }
        d*=c+1;
    }
    if(n!=1)
        d*=2;

    return d;
}
int main()
{
//    freopen("in.txt","r",stdin);
//   freopen("out.txt","w",stdout);

    int tks,ind,dmax;
    sieve(32000);
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&L,&U);
        ind=0,dmax=0;
        for(int i=L;i<=U;i++)
        {
//            deb(i);
           int d=Divisors(i);
//           deb(d);
           if(d>dmax)
           {
               dmax=d;
               ind=i;
           }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,ind,dmax);
    }
    return 0;
}
