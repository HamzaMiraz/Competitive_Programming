#include<bits/stdc++.h>
using namespace std;


const int SIZE=110;

int matrix[SIZE][SIZE];

int main()
{
    int V,E,i,j,u,v;
    while(scanf("%d%d",&V,&E)==2)
    {
        for(i=0;i<V+5;i++)
            for(j=0;j<V+5;j++)
                matrix[i][j]=0;

        for(i=0;i<E;i++)
        {
            scanf("%d%d",&u,&v);
            matrix[u][v]=1;
            matrix[v][u]=1;
        }

        for(i=1;i<=V;i++)
        {
            printf("%d -> ",i);

            bool flag=true;
            for(j=1;j<=V;j++)
            {
                if(matrix[i][j]==1)
                {
                    if(flag)
                        printf("%d",j);
                    else
                        printf(", %d",j);
                    flag=false;
                }
            }
            printf("\n");

        }
        printf("\n");
    }

    return 0;
}

/**
8 6
1 2
1 3
3 4
4 5
6 7
7 8
*/
