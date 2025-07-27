#include<bits/stdc++.h>
using namespace std;

char Text[1000101];
char Pattern[1000101];
int Prefix[1000101];
int cnt;

void Compute_Prefix_Function(int m)///j....i,prefix matching j to i
{
    int i,j;
    j = 0;
    Prefix[0]=0;
    for(i=1;i<m;i++)
    {
        while((j>0) && (Pattern[j] != Pattern[i]))
            j = Prefix[j-1];

        if(Pattern[j] == Pattern[i])
            j = j + 1;

        Prefix[i]=j;
    }
}

void KMP(int m,int n)
{
    int i,j;
    j = 0;
    for(i=0;i<n;i++)
    {
        while((j>0) && (Pattern[j] != Text[i]))
            j = Prefix[j-1];

        if(Pattern[j]==Text[i])
        {
            j = j + 1;
            if(j==m)
            {
                ++cnt;
                j = Prefix[j-1];
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int m,n,t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        scanf("%s%s",Text,Pattern);
        cnt=0;
        n = strlen(Text);
        m = strlen(Pattern);
        Compute_Prefix_Function(m);
        KMP(m,n);
        printf("Case %d: %d\n",i,cnt);
    }

    return 0;
}
