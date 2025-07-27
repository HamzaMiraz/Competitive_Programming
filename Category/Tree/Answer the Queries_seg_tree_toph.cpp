#include<bits/stdc++.h>

using namespace std;

#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define GCD(a,b)  __gcd(a,b)
#define LCM(a,b)  (a*b)/__gcd(a,b)
#define sqr(a)    ((a)*(a))
typedef long long LL;
const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 2e9+10;

const int Size=100005;
int ar[Size];
pair<int,int> tree[4*Size];
void build(int node,int left,int right){
    if(left==right){
        tree[node]={ar[left],1};
        return;
    }

    int mid=(left+right)/2;
    build(node*2,left,mid);
    build(node*2+1,mid+1,right);
    auto left_node=tree[node*2];
    auto right_node=tree[node*2 +1];
    
    if(left_node.first==right_node.first){
        tree[node]={left_node.first,left_node.second+right_node.second};
    }else if(left_node.first>right_node.first){
        tree[node]={left_node.first,left_node.second};
    }else{
        tree[node]={right_node.first,right_node.second};
    }

}
pair<int,int> query(int node,int left,int right,int ql,int qr){///query left=ql,right=qr
    if(left>=ql && right<=qr){
        return {tree[node].first,tree[node].second};
    }
    int mid=(left+right)/2;
    if(qr<=mid){
        return query(2*node,left,mid,ql,qr);
    }
    else if(mid<ql){
        return query(2*node+1,mid+1,right,ql,qr);
    }
    else{
        auto left_node=query(2*node,left,mid,ql,mid);
        auto right_node=query(2*node+1,mid+1,right,mid+1,qr);
        if(left_node.first==right_node.first){
            return {left_node.first,left_node.second+right_node.second};
        }else if (left_node.first>right_node.first){
            return {left_node.first,left_node.second};
        }else{
            return {right_node.first,right_node.second};
        }
    }

}
int ks;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ql,qr,pos,new_val,q;
    int t;cin>>t;
    while(t--){
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>ar[i];
        }
        build(1,1,n);
        cout<<"Case "<<++ks<<":\n";
        while(q--){
            cin>>ql>>qr;
            ql++,qr++;
            cout<<query(1,1,n,ql,qr).second<<"\n";
        }
    }
    return 0;
}
/*

1
5 3
1001 3 5 5 99
1 2
2 3
0 4

*/