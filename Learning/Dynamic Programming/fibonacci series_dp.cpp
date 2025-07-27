//Fibonacci Series using Recursion
#include<bits/stdc++.h>
using namespace std;
int memo[10000];
int fib(int n)
{
    if (n <= 1)
        return n;

    int &rf = memo[n];
    if(rf>-1)return rf;

    return rf = fib(n-1) + fib(n-2);
}

int main ()
{
    int n;
    cin>>n;
    memset(memo , -1 , sizeof memo);
    for(int i=0;i<n;i++)
    cout <<fib(i)<<" ";
    getchar();
    return 0;
}
