#include <bits/stdc++.h>
using namespace std;

/// sl = segment left,sr = segment right, tree[nod] contain [sl-sr] range
#define ll long long
const int MAX_N =100007;
const int oo = 2e9+10;
int ar[MAX_N];
struct node{
    int first_element,last_element,first_element_ocars,last_element_ocars,maximum_ocars;
};
struct ST{
    node tree[4*MAX_N];
    node mearge(node l,node r){
        if(l.first_element==-1)return r;
        if(r.first_element==-1)return l;
        node nod;
        nod.first_element=l.first_element;
        nod.first_element_ocars=l.first_element_ocars;
        if(l.first_element==r.first_element){
            nod.first_element_ocars+=r.first_element_ocars;
        }
        nod.last_element=r.last_element;
        nod.last_element_ocars=r.last_element_ocars;
        if(r.last_element==l.last_element){
            nod.last_element_ocars+=l.last_element_ocars;
        }
        nod.maximum_ocars=max(l.maximum_ocars,r.maximum_ocars);
        if(l.last_element==r.first_element){
            nod.maximum_ocars=max(nod.maximum_ocars,l.last_element_ocars+r.first_element_ocars);
        }
        return nod;
    }
    void build(int nod,int sl,int sr){
        if(sl==sr){
            tree[nod]={ar[sl],ar[sl],1,1,1};
            return;
        }
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;

        build(left_child , sl , mid);
        build(right_child , mid+1, sr);

        tree[nod]=mearge(tree[left_child],tree[right_child]);
    }
    node query(int nod,int sl,int sr,int ql,int qr){
        if(qr<sl || ql>sr)return {-1,-1,-1,-1,-1};/// out of the range ,0/-oo/oo;
        if(sl>=ql && sr<=qr){///fully overlaped
            return tree[nod];
        }
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;
        
        return mearge(query(left_child,sl,mid,ql,qr),query(right_child,mid+1,sr,ql,qr));///change
    }

}st;
int ks;
signed main(){
    int n,q,ql,qr,ty,pos,c;
    int val,t;cin>>t;
    while(t--){
        cout<<"Case "<<++ks<<":\n";
        cin>>n>>c>>q;
        for(int i=1;i<=n;i++){
            cin>>ar[i];
        }
        st.build(1,1,n);
        while(q--){
            cin>>ql>>qr;
            node ans=st.query(1,1,n,ql,qr);
            cout<<ans.maximum_ocars<<"\n";
        }

    }
    return 0;
}


