#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int Size=2e5 +10;
ll ar[Size];
ll tree[4*Size];
void build(int node,int left,int right){
    if(left==right){
        tree[node]=ar[left];
        return ;
    }
    int mid=(left+right)/2;
    build(node*2,left,mid);
    build(node*2+1,mid+1,right);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}
int query(int node,int left,int right,int ql,int qr,ll x){///query left=ql,right=qr
    if(left==right){
        if(tree[node]>=x){
            return left;
        }else{
            return 0;
        }
        
    }
    int mid=(left+right)/2;
    if(tree[node*2]>=x){
        return query(2*node,left,mid,ql,qr,x);
    }
    else{
        return query(2*node+1,mid+1,right,ql,qr,x);
    }
 
}
void update(int node,int left,int right,int pos)
{
    if(left==pos && right==pos){
        tree[node]= ar[pos];
        return;
    }
    int mid = (left+right)/2;
    if(pos<=mid && pos>=left)
        update(node*2,left,mid,pos);
    else
        update(node*2+1,mid+1,right,pos);
    tree[node] = max(tree[node*2],tree[(node*2)+1]);
}
 
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ql,qr,pos,new_val,q;
    while(cin>>n>>q){
        for(int i=1;i<=n;i++){
            cin>>ar[i];
        }
        build(1,1,n);
        while(q--){
            ll x;
            cin>>x;
            int idx=query(1,1,n,1,n,x);
            if(idx){
                cout<<idx<<" ";
                ar[idx]-=x;
                update(1,1,n,idx);
            }else{
                cout<<"0 ";
            }
 
        }
        cout<<"\n";
    }
    return 0;
}