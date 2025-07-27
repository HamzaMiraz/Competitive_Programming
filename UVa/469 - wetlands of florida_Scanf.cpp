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
//    debug(r,c);
//    deb(N);
    if(in[r][c]=='L')   return 0;
    int sum = 1;
    flg[r][c] = false;

    for(int i=0;i<8;i++){
        int vr = r + dr[i];
        int vc = c + dc[i];

        if(vr<0 || vc<0 || N<=vr || N<=vc || flg[vr][vc] == false) continue;
        int cur = dfs(vr, vc);
        sum +=cur;
//        debug(r, c, sum, cur);
    }
//    debug(r, c, sum);
    return sum;
}


int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
    int tks, r, c, ks =0;

    cin>>tks;


    while(tks--)
    {
        if(ks==0){
            cin>>in[0];
            ks++;
        }else {
            cout<<endl;
            strcpy(in[0], que);
        }

        N = strlen(in[0]);
        for(int i=1;i<N;i++)
            cin>>in[i];

        while(cin>>que && isdigit(que[0]))
        {
            r = atoi(que);
            cin>>c;
            r--;
            c--;
//            debug(r,c);
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



