#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll  sz=1e18;

void ugly ()
{
    vector<ll>ugly_num;
    
    for(ll p2=1;p2<sz;p2*=2){
        
        for(ll p3=1;p2*p3<sz;p3*=3){
            
            for(ll p5=1;p2*p3*p5<sz;p5*=5){
                ugly_num.push_back(p2*p3*p5);
            }
        }
    }
    sort(ugly_num.begin(), ugly_num.end());
    cout<<"The 1500'th ugly number is "<<ugly_num[1499]<<".\n";
}
int main()
{
    ugly();
    return 0;
}




