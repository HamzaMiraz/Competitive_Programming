#include<bits/stdc++.h>
using namespace std;

vector<int> v1,v2;
vector<int> ans;
int n,m;
int memo[100][100];
int lcs(int t,int p){
    if(t==n || p==m){
        return 0;
    }
    if(memo[t][p]!=-1)return memo[t][p];

    if(v1[t]==v2[p]){
        memo[t][p]=1+lcs(t+1,p+1);
    }
    else{
        memo[t][p]=max(lcs(t+1,p),lcs(t,p+1));
    }
    return memo[t][p];
}
void path(int t,int p){
    if(t==n || p==m)return;
    if(v1[t]==v2[p]){
        cout<<v1[t]<<" ";
        path(t+1,p+1);
    }
    else if(memo[t+1][p]>memo[t][p+1]){
        path(t+1,p);
    }
    else {
        path(t,p+1);
    }
}
int main()
{   
    while(cin>>n){
        for(int i=0;i<n;i++){
            int x; cin>>x;
            v1.push_back(x);
            v2.push_back(x);
        }
        sort(v2.begin(),v2.end());
        for(int i=v2.size()-1;i>=1;i--){
            if(v2[i]==v2[i-1]){
                v2.erase(v2.begin()+i);

            }
        }
        m=v2.size();
        memset(memo,-1,sizeof memo);
        cout<<"LIS size = "<<lcs(0,0)<<endl;
        cout<<"LIS = ";path(0,0);
        cout<<"\n";
        v1.clear();v2.clear();
    }
    return 0;
}
/**
8
10 9 2 5 3 7 101 18
7
7 7 7 7 7 7 7
6
0 1 0 3 2 3

**/
