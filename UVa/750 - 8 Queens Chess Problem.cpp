//#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <ctype.h>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <utility>
#include <functional>
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <assert.h>

#include <unordered_set>
#include <unordered_map>

using namespace std;

#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

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



#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define GCD(a,b)  __gcd(a,b)
#define LCM(a,b)  (a*b)/__gcd(a,b)
#define sqr(a)    ((a)*(a))
#define el         "\n"
#define dec(n,x)  fixed << setprecision(x) <<n
typedef long long LL;
LL BIGMOD(LL b,LL power,LL Mod){LL ans = 1;
while(power){if(power & 1)ans = (ans * b) % Mod;
b = (b * b) % Mod;power = power >> 1;}return ans;}

vector<int>primeFactors(int n){vector<int>PRIME;int c=2;while///prime factor
(n>1){if(n%c==0){PRIME.push_back(c);n/=c;}else c++;}return PRIME;}

LL nCr(LL n, LL r){LL res=1;for (LL i=0;i<r;i++){
res *= (n-i);res /= (i+1);}return res;}/// NCR

LL fact(LL n){if(n<=1)return 1;return n*fact(n-1);}
LL nPr(LL n, LL r){return fact(n)/fact(n-r);}///NPR

const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 2e9+10;
const int MOD = 1e9+7;

int n,pc,pr;
vector<vector<string>>boards;
vector<vector<int>>ans;
vector<int>rows;

bool UnderAttack(int row,int col,vector<string>&board){
    int duprow = row;
    int dupcol = col;
    while(row>=1 && col>=1){
        if(board[row][col]=='Q')
            return true;
        --row,--col;
    }
    col = dupcol;
    row = duprow;
    while(row<=n && col<=n){
        if(board[row][col]=='Q')
            return true;
        ++row,++col;
    }
    col = dupcol;
    row = duprow;
    while(row<=n && col>=1){
        if(board[row][col]=='Q')
            return true;
        ++row,--col;
    }
    col = dupcol;
    row = duprow;
    while(row>=1 && col<=n){
        if(board[row][col]=='Q')
            return true;
        --row,++col;
    }
    row = duprow;
    col = dupcol;
    while(col>=1){
        if(board[row][col]=='Q')
            return true;
        --col;
    }
    row = duprow;
    col = dupcol;
    while(col<=n){
        if(board[row][col]=='Q')
            return true;
        ++col;
    }
    return false;
}

void res(int col,vector<string>&board){
    if(col==pc){
        rows.push_back(pr);
        res(col+1,board);
        rows.pop_back();
    }
    if(col==n+1){
        boards.push_back(board);
        ans.push_back(rows);
        return;
    }
    for(int row=1;row<=n;row++){
        if(UnderAttack(row,col,board))
            continue;
        board[row][col]='Q';
        rows.push_back(row);
        res(col+1,board);
        board[row][col]='.';
        rows.pop_back();
    }
}
int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a .
//    freopen("out.txt", "w", stdout);  ///To write  a file.
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        cin>>pr>>pc;
        n=8;
        vector<string>board(n+1,string(n+1,'.'));
        board[pr][pc]='Q';
        res(1,board);
        cout<<"SOLN       COLUMN\n";
        cout<<" #      1 2 3 4 5 6 7 8\n\n";
         int k=1;
        for(auto it : ans){
            printf("%2d     ",k);
            for(auto i : it){
                cout<<" "<<i;
            }
            k++;cout<<"\n";
        }
        if(t!=0)cout<<"\n";

        rows.clear();ans.clear();
        board.clear(),boards.clear();
    }
    return 0;
}
