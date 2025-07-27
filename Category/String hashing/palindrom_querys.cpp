#include <bits/stdc++.h>
using namespace std;

/// sl = segment left,sr = segment right, tree[nod] contain [sl-sr] range
#define ll long long
const int oo = 2e9+10;
#define F  first
#define S  second
const int MAX = 2e5 + 10;// string max size
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll base1 = 269;//31,//53
const ll base2 = 277;//31,//53
pair<ll,ll> pw[MAX], inv_pw[MAX];
string s;
int len;
struct nn{
    ll p1,p2,s1,s2;
};
ll BIGMOD(ll b,ll power,ll Mod){
    ll ans = 1;
    while(power){
        if(power & 1)ans = (ans * b) % Mod;
        b = (b * b) % Mod;power = power >> 1;}
    return ans%Mod;
}

void pow_clc(){
    ll rev_base1=BIGMOD(base1,MOD1-2,MOD1);///base1^-1
    ll rev_base2=BIGMOD(base2,MOD2-2,MOD2);///base2^-1
    pw[0]={1,1};
    inv_pw[0]={1,1};
    for(int i=1;i<MAX;i++){
        
        pw[i].F = 1LL * pw[i-1].F * base1 % MOD1;
        inv_pw[i].F = 1LL * inv_pw[i-1].F * rev_base1 % MOD1;
        
        pw[i].S = 1LL * pw[i-1].S * base2 % MOD2;
        inv_pw[i].S = 1LL * inv_pw[i-1].S * rev_base2 % MOD2;
    }
}
nn ar[MAX];
nn get_hsh(int i,char ch){
    i--;
    ll pr1,pr2,sf1,sf2;
    pr1= (ch*pw[i].F)%MOD1;
    pr2= (ch*pw[i].S)%MOD2;
    sf1= (ch*pw[len-i-1].F)%MOD1;
    sf2= (ch*pw[len-i-1].S)%MOD2;
    return {pr1,pr2,sf1,sf2};
}
bool is_palindrom(nn v,int i,int j){
    i--;
    j--;
    pair<ll,ll>pr;
    pair<ll,ll>sf;

    pr.F=(v.p1*inv_pw[i].F)%MOD1;
    pr.S=(v.p2*inv_pw[i].S)%MOD2;

    sf.F=(v.s1*inv_pw[len-j-1].F)%MOD1;
    sf.S=(v.s2*inv_pw[len-j-1].S)%MOD2;

    return pr==sf;
}
struct ST{
    nn tree[4*MAX];
    ST(){
        clear();
    }
    void clear(){
        memset(tree,0,sizeof tree);
        //memset(ar,0,sizeof ar);
    }
    void build(int nod,int sl,int sr){
        if(sl==sr){
            tree[nod]=ar[sr];// root node
            return;
        }
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;

        build(left_child , sl , mid);
        build(right_child , mid+1, sr);

        tree[nod].p1 = tree[left_child].p1 + tree[right_child].p1;///change
        tree[nod].p2 = tree[left_child].p2 + tree[right_child].p2;///change
        tree[nod].s1 = tree[left_child].s1 + tree[right_child].s1;///change
        tree[nod].s2 = tree[left_child].s2 + tree[right_child].s2;///change

    }
    nn query(int nod,int sl,int sr,int ql,int qr){
        if(sl>=ql && sr<=qr){///fully overlaped
            return tree[nod];
        }
        if(qr<sl || ql>sr)return {0,0,0,0};/// out of the range ,0/-oo/oo;
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;
        auto lf =query(left_child,sl,mid,ql,qr);
        auto rf=query(right_child,mid+1,sr,ql,qr);///change
        return {(lf.p1+rf.p1)%MOD1, (lf.p2+rf.p2)%MOD2 , (lf.s1+rf.s1)%MOD1 , (lf.s2+rf.s2)%MOD2};
    }
    void update(int nod,int sl,int sr , int pos,nn val){
        if(pos==sl && pos==sr){
            tree[nod]=val;//ar[pos];
            return;
        }
        if(pos>sr || pos<sl)return;/// position is out of the range

        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;

        update(left_child,sl,mid,pos,val);
        update(right_child,mid+1,sr,pos,val);

        tree[nod].p1 = tree[left_child].p1 + tree[right_child].p1;///change
        tree[nod].p2 = tree[left_child].p2 + tree[right_child].p2;///change
        tree[nod].s1 = tree[left_child].s1 + tree[right_child].s1;///change
        tree[nod].s2 = tree[left_child].s2 + tree[right_child].s2;///change

    }
}st;

signed main(){
    pow_clc();
    int n,q,ql,qr,ty,pos;
    char ch;
    while(cin>>s){
        len=s.size();
        n=len;
        for(int i=1;i<=n;i++){
            ar[i]=get_hsh(i,s[i-1]);
        }
        st.build(1,1,n);
        while(1){
            cin>>ty;
            if(ty==1){
                cin>>pos>>ch;
                ar[pos]=get_hsh(pos,ch);
                st.update(1,1,n,pos,ar[pos]);
            }else if(ty==2){
                cin>>ql>>qr;
                nn ans=st.query(1,1,n,ql,qr);
                if(is_palindrom(ans,ql,qr)){
                    cout<<"palindrom\n";
                }else{
                    cout<<"not palindrom\n";
                }
            }
        }
        st.clear();


    }
    return 0;
}


