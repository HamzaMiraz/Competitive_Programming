#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
int fun(int a, int b)
{
    int x,y,k,r,i;
    int c=0;
        k=0;

    while(a!=0 || b!=0)
    {
        x=a%10;
        y=b%10;


        r=x+y+k;
        if(r>9)
        {
            c=c+1;
            k=1;
        }
        if(r<=9)
        {
            k=0;
        }
        a=a/10;
        b=b/10;

    }
    return c;
}


int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int a,b;
    while(scanf("%d%d",&a,&b) ==2)
    {
        if(a==0 && b==0)
        {
            break ;
        }
        else
        {
         int c=fun(a,b);


            if(c==0)
            {
                printf("No carry operation.\n");
            }
            else if(c==1)
            {
                printf("1 carry operation.\n");
            }
            else
            {
                printf("%d carry operations.\n",c);
            }

        }
    }
    return 0;
}
