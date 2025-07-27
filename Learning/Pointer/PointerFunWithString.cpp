
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl

int main()
{
    int len;
    char in[100];

    scanf("%s", in);  ///    scanf("%s", &in[0]);
    len = strlen(in);
    deb(len);

    puts(in);

    scanf("%s", in[10]);

    len = strlen(in[10]);

    deb(len);

    puts(&in[10]);

    return 0;
}
