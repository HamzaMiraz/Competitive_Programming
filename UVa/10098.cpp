#include<bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("1.in", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    char a[11];
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",a);
        int len = strlen(a);
        sort(a,a+len);
        do
        {
            printf("%s\n",a);
        }while(next_permutation(a,a+len)); //next_permutation(); is an STL.
        printf("\n");
    }
    return 0;
}
