#include<stdio.h>


int main()
{
    int v = 10;
    ///refrance
    int &r = v;     ///assign in declaration
    ///v s other name is r

//    &r = v;     //not working

    printf("v = %d\n",v);
    printf("r = %d\n",r);

    r++;
    printf("\nv = %d\n",&v);
    printf("r = %d\n",&r);

    v = 15;
    printf("\nv = %d\n",v);
    printf("r = %d\n",r);

    return 0;
}
