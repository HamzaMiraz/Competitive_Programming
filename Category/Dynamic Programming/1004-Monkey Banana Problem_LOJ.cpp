#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
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
int arr[205][205];
int memo[205][205],n;
int go(int p,int q){
    if(p==2*n-2 && q==n-1)return 0;

    int &rf=memo[p][q];
    if(rf!=-1)return rf;
    rf=0;
    if(p<2*n-1 && q<n){
        rf=max(rf,go(p+1,q)+arr[p][q]);
        if(p<n-1)
            rf=max(rf,go(p+1,q+1)+arr[p][q]);
        else{
            if(q>0)
                rf=max(rf,go(p+1,q-1)+arr[p][q]);
        }
    }

    return rf;

}

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int t;
    cin>>t;
    for(int ts=1;ts<=t;++ts)
    {
        cin>>n;
        memset(arr,0,sizeof arr);
        memset(memo,-1,sizeof memo);
        for(int i =0;i<2*n-1;i++){
            if(i<n){
                for(int j=0;j<=i;j++){
                    cin>>arr[i][j];
                }
            }
            else{
                for(int j=0;j<2*n-1-i;j++){
                    cin>>arr[i][j];
                }
            }
        }
        cout<<"Case "<<ts<<": "<<go(0,0)<<endl;
    }
    return 0;
}
