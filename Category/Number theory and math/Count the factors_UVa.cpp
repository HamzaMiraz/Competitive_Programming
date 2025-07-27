
#include "bits/stdc++.h"
using namespace std;

#define MAXN 1000010
int spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;

    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
int unique_paimes_nums(int x)
{
    int cnt=0;
    while (x !=1) {
        int div=spf[x];
        cnt++;
        while(x%div==0){
            x = x / div;
        }
    }
    return cnt;
}

// driver program for above function
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    int x ;
    while(cin>>x){
        if(x==0)break;
        cout<<x<<" : "<< unique_paimes_nums(x)<<"\n";
    }

    return 0;
}
