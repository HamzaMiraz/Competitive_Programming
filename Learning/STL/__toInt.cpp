#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
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

void toStr(long long val, char s[]){
    s[0] = val/10 + '0';
    s[1] = val%10 + '0';
    s[2] = 0;
}

LL toInt(char s[]){
    LL res;
    int l;
    l=strlen(s);
    res=0;

    for(int i=0;i<l;i++)
    {
        res = res*10+(s[i]-'0');
    }


    return res;
}

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    LL val;
    char out[100];
    //printf("[%c] -> %d\n", '\0', '\0');
    //strcpy(out, "maksud hossain shibly");

    while(scanf("%s",out) == 1)
    {

       // toStr(val, out);
        //printf("[%s]\n",out);

        LL res = toInt(out);
        printf("%d\n",res);
    }
    return 0;
}
