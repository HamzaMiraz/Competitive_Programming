#include<bits/stdc++.h>
using namespace std;

int n;
const int MAX_N =200005;
struct ST{
    int tree[4*MAX_N];
    ST(){
        clear();
    }
    void clear(){
        memset(tree,0,sizeof tree);
        //memset(ar,0,sizeof ar);
    }
    void build(int nod,int sl,int sr){
        if(sl==sr){
            tree[nod]=0;// root node
            return;
        }
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;

        build(left_child , sl , mid);
        build(right_child , mid+1, sr);
    }
    int query(int nod,int sl,int sr,int ql,int qr){
        if(sl>=ql && sr<=qr){///fully overlaped
            return tree[nod];
        }
        if(qr<sl || ql>sr)return 0;/// out of the range ,0/-oo/oo;
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;

        return max(query(left_child,sl,mid,ql,qr),query(right_child,mid+1,sr,ql,qr));///change
    }
    void update(int nod,int sl,int sr , int pos,int val){
        if(pos==sl && pos==sr){
            tree[nod]=val;//ar[pos];
            return;
        }
        if(pos>sr || pos<sl)return;/// position is out of the range

        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;

        update(left_child,sl,mid,pos,val);
        update(right_child,mid+1,sr,pos,val);

        tree[nod]=max(tree[left_child],tree[right_child]);///change
    }
}st;

void solve(){
    cin>>n;
    int ar[n+2];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    st.build(1,1,MAX_N); /// segment tree on value
    // segmentree not working above 1e6 // needs to compress values 
    // coordinate compression, now all a[i] are 1 <= a[i] <= n which is cute
    set<int>s;
    for(int i=0;i<n;i++)s.insert(ar[i]);
    int id=0;
    map<int,int>mp;
    for(auto it : s){
        mp[it]=++id;
    }
    for(int i=0;i<n;i++)ar[i]=mp[ar[i]];
    vector<int>dp(n+2,1);
    int mx=1;
    for(int i=0;i<n;i++){
        // for(int j=0;j<i;j++){
        //     if(ar[j]<ar[i]){
        //         dp[i]=max(dp[i],1+dp[j]);
        //     }
        // }
        // mx=max(dp[i],mx);
        dp[i]=max(dp[i],st.query(1,1,MAX_N,1,ar[i]-1)+1);
        st.update(1,1,MAX_N,ar[i],dp[i]);
        mx=max(mx,dp[i]);
    }
    cout<<mx<<"\n";

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    //cerr<<"\nTime:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n"; 
    return 0;
}
///invisible =  