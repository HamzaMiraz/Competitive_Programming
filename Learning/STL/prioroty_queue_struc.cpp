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

// #include <bits/stdc++.h>
using namespace std;


#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define PrintConP(mp)    {cout<<#mp<<" #=> ";for(auto &it: mp){cout<<it.first<<":"<<it.second<<", ";} cout<<endl;}
#define PrintCon(mp)    {cout<<#mp<<" #=> ";for(auto &it: mp){cout<<it<<", ";} cout<<endl;}
#define deb(a)      cout<<__LINE__<<"#-> "<<#a<<"  "<<a<<endl

#define debug(a...)          {cout<<" #--> ";dbg,a; cout<<endl;}
struct debugger
{
    ///Collected from rudradevbasak
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;


struct Nod{
    int u, dis;

    Nod(int iU, int iDis){
        u = iU;
        dis = iDis;
    }

    bool operator<(const Nod& b) const{

        return dis > b.dis;
    }
};


int main()
{
    // freopen("0.in","r",stdin);
    // freopen("out.out","w",stdout);
    // ios::sync_with_stdio(false);cin.tie(0);
///priority_queue<int ,vector<int>,greater<int>>pq;///acending order
   priority_queue<Nod>pq;

   pq.push(Nod{5,6});//    Nod(int iU, int iDis){
   pq.push({4,7});   //        u = iU;
   pq.push(Nod(3,6));//        dis = iDis;}
   pq.push(Nod(10,5));
   pq.push(Nod(10,8));
   while(!pq.empty()){
        Nod f= pq.top();

        cout<<f.u<<" "<<f.dis<<endl;///reverce priority queue becouse
                                    ///bool oparator return dis > b.dis;
        pq.pop();

   }

    return 0;
}
