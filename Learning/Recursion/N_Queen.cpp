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

int n;
vector<vector<string>>boards;

bool UnderAttack(int row,int col,vector<string>&board){
    int duprow = row;
    int dupcol = col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q')
            return true;
        --row,--col;
    }
    col = dupcol;
    row = duprow;
    while(row<n && col>=0){
        if(board[row][col]=='Q')
            return true;
        ++row,--col;
    }
    row = duprow;
    col = dupcol;
    while(col>=0){
        if(board[row][col]=='Q')
            return true;
        --col;
    }
    return false;
}

void res(int col,vector<string>&board){
    if(col==n){
        boards.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(UnderAttack(row,col,board))
            continue;
        board[row][col]='Q';
        res(col+1,board);
        board[row][col]='.';
    }
}
int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a .
//    freopen("out.txt", "w", stdout);  ///To write  a file.
//    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin>>n)
    {
        vector<string>board(n,string(n,'.'));
        res(0,board);
        int w=0;
        for(auto ans : boards){
            cout<<"Possible Way :"<<++w<<el;
            for(auto r : ans){
                cout<<r<<el;
            }
            cout<<el;
        }
        board.clear(),boards.clear();
    }
    return 0;
}
