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
const double PI = acos(-1);

bool used[12];
int len;
char sto[12], str[12];
void backtracking(int d)
{
    int i;
    if (d == len)
    {
        for(i=0;i<len;i++)
        {
            printf("%c",sto[i]);
        }
        printf("\n");
    }
    else
    {
        for (i = 0; i < len; i++)
        {
            if (used[i]==false)
            {
                used[i] = true;
                sto[d] = str[i];
                backtracking(d + 1);
                used[i] = false;
            }
        }
    }
}

int main()
{
//freopen("1.in", "r", stdin);  ///To read from a file.
//freopen("out.txt", "w", stdout);  ///To write  a file.
    int Case;
    scanf("%d",&Case);

    while(Case--)
    {
        scanf("%s",str);
        len = strlen(str);
        sort(&str[0], &str[len]);
        memset(used, false, sizeof used);
        backtracking(0);
        printf("\n");
    }

    return 0;
}
