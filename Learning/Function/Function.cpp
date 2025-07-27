#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define deb(a)     cout<<#a<<" -> "<<a<<endl;

void fun()
{
    printf("%s: ", __FUNCTION__);
    int n=5;
    for(int i=0;i<n;i++)
        printf("%d, ",i);
    printf("\n");
}

void fun2(int n)    /// Pass by value
{
    printf("%s: ", __FUNCTION__);
    for(int i=0;i<n;i++)
        printf("%d, ",i);
    printf("\n");
    n = 100;
}

void fun3(int &n)   ///Pass by Reference.
{
    printf("%s: ", __FUNCTION__);
    for(int i=0;i<n;i++)
        printf("%d, ",i);
    printf("\n");
    n = 100;
}

double add(double a, double b)
{
    double sum;
    sum  = a +b;
    return sum;
}

int main()
{
    puts("First");

    fun();

    puts("Second");

    int b =  7;
    fun2(b);
    fun2(5);
    deb(b)

    puts("Third");

    b = 10;
    fun3(b);
///    fun3(5); //Error.
    deb(b)

    puts("ADD");
    double sum = add(2.3, 3.00);

    deb(sum);

    puts("End");

    return 0;
}
