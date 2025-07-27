#include<bits/stdc++.h>
using namespace std;

vector<int>ar;
vector<vector<int>>dp;
int n;
int go(int i,int j){
    if(j== n)return 0;
    int &rf=dp[i+1][j];
    if(rf!=-1)return rf;
    rf=go(i,j+1);
    if((i==-1|| ar[j]%ar[i]==0 )){
        rf=max(rf,1+go(j,j+1));
    }
    return rf;
}
vector<int>vec;
 void path(int i,int j){
    if(j== n)return;
    if(dp[i+1][j+1]>1+dp[j+1][j+1]){
        path(i,j+1);
    }else{
        if(i==-1 || ar[j]%ar[i]==0){
            vec.push_back(ar[j]);
            path(j,j+1);
        }else{
            path(i,j+1);
        }
    }
}

int largestDivisibleSubset(vector<int>&nums){
    ar=nums;
    n=ar.size();
    sort(ar.begin(),ar.end());
    dp=vector<vector<int>>(n+2,vector<int>(n+2,-1));
    return go(-1,0);
}

int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
//    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int>v={8,1,2,7,4,17};
    cout<<largestDivisibleSubset(v)<<endl;
    path(-1,0);
    for(auto it :vec){
        cout<<it<<" "; 
    }
    vec.clear();
    return 0;
}
///invisible =  
