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
const double EPS = 1e-7; ///1*10^-7
const int oo = 1e9+10;
const ll MOD = 1e9 +7;// Prime

double cross(array<int,2>a,array<int,2>b){
    return (a[0]*b[1]) - (a[1]*b[0]);
}

void solve(){

    double x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    double a1,b1,a2,b2,c1,c2;
    
    array<int,2>v1,v2;// macking vector
    v1[0]=x2-x1;
    v1[1]=y2-y1;
    v2[0]=x4-x3;
    v2[1]=y4-y3;

    if(fabs(cross(v1,v2))<=1e-9){/// vector cross product is 0 then theta ==0
        array<int,2>v3={x3-x2, y3-y2};
        if(fabs(cross(v1,v3))<=1e-9){/// vector cross product is 0 then theta ==0
            cout<<"LINE\n";
        }else{
            cout<<"NONE\n";
        }
        return;
    }
    a1=y1-y2;
    b1=-x1+x2;
    c1=x1*(y1-y2) - y1*(x1-x2);
    
    a2=y3-y4;
    b2=-x3+x4;
    c2=x3*(y3-y4) - y3*(x3-x4);

    double x=(c1*b2-c2*b1)/(a1*b2-a2*b1);///Cramer’s Rule
    double y=(a1*c2-a2*c1)/(a1*b2-a2*b1);


    cout<<"POINT "<<sp(x,2)<<" "<<sp(y,2)<<"\n";



}

signed main()
{
#ifndef ONLINE_JUDGE
     freopen("inputf.in", "r", stdin);  ///To read from a file.
//    freopen("outputf.in", "w", stdout);  ///To write  a file.
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    ll tks=1;
    cin>>tks;
    cout<<"INTERSECTING LINES OUTPUT\n";
    for(ll ks=1;ks<=tks;ks++){
        //cout<<"Case "<<ks<<": ";
        solve();
    }
    cout<<"END OF OUTPUT\n";
    //cerr<<"\nTime:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
///invisible =  