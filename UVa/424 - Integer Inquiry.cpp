#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <map>
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

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    string s;
	int Sum[201] = {0}, i, j, length;
    while(cin>>s)
    {

        if(s == "0")break;

        length = s.length();

		for(i = 0, j = length-1; i < length; i++, j--)
			Sum[i] += s[j] - '0';
    }
    for(i = 0; i < 200; i++)
		if(Sum[i] >= 10) {
			Sum[i+1] += Sum[i]/10;
			Sum[i] %= 10;
		}
	i = 200;
	while(Sum[i] == 0 && i >= 0)i--;

	if(i == -1)	printf("0");

	for(; i >= 0; i--) {
		printf("%d", Sum[i]);
	}
	puts("");

    return 0;
}
