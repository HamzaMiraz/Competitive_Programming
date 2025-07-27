#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#endif
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define vii vector<pair<int,int>>
#define vll vector<pair<ll,ll>>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pql priority_queue<ll>
#define LCM(a,b)  (a*b)/__gcd(a,b)
#define sp(n,x)  fixed << setprecision(x) <<n
#define sqr(a)    ((a)*(a))
#define ss " "
#define nn "\n"
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;
const int sz=2e5+10;
const ll mod=1e9+7;
const double PI = acos(-1);
 ll cil(ll x,ll y){
    if(x%y)return x/y +1;
    return x/y;
}
int ks;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    double r1,r2,r3,a,b,c;
    while (t--) {
        cin>>r1>>r2>>r3;
        a=r1+r2;
        b=r3+r2;
        c=r1+r3;
        double s=(a+b+c)/2.0;
        double tri_area=sqrt(s*(s-a)*(s-b)*(s-c));

        // double  A=asin((tri_area*2)/(b*c));
        // double  B=asin((tri_area*2)/(a*c));
        // double  C=asin((tri_area*2)/(b*a));

        double C=acos((a*a+b*b-c*c)/(2*a*b));
        double B=acos((a*a+c*c-b*b)/(2*a*c));
        double A=acos((b*b+c*c-a*a)/(2*b*c));
        //cout<<tri_area<<" "<<A<<" "<<B<<" "<<C<<nn;

        double part1=sqr(r1)*B/2.0;
        double part2=sqr(r2)*C/2.0;
        double part3=sqr(r3)*A/2.0;
        double ans=tri_area-part1-part2-part3;
        cout<<"Case "<<++ks<<": "<<sp(ans,7)<<"\n";

    }
    return 0;
}
