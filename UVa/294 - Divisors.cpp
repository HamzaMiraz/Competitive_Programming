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

#define SIZE_N 32000
#define SIZE_P 1000

bool isprime [SIZE_N];
int prime [SIZE_P];

void sieve ()
{
    int i, j, r, c = 1;

    for ( i = 3; i <= SIZE_N; i += 2 )
        isprime[i] = true ;
    isprime [2] = true ;

    prime [c++] = 2 ;

    for ( i = 3; i <= SIZE_N; i += 2 )
        if ( isprime[i] == true )//if ( isprime[i] )
        {
            prime[c++] = i ;

            if ( SIZE_N/i >= i )
            {
                r = i * 2 ;
                for ( j = i * i; j <= SIZE_N; j += r )
                    isprime[j] = false ;
            }
        }
}
int main() {
    sieve();

    int T;
    scanf("%d", &T);
    while (T--)
    {
        int L, U;
        scanf("%d%d", &L, &U);
        int Div = 1, Num = L;
        for (int i = L; i <= U; i++)
        {
            int N = i, D = 1;
            for (int j = 1; prime[j] <= (N/prime[j]); j++)
            {
                if (N % prime[j] == 0)
                {
                    int C = 0;
                    while (N % prime[j] == 0)
                    {
                        ++C;
                        N /= prime[j];
                    }
                    D *= (C + 1);
                }
            }
            if(N!=1)D*=2;
            if (D > Div)
            {
                Div = D;
                Num = i;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, Num, Div);
    }
    return 0;
}

