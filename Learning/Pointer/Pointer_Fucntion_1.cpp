#include<stdio.h>
#include<stdlib.h>


void func(int *A)///A[]
{
    int i;
    for(i=0;i<5;i++)
        printf("func -> %d ",A[i]);
    printf("\n\n");
}

void func1(char *str)///str[]
{
    printf("func1 -> %s\n\n",str);
}

int* func2(int n)
{
    int *p;
    p = (int *)malloc(sizeof(int)*n);
    return (p);
}

int* func3()
{
    int i;
    static int ar[]={1,2,3,4,5,6};
    return ar;
}

char* func4()
{
    char str[]="Codeforces";
    return str;
}

char* func5()
{
    static char str[]="Codeforces";
    return str;
}

int* func6()
{
    static  int arr[100];
    return arr;
}

int* func7(int A[])     ///*A also works
{
    int i;
    for(i=0;i<5;i++)
        A[i]+=12345;
    return A;
}


int main()
{
    int ar[]={2,4,5,6,8};
    func(ar);
        for(int i=0;i<5;i++)
        printf("%d ",ar[i]);
    printf("\n\n");

    char str[] = "Naim Elias";
    func1(str);


    int *A,i;
    A = func2(5);
    for(i=0;i<5;i++)
        A[i]=100+i*i;
    printf("func2 -> ");
    for(i=0;i<5;i++)
        printf("%d ",A[i]);
    printf("\n\n");


    int *Ar;
    Ar = func3();
    printf("func3 -> ");
    for(i=0;i<6;i++)
        printf("%d ",Ar[i]);
    printf("\n\n");


    char *S;
    S = func4();
    printf("func4 -> %s\n\n",S);


    S = func5();
    printf("func5 -> %s\n\n",S);


    Ar = func6();
    for(i=0;i<15;i++)
        Ar[i]=1e5+i;
    printf("func6 -> ");
    for(i=0;i<15;i++)
        printf("%d ",Ar[i]);
    printf("\n\n");


    Ar = func7(ar);///inatialize befor ar[]={2,4,5,6,8};
    printf("func7 -> ");
    for(i=0;i<5;i++)
        printf("%d ",Ar[i]);
    printf("\n\n");

    return 0;
}
