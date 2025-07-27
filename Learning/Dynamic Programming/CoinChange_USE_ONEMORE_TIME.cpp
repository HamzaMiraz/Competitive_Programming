#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20
#define MAX_W 10000

#define INF 99999999
#define EMPTY_VALUE -1

int C[MAX_N];
int memo[MAX_W];
int NC,n;

int way(int W) {
    if (W < 0) return INF;
    if (W == 0) return 0;

    int &rf=memo[W];
    if (rf != EMPTY_VALUE) {
        return rf;
    }

    rf = INF;
    for (int i = 0;i < NC;i++) {
        rf = min(rf, 1 + way(W - C[i]));
    }
    return rf;
}
int main()
{
//    freopen("dp1.in","r",stdin);
//    freopen("out.txt","w",stdout);

    while(cin>>n>>NC)///NC = number of coin , n = reach Destination
    {
        memset(memo, -1, sizeof memo);

        for(int i=0;i<NC;i++)
        {
            cin>>C[i];
        }
        cout<<way(n)<<endl;
    }

    return 0;
}


