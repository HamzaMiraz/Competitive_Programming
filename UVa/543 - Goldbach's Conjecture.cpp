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

#define SIZE_N 1000000
#define SIZE_P 810000

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

    int n;

    while(scanf("%d",&n) && n){

        for(int a = 3; a < n; a+=2){

            if( isprime[a] == true){

                int b = n - a;

                if( isprime[b] == true ){
                    printf("%d = %d + %d\n", n, a, b);
                    break;
                }

            }
        }

    }


    return 0;
}
