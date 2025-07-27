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
string str[1000];
int e,w,h;
#define even 0;
#define odd 1;
int memo[100][100],c;

int go(int W,int H){

    if(str[W][H]=even)++c
    if(c==e)return c;
    int &rf=memo[W][H];
    if(rf!=-1)return rf;
    rf=0;




}


int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    while(scanf("%d%d",&w,&h) == 2)
    {
        memset(memo,-1,sizeof memo);
        int cnt=0;
        for(int i=0;i<h;i++){
            cin>>str[i];
        }
         for(int i=0;i<h;i++)
         {
            for(int j=0;j<w;j++)
            {
                int x=str[i][j]-'0';
                if(x%2==0){
                    ++cnt;
                    str[i][j]=even;
                }
            }

        }
        cnt=e;
        c=0;
    }
    return 0;
}
