#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int>&a){
    vector<int>v;
    int ans=0;
    for(auto x : a){
        auto it =lower_bound(v.begin(),v.end(),x);
        ans=max(ans,(int)(it-v.begin()+1));
        if(it==v.end()){
            v.push_back(x);
        }else{
            *it=x;
        }
    }
    return ans;
}

int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin>>n)
    {
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        cout<<LIS(v)<<"\n";
    }
    return 0;
}