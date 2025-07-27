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
vector<vector<int>>ds;
void fun(vector<int>&v,vector<int>&arr,int sum,int n){
    if(sum>target)return;

    if(sum==target){
        ds.emplace_back(v);
        return;
    }



    for(int i=0;i<n;i++){
        sum+=arr[i];
        v.push_back(arr[i]);

        fun(v,arr,sum,n);

        sum-=arr[i];
        v.pop_back();
    }
}


int main()
{

    vector<int>arr={1,2,3,4};

    int n=4;///array size
    target=5;
    vector<int>v;
    fun(v,arr,0,n);

    /// print all combination results
    for(auto vec : ds){
        for(auto i: vec){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    if(ds.size()){
        cout<<"Numbar of ways:"<<ds.size()<<"\n";
    }
    else{
        cout<<"impossible\n";
    }

    return 0;
}
