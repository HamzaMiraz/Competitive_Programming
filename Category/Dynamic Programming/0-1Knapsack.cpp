//#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
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

int val[100];//object's value/profit
int wt[100];//object's waight

int knapSack(int i, int sto) {
   if (sto < 0)
      return INT_MIN;
   if (i < 0 || sto == 0)
      return 0;
   int in = val[i]+knapSack(i-1, sto-wt[i]);
   int ex = knapSack(i-1, sto);
   return max(in, ex);
}

int main() 
{
    
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


   int sto;//number of storage
   int itm;//number of item
   while(cin>>itm>>sto)
   {
        for(int i=0;i<itm;i++)
            cin>>wt[i]>>val[i];
       
       cout << "Knapsack value is " << knapSack(itm - 1, sto);
   }
   return 0;
}
