#include <bits/stdc++.h>
using namespace std;

/// sl = segment left,sr = segment right, tree[nod] contain [sl-sr] range
#define ll long long
const int N =2e5;
const int oo = 2e9+10;
int a[N], b[N], Q[N];
struct LT{
    ll tree[4*N],lazy[4*N];
    LT(){
        clear();
    }
    void clear(){
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        //memset(ar,0,sizeof ar);
    }
    inline void lazyUpdate(int nod,int sl,int sr){
        if(lazy[nod]==0)return;
        //tree[nod] += lazy[nod];// change += or = // if we chaking for max,min 
        tree[nod] += lazy[nod]*(sr-sl+1);// change += or =
        if(sl!=sr){
            int left_child = 2*nod , right_child = 2*nod+1;
            lazy[left_child] += lazy[nod], lazy[right_child] += lazy[nod];// chamge += or =
        }
        lazy[nod]=0;
    }
    void build(int nod,int sl,int sr){
        lazy[nod]=0;
        if(sl==sr){
            tree[nod]=0;// root node
            return;
        }
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;

        build(left_child , sl , mid);
        build(right_child , mid+1, sr);

        tree[nod] = tree[left_child] + tree[right_child];///change
    }
    ll query(int nod,int sl,int sr,int ql,int qr){
        lazyUpdate(nod,sl,sr);
        if(ql<=sl && sr<=qr){///fully overlaped
            return tree[nod];
        }
        if(qr<sl || sr<ql)return 0;/// out of the range ,0/-oo/oo;
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;

        return query(left_child,sl,mid,ql,qr)+query(right_child,mid+1,sr,ql,qr);///change
    }
    void update(int nod,int sl,int sr,int ql,int qr,int val){
        lazyUpdate(nod,sl,sr);
        if(ql<=sl && sr<=qr){///fully overlaped
            lazy[nod]+=val;
            lazyUpdate(nod,sl,sr);
            return;
        }
        if(qr<sl || sr<ql)return;/// position is out of the range

        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;

        update(left_child,sl,mid,ql,qr,val);
        update(right_child,mid+1,sr,ql,qr,val);

        tree[nod]=tree[left_child]+tree[right_child];///change
    }
}lt;
int ks;
signed main(){
    //ios_base::sync_with_stdio(0);
  //cin.tie(0);
    int n,q,ql,qr,ty;
    int val;
    int t;cin>>t;
    while(t--){
        cout<<"Case "<<++ks<<":\n";
        cin>>n>>q;
        
        set<int>st;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
            st.insert(a[i]);
            st.insert(b[i]);
        }
        for(int i=1;i<=q;i++){
            cin>>Q[i];
            st.insert(Q[i]);
        }
        map<int,int>mp;
        int id=0;
        for(auto it : st){
            mp[it]=++id;
        }
        int limit=id;
        for (int i = 1; i <= n; i++) {
            a[i] = mp[a[i]];
            b[i] = mp[b[i]];
        }

        for (int i = 1; i <= q; i++) {
            Q[i] = mp[Q[i]];
          //cout<<Q[i]<<"\n";
        }
        for(int i=1;i<=n;i++){
            lt.update(1,1,id,a[i],b[i],1);
        }
        for(int i=1;i<=q;i++){
            cout<<lt.query(1,1,id,Q[i],Q[i])<<"\n";
        }
        lt.clear();
    }
    return 0;
}


