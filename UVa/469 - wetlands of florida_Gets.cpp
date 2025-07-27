#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
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

const int SIZE = 100;
char in[SIZE][SIZE];
bool flg[SIZE][SIZE];

char que[SIZE];
int dr[]= {-1,-1,-1,0,0,1,1,1};
int dc[]= {-1,0,1,-1,1,-1,0,1};

int N;

int dfs(int r,int c)
{
    if(in[r][c]=='L')   return 0;
    int sum = 1;
    flg[r][c] = false;

    for(int i=0;i<8;i++){
        int vr = r + dr[i];
        int vc = c + dc[i];

        if(vr<0 || vc<0 || N<=vr || N<=vc || flg[vr][vc] == false) continue;
        int cur = dfs(vr, vc);
        sum +=cur;

    }
    return sum;
}


int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
    int tks;
    int ks = 0;

    cin>>tks;
    gets(in[0]);
    gets(in[0]);

    while(tks--){
        if(ks++)  cout<<endl;
        gets(in[0]);
//        deb(in[0]);
        N = strlen(in[0]);

        for(int i=1;i<N;i++)
            gets(in[i]);

        while(gets(que)){
            int len = strlen(que);
            if(len==0)  break;
            int r,c;
            sscanf(que,"%d %d",&r,&c);
            r--;
            c--;
            memset(flg, true,sizeof flg);
            cout<<dfs(r,c)<<endl;
        }
    }

    return 0;
}
/*
1
LLLLLLLLL
LLWWLLWLL
LWWLLLLLL
LWWWLWWLL
LLLWWWLLL
LLLLLLLLL
LLLWWLLWL
LLWLWLLLL
LLLLLLLLL
3 2
7 5
*/



