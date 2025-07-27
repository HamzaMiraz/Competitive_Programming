#include <bits/stdc++.h>

using namespace std;

string s;
int ispal[5010][5010];
int IsPallindrome(int l , int r) {
    if(l>r)return 1;
    if(ispal[l][r]!=-1)return ispal[l][r];
    return ispal[l][r]= s[l]==s[r] & IsPallindrome(l+1,r-1);
}
int dp[5010][5010];
int number_of_palindrome(int l,int r){
    if(l>r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    return dp[l][r]=IsPallindrome(l,r)+
        number_of_palindrome(l+1,r)+number_of_palindrome(l,r-1)-number_of_palindrome(l+1,r-1);
}
int main() {
    ///zero based
    //ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int q;
    while(cin>>s){
        cin>>q;
        memset(dp,-1,sizeof dp);
        memset(ispal,-1,sizeof ispal);
        while(q--){
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<number_of_palindrome(l,r)<<"\n";
        }
    }
    return 0;
}