#include<bits/stdc++.h>
using namespace std;

//For Debugging
#define debug(a...)          {cout<<__LINE__<<" #--> ";dbg,a; cout<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>using iset=tree<T,null_type,less<T>,///descending_order=greater<T>,multi_iset=less_equal<T>
rb_tree_tag,tree_order_statistics_node_update> ;///exmp= iset<double>st
///who is k'th position= *(set.find_by_order(k)),index of v = set.order_of_key(v);

typedef long long ll;/// 1e18;
//typedef __int128_t LL;/// 1e32;
template <typename T>
T BIGMOD(T base,T power,T Mod=1e9+7){T ans = 1;
while(power){if(power & 1)ans = (ans * base) % Mod;
base = (base * base) % Mod;power = power >> 1;}return ans;}

template <typename T>
T INV(T base,T mod=1e9+7){//defult mod=1e9+7
    return BIGMOD(base%mod,mod-2,mod)%mod;///base^-1
}

template <typename T>
T nCr(T n, T r){T res=1;for (T i=0;i<r;i++){
res *= (n-i);res /= (i+1);}return res;}/// NCR

template <typename T>
T fact(T n){if(n<=1)return 1;return n*fact(n-1);}

template <typename T>
T nPr(T n, T r){return fact(n)/fact(n-r);}///NPR


#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define all(x) x.begin(), x.end()
#define loop(IV,INIT,NV) for(int IV=INIT;IV<=NV;IV++)
#define lbv(vec,x) lower_bound(all(vec),x)-vec.begin()//retrun index
#define ubv(vec,x) upper_bound(all(vec),x)-vec.begin()
#define lba(ar,n,x) lower_bound(ar,ar+n,x)-&ar[0];//return index
#define uba(ar,n,x) upper_bound(ar,ar+n,x)-&ar[0];
#define lb(mp,x) mp.lower_bound(x);///for set,map
#define ub(st,x) st.upper_bound(x);///return pointer address
#define GCD(a,b)  __gcd(a,b)
#define LCM(a,b)  (a*b)/__gcd(a,b)
#define sqr(a)    ((a)*(a))
#define deg(n)  n*PI/180 /// redian to degree
#define sp(n,d)  fixed << setprecision(d) <<n
#define pb emplace_back
#define F  first
#define S  second
#define ss " "
#define nn printf("\n");
#define el cout<<"\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

const double PI = acos(-1);
const double EPS = 1e-9; ///1*10^-7
const ll oo = LLONG_MIN / 4;

struct P{
    double x,y;
};
P vec2d(P &a,P &b){
    return{b.x - a.x, b.y - a.y};
}
double cross(P &A, P &B) {
    return A.x * B.y - A.y * B.x;
}
bool onSegment(P &a,P &b, P &p) {
    return min(a.x, b.x) - 1e-9 <= p.x && p.x <= max(a.x, b.x) + 1e-9
        && min(a.y, b.y) - 1e-9 <= p.y && p.y <= max(a.y, b.y) + 1e-9;
}

bool intersect(P &a,P &b, P &c, P&d){
    P AB=vec2d(a,b);
    P AC=vec2d(a,c);
    P AD=vec2d(a,d);
    P CD=vec2d(c,d);
    P CB=vec2d(c,b);
    P CA=vec2d(c,a);

    if(cross(AB,AC)*cross(AB,AD)<0 && cross(CD,CB)*cross(CD,CA)<0)return true;
    if(cross(AB,AC)==0 && onSegment(a,b,c))return true;
    if(cross(AB,AD)==0 && onSegment(a,b,d))return true;
    if(cross(CD,CB)==0 && onSegment(c,d,b))return true;
    if(cross(CD,CA)==0 && onSegment(c,d,a))return true;
    return false;

}
bool insiderect(P &p, P &A,P &B, P &C, P &D){
    double mnx=min({A.x,B.x,C.x,D.x});
    double mxx=max({A.x,B.x,C.x,D.x});
    double mny=min({A.y,B.y,C.y,D.y});
    double mxy=max({A.y,B.y,C.y,D.y});

    return p.x >= mnx-1e-9 && mxx+1e-9 >= p.x && p.y >= mny-1e-9 && mxy+1e-9 >= p.y;
}
void solve() {
    P a,b,c,d;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;

    P A={c.x,c.y};
    P C={d.x,d.y};
    P B={C.x,A.y};
    P D={A.x,C.y};
    if(insiderect(a,A,B,C,D) || insiderect(b,A,B,C,D)){
        cout<<"T\n";
        return;
    }
    if(intersect(a,b,A,B)){
        cout<<"T\n";
        return;
    }
    if(intersect(a,b,A,D)){
        cout<<"T\n";
        return;
    }
    if(intersect(a,b,B,C)){
        cout<<"T\n";
        return;
    }
    if(intersect(a,b,C,D)){
        cout<<"T\n";
        return;
    }
    cout<<"F\n";


}

signed main()
{
#ifndef ONLINE_JUDGE
     freopen("inputf.in", "r", stdin);  ///To read from a file.
//    freopen("outputf.in", "w", stdout);  ///To write  a file.
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int tks=1;
    cin>>tks;
    for(int ks=1;ks<=tks;ks++){
        //cout<<"Case "<<ks<<": ";
        solve();
    }
    //cerr<<"\nTime:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
///invisible =  