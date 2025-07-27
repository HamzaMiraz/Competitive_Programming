#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
///#include "debug.h"
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
#define ss ' '
#define nn '\n'
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

const int MAX = 2e6 + 10;
int a[MAX];
int FT[MAX], S[MAX], E[MAX], _time, tree[4 * MAX];
int vis[MAX];
vector<int>g[MAX];

void dfs(int ver = 1) {
    S[ver] = ++_time;
    FT[_time] = a[ver];
    vis[ver]=1;
    for (auto it : g[ver]) {
        if (!vis[it]) {
            dfs(it);
        }
    }
    E[ver] = ++_time;
    FT[_time] = a[ver];
}

void build(int node,int left,int right){
    if(left==right){
        tree[node]=FT[left];
        return ;
    }
    int mid=(left+right)/2;
    build(node*2,left,mid);
    build(node*2+1,mid+1,right);
    //tree[node]=tree[node*2]+tree[node*2+1];
    tree[node]=max(tree[node*2],tree[node*2+1]);
    //tree[node]=min(tree[node*2],tree[node*2+1]);
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
        //return left_node+right_node;
        return max(left_node,right_node);
        //return min(left_node,right_node);
    }

}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs();

    build(1, 1, _time);

    ll sum = 0;

    for (int i = 2; i <= n; i++) {
        int L_MAX = query(1, 1, _time, 1, S[i] - 1);
        int R_MAX = query(1, 1, _time, E[i] + 1, _time);
        L_MAX = max(L_MAX, R_MAX);
        sum += (1LL * L_MAX * a[i]);
    }

    cout << sum << '\n';

    return 0;
}
///https://codeforces.com/gym/428052/problem/F