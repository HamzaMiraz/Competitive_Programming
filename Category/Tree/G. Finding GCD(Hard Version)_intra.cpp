#include<bits/stdc++.h>
using namespace std;

const int Size=2e6+7;
int ar[Size];
int tree[4*Size];
vector<int> g[Size];
int st[Size];
int ft[2*Size];
int en[Size];
int t;
const int N = 1e6 + 3;
vector<int>divisor[N];

void sieve()
{
    for (int i = 1; i <=N; i++) {
        for (int j = i; j <= N; j += i) {
            divisor[j].push_back(i);
        }
    }
}
void dfs(int node=1,int par=-1){
    st[node]=++t;
    ft[t]=ar[node];
    for(auto v : g[node]){
        if(v==par)continue;
            dfs(v,node);

    }
    en[node]=++t;
    ft[t]=ar[node];

}
void build(int node,int left,int right){
    if(left==right){
        tree[node]=ft[left];
        return ;
    }
    int mid=(left+right)/2;
    build(node*2,left,mid);
    build(node*2+1,mid+1,right);
    tree[node]=__gcd(tree[node*2],tree[node*2+1]);
}
int query(int node,int left,int right,int ql,int qr){///query left=ql,right=qr
    if(left>=ql && right<=qr){
        return tree[node];
    }
    int mid=(left+right)/2;
    if(qr<=mid){
        return query(2*node,left,mid,ql,qr);
    }
    else if(mid<ql){
        return query(2*node+1,mid+1,right,ql,qr);
    }
    else{
        int left_node=query(2*node,left,mid,ql,mid);
        int right_node=query(2*node+1,mid+1,right,mid+1,qr);
        return __gcd(left_node,right_node);
    }

}
void update(int node,int left,int right,int pos)
{
    if(left==pos && right==pos){
        tree[node]= ft[pos];
        return;
    }
    int mid = (left+right)/2;
    if(pos<=mid && pos>=left)
        update(node*2,left,mid,pos);
    else
        update(node*2+1,mid+1,right,pos);

    tree[node] = __gcd(tree[node*2],tree[(node*2)+1]);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    int n,ql,qr,pos,new_val,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>ar[i];
        }
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        t=0;
        dfs();
        build(1,1,t);
        while(q--){
            int k;
            cin>>k;
            if(k==1){
                cin>>pos>>new_val;
                ft[st[pos]]=new_val;
                update(1,1,t,st[pos]);
                ft[en[pos]]=new_val;
                update(1,1,t,en[pos]);
                continue;
            }
            int nod;cin>>nod;
            int SUB_GCD=query(1,1,t,st[nod],en[nod]);
            for(auto div : divisor[SUB_GCD]){
                cout<<div<<" ";
            }
            cout<<"\n";

        }

    return 0;
}
//https://codeforces.com/gym/428052/problem/G