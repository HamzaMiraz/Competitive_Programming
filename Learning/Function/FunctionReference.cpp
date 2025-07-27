#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define deb(a)     cout<<#a<<" -> "<<a<<endl;


void fun(int n)    /// Pass by value
{
    printf("%s: N: %d\n", __FUNCTION__, n);
    n = 100;
    printf("%s: N: %d\n", __FUNCTION__, n);
}

void funRef(int &n, int m)   ///Pass by Reference.
{
    printf("%s: N: %d M: %d\n", __FUNCTION__, n, m);
    n = 100;
    printf("%s: N: %d M: %d\n", __FUNCTION__, n, m);
}


int main()
{
    int b =  7;

    fun(b);
    deb(b);

    fun(5);

    puts("Reference\n\n");

    b = 10;
    funRef(b, 3);
///    funRef(5); //Error.
    deb(b)

    return 0;
}
