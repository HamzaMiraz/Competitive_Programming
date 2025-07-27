#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//For Debugging
#define debug(a...)          {cout<<" #--> ";dbg,a; cout<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;


#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
typedef long long LL;
const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 1e8+0.5;

int P[755], R[755];
struct edg {
    int u, v;
    double w;
};
edg E[755*755];

bool cmp(edg a, edg b) {
    return a.w < b.w;
}
void init(int n) {
    static int i;
    for(int i = 0; i <= n; i++)
        P[i] = i, R[i] = 1;
}
int findSet(int u){
    if(u != P[u]){
        P[u] = findSet(P[u]);
    }
    return P[u];
}
int makeLink(int x, int y) {
    x = findSet(x), y = findSet(y);
    if(x != y) {
        if(R[x] > R[y])
            R[x] += R[y], P[y] = x;
        else
            R[y] += R[x], P[x] = y;
        return 1;
    }
    return 0;
}
int main(){
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    int t, n, m, x[755], y[755];
    int i, j, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            scanf("%d %d", &x[i], &y[i]);
        init(n);
        scanf("%d", &m);
        int cnt = 0;
        while(m--){
            scanf("%d %d", &a, &b);
            cnt += makeLink(a, b);
        }
        if(cnt == n-1){
            puts("No new highways need");
        } else {
            m = 0;
            for(i = 1; i <= n; i++){
                for(j = i+1; j <= n; j++){
                    E[m].u = i, E[m].v = j;
                    E[m].w = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                    m++;
                }
            }
            sort(E, E+m, cmp);
            for(i = 0; i < m; i++) {
                if(makeLink(E[i].u, E[i].v)) {
                    printf("%d %d\n", E[i].u, E[i].v);
                }
            }
        }
        if(t)puts("");
    }
    return 0;
}
