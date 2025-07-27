#include <bits/stdc++.h>
using namespace std;

using ll= long long;
/// nlog(n)
#define SIZE_N 1000010///finding all prime number under SIZE_N
#define SIZE_P 1000010
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
        if ( isprime[i] == true )
        {
            prime[c++] = i ;

            if ( SIZE_N/i >= i )
            {
                r = i * 2 ;
                for ( j = i * i; j <= SIZE_N; j += r )
                    isprime[j] = false ;///unprime all nums which is divisible by i
            }
        }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    int t;cin>>t;
    while(t--){
        ll n;
        cin>>n;
        double nn =n;
        double xx=sqrtl(nn);
        ll x=sqrtl(n);
        if(xx-x>0)x++;
        //cout<<x<<"\n";
        if(isprime[x] && x*x ==n){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }


    return 0;
}




