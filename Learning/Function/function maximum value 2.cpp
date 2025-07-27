/// problem 2
#include <stdio.h>

using namespace std;

int max2(int x, int y)
{
    int m;

    if(x>y)m=x;

    else m=y;

    return m;

}

int max3(int x, int y,int z)
{
     int n,m;
     m=max2(x,y);
     n=max2(m,z);

    return n;

}

int main()
{

    int x,y,z,m;
    while(scanf("%d%d%d",&x,&y,&z) ==3)
    {
        printf("X=%d, Y=%d, Z=%d\n",x,y,z);

        int m=max3(x,y,z);

        printf("The maximum value is %d\n",m);


    }
    return 0;
}
