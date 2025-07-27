class Solution {
public:
    vector<vector<int>>dp;
    string st;
    int go(int i,int j){
        if(i>j)return 0;
        int &rf=dp[i][j];
        if(rf!=-1)return rf;
        if(st[i]==st[j]&& i!=j){
            rf=go(i+1,j-1)+2;
        }else if(st[i]==st[j]){
            rf=go(i+1,j-1)+1;
        }
        else{
            rf=max(go(i+1,j),go(i,j-1));
        }
        return rf;
    }
    int minInsertions(string &s1) {
        st=s1;
        int n=s1.size();
        dp=vector<vector<int>>(n+2,vector<int>(n+1,-1));
        int res=go(0,n-1);
        return n-res;
    }
};