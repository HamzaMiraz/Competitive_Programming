#include <bits/stdc++.h>
using namespace std;

/// sl = segment left,sr = segment right, tree[nod] contain [sl-sr] range
#define ll long long
const int MAX_N =100007;
const ll oo = 2e10+10;
ll ar[MAX_N];
struct node{
    ll ant,occ,gcd;
};
struct ST{
    node tree[4*MAX_N];
    ST(){
        clear();
    }
    void clear(){
        //memset(tree,0,sizeof tree);
        //memset(ar,0,sizeof ar);
    }
    void build(int nod,int sl,int sr){
        if(sl==sr){
            tree[nod]={ar[sr],1,ar[sr]};;// root node
            return;
        }
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;

        build(left_child , sl , mid);
        build(right_child , mid+1, sr);

        if(tree[left_child].ant<tree[right_child].ant){
            tree[nod].ant=tree[left_child].ant;
            tree[nod].occ=tree[left_child].occ;

        }else if(tree[left_child].ant>tree[right_child].ant){
            tree[nod].ant=tree[right_child].ant;
            tree[nod].occ=tree[right_child].occ;
        }else{
            tree[nod].ant=tree[right_child].ant;
            tree[nod].occ= tree[right_child].occ + tree[left_child].occ;
        }
        tree[nod].gcd = __gcd(tree[left_child].gcd , tree[right_child].gcd);///change
    }
    node query(int nod,int sl,int sr,int ql,int qr){
        if(sl>=ql && sr<=qr){///fully overlaped
            return tree[nod];
        }
        if(qr<sl || ql>sr)return {oo,0,0};/// out of the range ,0/-oo/oo;
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;
        auto left_node=query(left_child,sl,mid,ql,qr);
        auto right_node=query(right_child,mid+1,sr,ql,qr);

        node ans;
        if(left_node.ant<right_node.ant){
            ans.ant=left_node.ant;
            ans.occ=left_node.occ;

        }else if(left_node.ant>right_node.ant){
            ans.ant=right_node.ant;
            ans.occ=right_node.occ;
        }else{
            ans.ant=right_node.ant;
            ans.occ= right_node.occ + left_node.occ;
        }
        ans.gcd = __gcd(left_node.gcd , right_node.gcd);///change
        return ans;
    }

}st;

signed main(){
    int n,q,ql,qr,ty,pos;
    int val;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>ar[i];
        }
        st.build(1,1,n);
        cin>>q;
        while(q--){
            cin>>ql>>qr;
           auto ans= st.query(1,1,n,ql,qr);
           //cout<<ans.ant<<" "<<ans.occ<<" "<<ans.gcd<<"\n";
           if(ans.ant== ans.gcd){
                cout<<(qr-ql+1)-(ans.occ)<<"\n";
           }else{
                cout<<qr-ql+1<<"\n";
           }

        }
    }
    return 0;
}


