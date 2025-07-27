#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

void fun(int* p)
{
    *p = 100;
}

int main()
{
    int len = 5;

    fun(&len);

    deb(len);

    int &b = len;
    deb(b);

    printf("Address:%X %X\n", &b, &len);

    b = -55;

    deb(b);
    deb(len);

    return 0;
}
