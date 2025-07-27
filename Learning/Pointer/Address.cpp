#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

void addressOfArray()
{
    int n = 10;
    int ar[n];
    int *p = ar;

    printf("Size of integer: %d\n", sizeof(int));
    printf("Size of Array ar: %d\n", sizeof(ar));

    puts("\naddressOfArray");
    for(int i=0;i<n;i++)
    {
        printf("\ti: %d -> %X %x # %X\n", i, &ar[i], &ar[i], p);
        ++p;    ///Pointer variable p is increased by 4, since size of integer is 4.
    }
    printf("Array: %X  %X\n", ar, &ar[0]);
}

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.

    int a;
    int* p; ///Pointer Variable

    a = 50;
    p = &a;

    printf("P: %X  &A: %X\n", p, &a);

    int b = *p;

    deb(b);
    deb(&b);

    *p = 100;

    deb(a);

    addressOfArray();

    double x;
    double *px = &x;

    return 0;
}
