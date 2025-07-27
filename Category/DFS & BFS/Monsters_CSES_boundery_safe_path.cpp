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
template<class T> using iset=tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update> ;///exmp= iset<double>st
///who is k'th position= set.find_by_order(k),index of v = set.order_of_key(v);

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
vector<T>primeFactors(T n){vector<T>PRIME;T c=2;while///prime factor
(n>1){if(n%c==0){PRIME.push_back(c);n/=c;}else c++;}return PRIME;}

template <typename T>
T nCr(T n, T r){T res=1;for (T i=0;i<r;i++){
res *= (n-i);res /= (i+1);}return res;}/// NCR

template <typename T>
T fact(T n){if(n<=1)return 1;return n*fact(n-1);}

template <typename T>
T nPr(T n, T r){return fact(n)/fact(n-r);}///NPR

template <typename T>
vector<T>BigFactorial(T n){vector<T> dg;dg.push_back(1);
for (T f=2;f<=n;f++) {T c = 0;for (T i= 0;i<dg.size();i++){
T p=dg[i]*f+c;dg[i]=p%10;c=p/10;}while(c){dg.push_back(c%10);c/=10;}}
reverse(dg.begin(),dg.end());return dg;}

#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define all(x) x.begin(), x.end()
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

template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 2e9+10;
const ll MOD = 1e9+7;// Prime
vector<string>grid;
pair<int,int> par[1002][1002];
int dr[]={+1,-1,0,0};
int dc[]={0,0,-1,+1};
int r,c;
vector<vector<int>>bfs(vector<pair<int,int>>&v){
    vector<vector<int>>dis(r+1,vector<int>(c+1,oo));
    queue<pair<int,int>>q;
    for(auto [f,s] : v){
        dis[f][s]=0;
        q.push({f,s});
    }
    while(!q.empty()){
        auto u=q.front();
        q.pop();
       for(int i=0;i<4;i++){
           int rr= u.first+dr[i];
           int cc= u.second+dc[i];
           if(rr>=0 && rr<=r-1 && cc>=0 && cc<=c-1 && grid[rr][cc]!='#' && dis[rr][cc]==oo){
                dis[rr][cc] = dis[u.first][u.second] + 1;
                q.push({rr,cc});
           }
        }
    }
    return dis;
 }
pair<int,int> safebfs(vector<pair<int,int>>&me,vector<pair<int,int>>&monstars){
    vector<vector<int>>idis=bfs(me);
    vector<vector<int>>mdis=bfs(monstars);

    vector<vector<int>>safe(r+1,vector<int>(c+1,false));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(idis[i][j]<mdis[i][j] && grid[i][j]!='#'){
                safe[i][j]=true;
            }
        }
    }
    vector<vector<int>>vis(r+1,vector<int>(c+1,false));
    queue<pair<int,int>>q;
    q.push(me[0]);
    vis[me[0].first][me[0].second]=true;
    while(!q.empty()){
        auto u=q.front();
        q.pop();
       for(int i=0;i<4;i++){
           int rr= u.first+dr[i];
           int cc= u.second+dc[i];
           if(rr>=0 && rr<=r-1 && cc>=0 && cc<=c-1 && safe[rr][cc] && !vis[rr][cc]){
                vis[rr][cc]=1;
                par[rr][cc]={u};
                q.push({rr,cc});
                if(rr==0 || rr==r-1 || cc==0 || cc==c-1){
                    return {rr,cc};
                }
           }
        }
    }
    return{-1,-1};

}
int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
//    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin>>r>>c)
    {
        string s;
        for(int i=0;i<r;i++){
            cin>>s;
            grid.push_back(s);
        }
        pair<int,int> start;
        vector<pair<int,int>>me,monstars;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                par[i][j]={-1,-1};
                if(grid[i][j]=='A'){
                    me.push_back({i,j});
                }
                if(grid[i][j]=='M'){
                    monstars.push_back({i,j});
                }

            }
        }
       

        if(me[0].first==0 || me[0].second==0 || me[0].first==r-1 || me[0].second==c-1){
            cout<<"YES\n";
        }else{
             auto bound=safebfs(me,monstars);
            if(bound.first==-1 || bound.second==-1){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
                vector<pair<int,int>>ans;
                while(bound.first!=-1){
                    ans.push_back(bound);
                    bound=par[bound.first][bound.second];
                }
                cout<<ans.size()-1<<"\n";
                for(int i=ans.size()-1;i>=1;i--){
                    if(ans[i].S>ans[i-1].S){
                        cout<<"L";
                    }
                    if(ans[i].S<ans[i-1].S){
                        cout<<"R";
                    }
                    if(ans[i].F>ans[i-1].F){
                        cout<<"U";
                    }
                    if(ans[i].F<ans[i-1].F){
                        cout<<"D";
                    }
                }
                cout<<"\n";

            }
        }
    }
    return 0;
}
///invisible =  
