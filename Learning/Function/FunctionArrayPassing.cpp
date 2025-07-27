#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

#define deb(a)     cout<<#a<<" -> "<<a<<endl;

void initialize(int buf[], int n)   /// Array is always PASS BY REFERENCE.
{
    for(int i=0;i<n;i++)
        buf[i] = -1;

    n = 5;
}

int strlen(char p[])
{
    int len = 0;

    while(p[len]){
        len++;
    }
    return len;
}

char gc;

int sum(int ar[][10][15], int d1, int d2, int d3)   ///Need to mention size of all the dimentions of array, but we can ignore the size of first dimention.
{
    int sum = 0;
    for(int i=0;i<d1; i++)
        for(int j=0;j<d2;j++)
            for(int k = 0;k <d3;k++)
            {
//                printf("%d %d %d # val = %d\n", i, j, k, ar[i][j][k]);
//                scanf("%c",&gc);
                sum += ar[i][j][k];
            }

    return sum;
}

///int mat[5][10][15];      //Initially all the element's value is ZERO for global variables.

int main()
{
//    int ar[] = {1, 2, 3, 4, 5};

    int ar[10];
    int n = 10;
    int mat[5][10][15];


    initialize(ar, n);

    for(int i=0;i<n;i++)
        printf("i:%d  => %d\n", i, ar[i]);

    char name[100];
    strcpy(name, "Maksud");
    int len = strlen(name);
    deb(len);

    int val = sum(mat, 5, 10, 15);
    deb(val)

    return 0;
}
