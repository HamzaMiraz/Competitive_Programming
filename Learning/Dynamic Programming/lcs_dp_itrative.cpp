#include<bits/stdc++.h>

using namespace std;

 vector<vector<int>>dp;
 string s1,s2;

int main()
{
    while(cin>>s1>>s2){
        int l1=s1.size(),l2=s2.size();
        dp=vector<vector<int>>(l1+3,vector<int>(l2+3,0));
        for(int i=l1-1;i>=0;i--){
            for(int j=l2-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        cout<<"LCS = "<<dp[0][0]<<"\n";
    }
    return 0;
}

