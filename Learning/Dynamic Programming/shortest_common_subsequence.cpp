class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int l1=s1.size(),l2=s2.size();
        vector<vector<int>>dp(l1+3,vector<int>(l2+3,0));
        for(int i=l1-1;i>=0;i--){
            for(int j=l2-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
				string ans="";
				int i=0;
				int j=0;
				while(i<l1 && j<l2){
					if(s1[i]==s2[j]){
						ans+=s1[i];
						i++,j++;
					}else if(dp[i+1][j]>dp[i][j+1]){
						ans+=s1[i];
						i++;
					}else{
						ans+=s2[j];
						j++;
					}
				}
				while(i<l1){
					ans+=s1[i];
					i++;
				}
				while(j<l2){
					ans+=s2[j];
					j++;
				}
				return ans;
    }
};