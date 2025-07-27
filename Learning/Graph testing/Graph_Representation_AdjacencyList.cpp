#include<bits/stdc++.h>
using namespace std;


const int SIZE=110;

vector<int>graph[SIZE];

int main()
{
    int V,E,i,j,u,v;
    while(scanf("%d%d",&V,&E)==2)
    {
        for(i=0;i<V+5;i++)
            graph[i].clear();

        for(i=0;i<E;i++)
        {
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(i=1;i<=V;i++)
        {
            printf("%d -> ",i);
            int sz=graph[i].size();
            for(j=0;j<sz;j++)
            {
                if(j==0)
                    printf("%d",graph[i][j]);
                else
                    printf(", %d",graph[i][j]);
            }
            printf("\n");
        }
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

