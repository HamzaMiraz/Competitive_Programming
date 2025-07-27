#include <stdio.h>
    int max2 (int x , int y )
    {
        int m;
        if (x>y)m=x;

        else m=y;

        return m;
    }
    int max3(int x ,int y , int z) {
        int m;
        m=max2(x,y);
        m=max2(m,z);
        return m;
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
