
vector<vector<int>>dp;
int n;
vector<int>ar;
int longestBitonicSubsequence(vector<int>& arr, int N)
{
	n=N;
	ar=arr;
	reverse(arr.begin(),arr.end());
	vector<int>dp(n+2,1);
	int mx=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(ar[j]<ar[i]){
				dp[i]=max(dp[i],1+dp[j]);
			}
		}
	}
	vector<int>memo(n+2,1);
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(ar[j]<ar[i]){
				memo[i]=max(memo[i],1+memo[j]);
			}
		}
		mx=max(mx,dp[i]+memo[i]);
	}
	return mx-1;

}
