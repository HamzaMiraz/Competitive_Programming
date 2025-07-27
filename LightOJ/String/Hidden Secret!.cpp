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
#define sp(n,x)  fixed << setprecision(x) <<n
#define sqr(a)    ((a)*(a))
#define ss " "
#define nn "\n"
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;
const int sz=2e5+10;
const ll mod=1e9+7;
const double PI = acos(-1);
 ll cil(ll x,ll y){
    if(x%y)return x/y +1;
    return x/y;
}
int ks;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    cin.ignore();
    while (t--) {
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        map<char,int>mp1;
        map<char,int>mp2;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' ')continue;
            if(isupper(s1[i])){
                s1[i]=tolower(s1[i]);
            }
            mp1[s1[i]]++;
        } 
        for(int i=0;i<s2.size();i++){
            if(s2[i]==' ')continue;
            if(isupper(s2[i])){
                s2[i]=tolower(s2[i]);
            }
            mp2[s2[i]]++;
        }
        int flg=0;
        if(mp1.size()>mp2.size()){
            for(auto [f,s] :mp2){
                if(mp1[f]<s){
                    flg=1;
                    break;
                }
            }
            if(flg){
                cout<<"Case "<<++ks<<": "<<"No"<<"\n";
                continue;
            }else{
                cout<<"Case "<<++ks<<": "<<"Yes"<<"\n";
                continue;
            }
        }
        else{
            for(auto [f,s] : mp1){
                if(mp2[f]<s){
                    flg=1;
                    break;
                }
            }
            if(flg){
                cout<<"Case "<<++ks<<": "<<"No"<<"\n";
                continue;
            }else{
                cout<<"Case "<<++ks<<": "<<"Yes"<<"\n";
                continue;
            }
        }

        

    }
    return 0;
}
