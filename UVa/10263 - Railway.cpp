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

struct Point{
    double x,y;
};

double cross(Point a,Point b){
    return (a.x*b.y) - (a.y*b.x);
}
double dot(Point a,Point b){
    return (a.x*b.x)+(a.y*b.y);
}
double pdis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}


pair<Point,double> dis(Point M,Point A,Point B){
    Point AM={M.x-A.x,M.y-A.y};
    Point AB={B.x-A.x,B.y-A.y};
    if(dot(AB,AM)<=0){
        return {A,pdis(M,A)};
    }
    Point BM={M.x-B.x,M.y-B.y};
    Point BA={A.x-B.x,A.y-B.y};
    if(dot(BA,BM)<=0){
        return {B,pdis(M,B)};
    }
    double len_AB=sqrt(AB.x*AB.x + AB.y*AB.y); // |AB|
    double dist = fabs(cross(AM,AB)/len_AB);
    double t=dot(AM,AB)/dot(AB,AB);
    Point Q={A.x+AB.x*t,A.y+AB.y*t};// this is actually projection point [ projection AM on AB]

    return{Q,dist};
}

void solve(double x, double y,int N){
    Point M={x,y};

    int n=N;
    n++;
    Point p[n+2];
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }
    double mn=1e9;
    double tx,ty;
    for(int i=1;i<n;i++){
        Point A={p[i].x,p[i].y};
        Point B={p[i+1].x,p[i+1].y};
        Point AB={B.x-A.x,B.y-A.y};
        pair<Point,double> d=dis(M,A,B);
        if(d.second<mn){
            mn=d.second;
            tx=d.first.x;
            ty=d.first.y;
        }

    }
    cout<<sp(tx,4)<<"\n"<<sp(ty,4)<<"\n";





}

signed main()
{
#ifndef ONLINE_JUDGE
     freopen("inputf.in", "r", stdin);  ///To read from a file.
//    freopen("outputf.in", "w", stdout);  ///To write  a file.
#endif
    //cin.tie(nullptr)->sync_with_stdio(false);
    ll tks=1;
    double x, y;
    while(cin>>x>>y)
    {
        int N;
        cin>>N;
        //cout<<"Case "<<ks<<": ";
        solve(x,y,N);
    }
    //cerr<<"\nTime:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
///invisible =  