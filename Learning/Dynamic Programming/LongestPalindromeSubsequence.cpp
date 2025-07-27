#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
string st;
int go(int i,int j){
    if(i>j)return 0;
    int &rf=dp[i][j];
    if(rf!=-1)return rf;
    if(st[i]==st[j]&& i!=j){
        rf=go(i+1,j-1)+2;
    }else if(st[i]==st[j] && i==j){
        rf=go(i+1,j-1)+1;
    }
    else{
        rf=max(go(i+1,j),go(i,j-1));
    }
    return rf;
}
int longestPalindromeSubseq(string &s) {
    st=s;
    int n=s.size();
    dp=vector<vector<int>>(n+2,vector<int>(n+1,-1));
    return go(0,n-1);
}
int main() {

    string s;
    while(cin>>s){
        cout<<"longestPalindromeSubsequence = "
        <<longestPalindromeSubseq(s)<<"\n";
    }

    return 0;
}
