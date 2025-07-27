class Solution {
public:
int n;
vector<vector<int>>dp;
vector<int>ar;
int go(int i,int j){
    if(i>j)return 0;
    int &rf=dp[i][j];
    if(rf!=-1)return rf;
    rf=-9999999;
    for(int idx=i;idx<=j;idx++){
        rf=max(rf,ar[i-1]*ar[idx]*ar[j+1]+go(i,idx-1)+go(idx+1,j));
    }
    return rf;
}
    int maxCoins(vector<int>& nums) {
        ar=nums;
        ar.insert(ar.begin(),1);
        ar.push_back(1);
        n=ar.size();
        dp=vector<vector<int>>(n+2,vector<int>(n+2,-1));
        
        return go(1,n-2);
    }
};