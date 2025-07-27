#include<bits/stdc++.h>
using namespace std;

typedef long long ll;/// 1e18;
ll dp1[3005][3005];
bool vis1[3005][3005];
ll dp2[3005][3005];
bool vis2[3005][3005];
ll  ar[3005];
ll first_player_optimal(int i,int j);///function prototype
ll second_player_optimal(int i,int j){
    
    if(i>j)return 0;
    
    if(vis2[i][j])return dp2[i][j];
    vis2[i][j]=true;
    
    ll left = first_player_optimal(i+1 , j) - ar[i];
    ll right = first_player_optimal(i , j-1) - ar[j];
    return dp2[i][j] = min(left,right);
}

ll first_player_optimal(int i,int j){
    
    if(i>j)return 0;
    
    if(vis1[i][j])return dp1[i][j];
    vis1[i][j]=true;
    
    ll left = second_player_optimal(i+1 , j) + ar[i];
    ll right = second_player_optimal(i , j-1) + ar[j];
    return dp1[i][j] = max(left,right);
}

int main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin>>n)
    {
        //memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        cout<<first_player_optimal(0,n-1)<<"\n";
    }
    return 0;
}
///invisible =  
//https://atcoder.jp/contests/dp/tasks/dp_l?lang=en