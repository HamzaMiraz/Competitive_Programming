#include <bits/stdc++.h>
using namespace std;

using ll=long long;
/// nlog(n)
#define SIZE_N 1000010///finding all prime number under SIZE_N
bool isprime [SIZE_N];
vector<int>prime;

void sieve()
{
    int i, j, r, c = 1;
    for ( i = 3; i <= SIZE_N; i += 2 )
        isprime[i] = true ;
    isprime [2] = true ;

    prime.push_back(2);

    for ( i = 3; i <= SIZE_N; i += 2 )
        if ( isprime[i] == true )
        {
            prime.push_back(i);

            if ( SIZE_N/i >= i )
            {
                r = i * 2 ;
                for ( j = i * i; j <= SIZE_N; j += r )
                    isprime[j] = false ;///unprime all nums which is divisible by i
            }
        }
}
int ks;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    int t;cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll number_of_divs=1;
        for(ll i=0;i<prime.size();i++){
            if(prime[i]*prime[i]>n)break;
            if(n%prime[i]==0){
                ll pow=0;
                while(n%prime[i]==0){
                    pow++;
                    n/=prime[i];
                    //cout<<"pow->"<<pow<<"\n";
                }
                number_of_divs*=(pow+1);
            }
        }
        if(n>1){
            int pow=1;
            number_of_divs*=(pow+1);
        }
        cout<<"Case "<<++ks<<": "<<number_of_divs-1<<"\n";
    }

    return 0;
}




