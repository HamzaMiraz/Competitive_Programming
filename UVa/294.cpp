#include <bits/stdc++.h>
using namespace std;

// function to print the divisors
int Divisors(long long n)
{
    vector<long long>vec;
    vec.clear();
	// Vector to store half of the divisors
	for (long long i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {

			// check if divisors are equal
			if (n / i == i)
				vec.push_back(i);
			else {
				vec.push_back(i);

				// push the second divisor in the set
				vec.push_back(n/i);
			}
		}
	}
    return vec.size();
}

int main()
{
    int t;cin>>t;
    long long L,H;
    while(t--){
        cin>>L>>H;
        long long mx=0,pos;
        for(long long i=L;i<=H;i++){
            if(mx<Divisors(i)){
                mx=Divisors(i);
                pos=i;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",L,H,pos,mx);
    }
	return 0;
}
