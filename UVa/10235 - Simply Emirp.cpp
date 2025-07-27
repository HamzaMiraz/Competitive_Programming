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
bool isprime [10010000];
int prime [810000];

void sieve ()
{
    int i, j, r, c = 1;

    for ( i = 3; i <= 1000000; i += 2 )
        isprime[i] = true ;
    isprime [2] = true ;

    prime [c++] = 2 ;

    for ( i = 3; i <=1000000; i += 2 )
        if ( isprime[i] == true )//if ( isprime[i] )
        {
            prime[c++] = i ;

            if ( 1000000/i >= i )
            {
                r = i * 2 ;
                for ( j = i * i; j <=1000000; j += r )
                    isprime[j] = false ;
            }
        }
}
int rev(int n)
{
    int reversed = 0;
    while(n>0)
    {
        reversed *= 10;
        reversed += n%10;
        n /= 10;
    }
    return reversed ;
}

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

   sieve();
	int N;
	while( cin >> N ){
		if(isprime[N] == false )
			cout << N << " is not prime." << endl;
		else{
			int R = rev(N);
			if( isprime[R] == true && N != R )
				cout << N << " is emirp." << endl;
			else
				cout << N << " is prime." << endl;
		}
	}
	return 0;
}
