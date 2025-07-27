#include <bits/stdc++.h>
using namespace std;

/// sl = segment left,sr = segment right, tree[nod] contain [sl-sr] range
#define ll long long
const int MAX_N =200007;
const int oo = 2e9+10;
int ar[MAX_N];
struct LT{
    ll tree[4*MAX_N],lazy[4*MAX_N];
    LT(){
        clear();
    }
    void clear(){
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);//on when build off
        //memset(ar,0,sizeof ar);
    }
    inline void lazyUpdate(int nod,int sl,int sr){
        if(lazy[nod]==0)return;
        tree[nod] += lazy[nod];// change += or = // if we chaking for max,min 
        if(sl!=sr){
            int left_child = 2*nod , right_child = 2*nod+1;
            lazy[left_child] += lazy[nod], lazy[right_child] += lazy[nod];// chamge += or =
        }
        lazy[nod]=0;
    }
    void build(int nod,int sl,int sr){
        lazy[nod]=0;
        if(sl==sr){
            tree[nod]=ar[sr];// root node
            return;
        }
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;

        build(left_child , sl , mid);
        build(right_child , mid+1, sr);

        tree[nod] = min(tree[left_child] , tree[right_child]);///change
    }
    ll query(int nod,int sl,int sr,int ql,int qr){
        lazyUpdate(nod,sl,sr);
        if(ql<=sl && sr<=qr){///fully overlaped
            return tree[nod];
        }
        if(qr<sl || sr<ql)return 1e17;/// out of the range ,0/-oo/oo;
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;

        return min(query(left_child,sl,mid,ql,qr),query(right_child,mid+1,sr,ql,qr));///change
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

        tree[nod] = min(tree[left_child] , tree[right_child]);///change
    }
}lt;

signed main(){
    int n,q,ql,qr,ty,val;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>ar[i];
        }
        cin>>q;
        cin.ignore();
        lt.build(1,1,n);
        while(q--){
            string line;
            getline(cin,line);
            stringstream ss(line);
                ss>>ql>>qr;
                ql++,qr++;
                if(ss>>val){
                    if(ql>qr){
                        lt.update(1,1,n,ql,n,val);
                        lt.update(1,1,n,1,qr,val);
                    }else{
                        lt.update(1,1,n,ql,qr,val);
                    }
                }else{
                    if(ql>qr){
                        cout<<min(lt.query(1,1,n,ql,n),lt.query(1,1,n,0,qr))<<"\n";
                    }else{
                        cout<<lt.query(1,1,n,ql,qr)<<"\n";
                    }
                }

            }
        
        lt.clear();

    }
    return 0;
}
/*

5
1 2 3 4 5
2 1 5
1 1 4 2
2 1 5
1 4 5 2
2 3 5
2 1 5
1 1 3 1
2 1 5
1 2 3 5
2 1 4
1 5 5 9
2 5 5
2 1 5

3
*/

