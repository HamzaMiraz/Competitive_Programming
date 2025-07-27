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
typedef long long LL;
const double PI = acos(-1);
const double EPS = 1e-7; ///1*10^-7
const int oo = 2e9+10;



int target;
set<vector<int>>ds;
///unique sets of combination sum
void fun(vector<int>&v,vector<int>&arr,int idx,int sum,int n){
    if(sum>target)return;
    if(idx==n){
        if(sum==target){
            ds.insert(v);
        }
        return;
    }
    ///take element
    sum+=arr[idx];
    v.push_back(arr[idx]);
    fun(v,arr,idx+1,sum,n);///not take arr[idx] one more time
    ///not take element
    sum-=arr[idx];
    v.pop_back();
    fun(v,arr,idx+1,sum,n);
}


int main()
{

    vector<int>arr={10,1,2,7,6,1,5};
    sort(arr.begin(),arr.end());/// if we not sort when we can see
                            /// 7 1 and 1 7 thare r not same
                        ///then we can't get unique sets of combination sum
    int n=7;///array size
    target=8;
    vector<int>v;
    fun(v,arr,0,0,n);
    if(ds.size()){
        cout<<"Numbar of ways:"<<ds.size()<<"\n";
    }
    else{
        cout<<"impossible\n";
    }
    /// print all combination results
    for(auto st : ds){
        for(auto i: st){
            cout<<i<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
