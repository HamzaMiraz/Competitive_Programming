#include <bits/stdc++.h>
using namespace std;

int lcs(string &s1, string &s2)
{
    int l1=s1.size(),l2=s2.size();
    vector<vector<int>>dp(l1+3,vector<int>(l2+3,0));
    int ans=0;
    for(int i=l1-1;i>=0;i--){
        for(int j=l2-1;j>=0;j--){
            if(s1[i]==s2[j]){
                dp[i][j]=1+dp[i+1][j+1];
            }else{
                dp[i][j]=0;
            }
            ans=max(ans,dp[i][j]);
        }
    }
    return  ans;
}

int main() {
    string s1,s2;
    while(cin>>s1>>s2){
        cout<<"Longest common substring "<<lcs(s1,s2)<<"\n";
    }

    return 0;
}
// abcakbdd
// bcadd