#include<bits/stdc++.h>
using namespace std;


int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    ios_base::sync_with_stdio(0); cin.tie(0);

        int n,b;
        cin>>n>>b;
        double ans;

        ans=(log2(n)/log2(b));//convert 2 base to b base

        cout<<ans<<"\n";
    
    
   return 0;
}
///invisible = ?
