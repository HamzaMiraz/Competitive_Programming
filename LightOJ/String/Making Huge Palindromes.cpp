#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#endif
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define vii vector<pair<int,int>>
#define vll vector<pair<ll,ll>>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pql priority_queue<ll>
#define LCM(a,b)  (a*b)/__gcd(a,b)
#define ss " "
#define nn "\n"
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;
const int sz=2e5+10;
const ll mod=1e9+7;
 ll cil(ll x,ll y){
    if(x%y)return x/y +1;
    return x/y;
}
int cnt,ks;
vector<int>make_lps(string &s){
    vector<int>lps(s.size()+1,0);/// prefix array
    for(int i=1;i<s.size();i++){
        int j=lps[i-1];

        while(j>0 && s[i]!=s[j])
            j=lps[j-1];
        
        if(s[i]==s[j])lps[i]=++j;
    }
    return lps;
}
int kmp(string &txt,string &pat,vector<int>&lps){
    int t(0),p(0);
    while(t<txt.size()){
        if(txt[t]==pat[p])++t,++p;
        else{
            if(p!=0)p=lps[p-1];
            else{
                ++t;
            }
        }
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string pat,txt;
    int t;cin>>t;
    while(t--){
        cin>>txt;
        pat=txt;
        reverse(pat.begin(),pat.end());
        vector<int>lps=make_lps(pat);
        cnt=0;
        int p=kmp(txt,pat,lps);
        cout<<"Case "<<++ks<<": "<<2*txt.size()-p<<nn;

    }
    return 0;
