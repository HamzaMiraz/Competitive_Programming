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
int fun(vector<int>&v,int arr[],int idx,int sum,int n){
    if(sum>target)return 0;
    if(idx==n){
        if(sum==target){
            if(v.size()==0)cout<<"{}";
            for(auto i: v)cout<<i<<" ";
            cout<<endl;
            return 1;
        }
        return 0;
    }
    ///take element
    sum+=arr[idx];
    v.push_back(arr[idx]);
    int a=fun(v,arr,idx,sum,n);///can take arr[idx] one more time
    //int a=fun(v,arr,idx+1,sum,n);///not take arr[idx] one more time
    ///not take element
    sum-=arr[idx];
    v.pop_back();
    int b=fun(v,arr,idx+1,sum,n);

    return a+b;
}


int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int arr[8]={10,1,2,7,6,1,5};
    int n=7;///array size
    target=8;
    vector<int>v;
    int ans=fun(v,arr,0,0,n);
    if(ans){
        cout<<"Numbar of ways:"<<ans<<"\n";
    }
    else{
        cout<<"impossible\n";
    }

    return 0;
}
