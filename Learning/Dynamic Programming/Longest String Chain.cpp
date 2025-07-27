class Solution {
public:
    vector<vector<int>>dp;
    int n;
    vector<string>st;
    static bool comp(string &a,string &b){
        return a.size()<b.size();
    }
    bool ck(string& s1,string& s2){
        int l1=s1.size();
        int l2=s2.size();
        if(l1+1 != l2)return false;
        int i=0;
        int j=0;
        while(j<l2){
            if(s1[i]==s2[j]){
                i++,j++;
            }else{
                j++;
            }
        }
        if(j-i==1)return true;
        return false;
    }
    // int go(int i,int j){
    //     if(i==n|| j==n)return 0;
    //     int rf=dp[i+1][j];
    //     if(rf!=-1)return rf;
    //     rf=go(i,j+1);
    //     if(i==-1 || ck(st[i],st[j])){
    //         rf=max(rf,1+go(j,j+1));
    //     }
    //     return rf;
    // }
    int longestStrChain(vector<string>& words) {
        st=words;
        n=st.size();
        sort(st.begin(),st.end(),comp);
        dp=vector<vector<int>>(n+5,vector<int>(n+5,0));
        for(int i=n-1;i>=-1;i--){
            for(int j=n-1;j>=0;j--){
                dp[i+1][j]=dp[i+1][j+1];
                 if(i==-1 || ck(st[i],st[j])){
                    dp[i+1][j]=max(dp[i+1][j],1+dp[j+1][j+1]);
                }
                
            }
        }

        return dp[0][0];
    }
};