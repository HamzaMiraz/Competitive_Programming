class Solution {
public:
int n;
vector<vector<int>>dp;
vector<int>c;
    int go(int i,int j){
        if(i>j)return 0;
    
        int &rf=dp[i][j];
        if(rf!=-1)return rf;
        rf=99999999;
        for(int cut=i;cut<=j;cut++){
            rf=min(rf,c[j+1]-c[i-1]+go(i,cut-1)+go(cut+1,j));
        }
        return rf;
    }

    int minCost(int len, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(len);
        sort(cuts.begin(),cuts.end());
        n=cuts.size();
        c=cuts;
        dp=vector<vector<int>>(n+2,vector<int>(n+2,-1));
        return go(1,n-2);
    }
};
///