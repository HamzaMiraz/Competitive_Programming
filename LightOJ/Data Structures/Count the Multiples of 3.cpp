#include <bits/stdc++.h>
using namespace std;

/// sl = segment left,sr = segment right, tree[nod] contain [sl-sr] range
#define ll long long
const int MAX_N =100007;
const int oo = 2e9+10;
int ar[MAX_N];
struct node{
    int oc_in_mod_3[3];
};
struct LT{
    node tree[4*MAX_N];
    int lazy[4*MAX_N];
    LT(){
        clear();
    }
    void clear(){
        //memset(tree,0,sizeof tree);
        //memset(lazy,0,sizeof lazy);//on when build off
        //memset(ar,0,sizeof ar);
    }
    inline void lazyUpdate(int nod,int sl,int sr){
        if(lazy[nod]==0)return;
        node cur=tree[nod];
        for(int i=0;i<3;i++){
            tree[nod].oc_in_mod_3[(i + lazy[nod]) % 3] = cur.oc_in_mod_3[i];
        }
        if(sl!=sr){
            int left_child = 2*nod , right_child = 2*nod+1;
            lazy[left_child] += lazy[nod], lazy[right_child] += lazy[nod];// chamge += or =
        }
        lazy[nod]=0;
    }
    node marge(node left_nod,node right_nod){
        node ans;
        for(int i=0;i<3;i++){
            ans.oc_in_mod_3[i]= left_nod.oc_in_mod_3[i] + right_nod.oc_in_mod_3[i];
        }
        return ans;
    }
    void build(int nod,int sl,int sr){
        lazy[nod]=0;
        if(sl==sr){
            tree[nod].oc_in_mod_3[0]=1;
            tree[nod].oc_in_mod_3[1]=0;
            tree[nod].oc_in_mod_3[2]=0;
            return;
        }
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;

        build(left_child , sl , mid);
        build(right_child , mid+1, sr);

        tree[nod] = marge(tree[left_child] , tree[right_child]);
    }
    int query(int nod,int sl,int sr,int ql,int qr){
        lazyUpdate(nod,sl,sr);
        if(ql<=sl && sr<=qr){///fully overlaped
            return tree[nod].oc_in_mod_3[0];
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

        tree[nod] = marge(tree[left_child] , tree[right_child]);
    }
}lt;
int ks;
signed main(){
    int n,q,ql,qr,ty;
    int val,t;
    cin>>t;
    while(t--){
        cin>>n>>q;
        cout<<"Case "<<++ks<<":\n";
        lt.build(1,1,n);
        while(q--){
            cin>>ty;
            if(ty==0){
                cin>>ql>>qr;
                ql++,qr++;
                lt.update(1,1,n,ql,qr,1);
            }else if(ty==1){
                cin>>ql>>qr;
                ql++,qr++;
                cout<<lt.query(1,1,n,ql,qr)<<"\n";
            }else{
                break;
            }
        }
        lt.clear();

    }
    return 0;
}


