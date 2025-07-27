#include <bits/stdc++.h>
using namespace std;

/// sl = segment left,sr = segment right, tree[nod] contain [sl-sr] range
#define ll long long
const int N=3e4+10;
const int oo = 2e9+10;


int E,V;
int LVL[N];
int par[N];
int A[N][30];
vector<int>adj[N];
int ar[N];
int in[N];
int out[N];
int FT[2*N];
int time_;
/// finding nodes tree level and parent
void leveling_dfs(int u){
    time_++;
    in[u]=time_;
    FT[time_]=ar[u];
    for(auto v : adj[u]){
        if(v==par[u])continue;
        LVL[v]=LVL[u]+1;
        par[v]=u;
        leveling_dfs(v);
    }
    time_++;
    out[u]=time_;
    FT[time_]=-ar[u];
}

void Sparse_Table()
{
    // creating sparse table
    for(int p=0;p<=log2(V)+1;p++)
    {
        for(int i=1;i<=V;i++)
        {
            if(p==0)
                A[i][p] = par[i];///2^p = 2^0 = 1'th parent
            else
                A[i][p] = A[A[i][p-1]][p-1];///  A[i][p] = i'th nodes 2^p'th parant
        }
    }
}

int LCA(int u,int v)
{
    if(LVL[u]>LVL[v])
        swap(u,v);
    //Bring u and v in same level
    for(int i=log2(V)+1;i>=0;i--){
        int x = A[v][i];
        if(LVL[u]==LVL[x]){
            v=x;
            break;
        }
        if(LVL[u]<LVL[x])
            v = x;
    }
    if(u==v)return u;

    for(int i=log2(V)+1;i>=0;i--)
    {
        if(A[u][i] != -1 && A[u][i] != A[v][i])
        {
            u = A[u][i];
            v = A[v][i];
        }
    }
    return par[u];
}

struct ST{
    int tree[8*N];
    ST(){
        clear();
    }
    void clear(){
        memset(tree,0,sizeof tree);
        //memset(ar,0,sizeof ar);
    }
    void build(int nod,int sl,int sr){
        if(sl==sr){
            tree[nod]=FT[sr];// root node
            return;
        }
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;

        build(left_child , sl , mid);
        build(right_child , mid+1, sr);

        tree[nod] = tree[left_child] + tree[right_child];///change
    }
    int query(int nod,int sl,int sr,int ql,int qr){
        if(sl>=ql && sr<=qr){///fully overlaped
            return tree[nod];
        }
        if(qr<sl || ql>sr)return 0;/// out of the range ,0/-oo/oo;
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;
        
        return query(left_child,sl,mid,ql,qr)+query(right_child,mid+1,sr,ql,qr);///change
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

        tree[nod]=tree[left_child]+tree[right_child];///change
    }
}st;
int ks;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,ql,qr,ty,pos;
    int val;
    int t;cin>>t;
    while(t--){
        cout<<"Case "<<++ks<<":\n";
        cin>>n;
        V=n;
        for(int i=0;i<n+5;i++)
        {   
            adj[i].clear();
            for(int j=0;j<=log2(n+3);j++)
                A[i][j] = -1;
        }
        for(int i=1;i<=n;i++){
            cin>>ar[i];
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            u++,v++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        time_=0;
        LVL[1]=1,par[1]=1;
        leveling_dfs(1);
        Sparse_Table();
        st.build(1,1,time_);
        cin>>q;
        while(q--){
            cin>>ty;
            if(ty==1){
                cin>>pos>>val;
                pos++;
                FT[in[pos]]=val;
                FT[out[pos]]=-val;
                st.update(1,1,time_,in[pos],val);
                st.update(1,1,time_,out[pos],-val);
            }else if(ty==0){
                cin>>ql>>qr;
                qr++,ql++;
                
                int ansistor=LCA(ql,qr);
                int ans=st.query(1,1,time_,1,in[ql]);
                
                ans+=st.query(1,1,time_,1,in[qr]);
                ans-=2*st.query(1,1,time_,1,in[ansistor]);
                
                cout<<ans+FT[in[ansistor]]<<"\n";
            }
        }

    }
    return 0;


}