#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 11
using namespace std;

bool used[N];
int len;
char now[N], str[N];
void backtracking(int n)
{
    int i;
    if (n == len)
    {
        now[n] = '\0';
        puts(now);
    }
    else
    {
        char last = '\0';
        for (i = 0; i < len; i++)
        {
            if (used[i]==false)
            {
                used[i] = true;
                now[n] = str[i];
                last = str[i];

                backtracking(n + 1);

                used[i] = false;
            }
        }
    }
}

int main()
{
//    freopen("1.in", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
    int Case;
    scanf("%d", &Case);

    while (Case--)
    {
        scanf("%s",str);
        len = strlen(str);
        fill(used, used + len, false);
        sort(str, str + len);

        backtracking(0);
        printf("\n");
    }

    return 0;
}
