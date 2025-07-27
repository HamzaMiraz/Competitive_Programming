#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define deb(a)     cout<<#a<<" -> "<<a<<endl;

int main()
{
//    freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int i,j,a,b,n;
    scanf("%d",&n);

    for(j=1;j<=n;j++)
    {
        int sum=0;
        scanf("%d%d",&a,&b);
        for(i=a;i<=b;i=i+2)
        {
            if(i%2==0)
            {
                i++;
            }
            sum=sum+i;
        }
        printf("Case %d: %d\n",j,sum);
    }
    return 0;
}
