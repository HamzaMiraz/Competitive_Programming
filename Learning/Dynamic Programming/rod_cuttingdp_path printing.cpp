#include<bits/stdc++.h>
using namespace std;


const int N = 100000;
int n,m;
int p[N];
int path[N];
int memo[1000];
int cut_rod(int n) {
    if (n == 0) return 0;
    if (n < 0) return -9999;
    if(memo[n]!=-1)return memo[n];
    memo[n] = -9999;
    for (int i = 1; i <= m; i++) {
        int res = p[i] + cut_rod(n - i);
        if (memo[n] < res) {
            memo[n] = res;
            path[n] = i;
        }
    }
    return memo[n];
}
int main() {
    cin >> n>>m;
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }
    memset(memo, -1, sizeof memo);
    int max_value = cut_rod(n);
    cout << "The maximum value " << max_value << endl;

    cout << "The best path -: ";
    while (n > 0) {
        cout << p[path[n]] << " ";
        n -= path[n];
    }
    cout << endl;


    return 0;
}
