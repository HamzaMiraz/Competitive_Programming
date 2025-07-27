#include<bits/stdc++.h>
using namespace std;

struct student{
    int roll, marks;
    char name[100];
};

student ar[100];

static bool compare(student a, student b)///first sort by marks
{
    if(a.marks==b.marks)///if two students marks r same then sort by roll
    {
        if(a.roll == b.roll)///if marks and roll bothe r same then sort by name as a dictionary order
        {
            return strcmp(a.name, b.name) < 0;
        }

        return a.roll < b.roll;
    }

    return a.marks>b.marks;
}

int main()
{
    int i,n;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d%d%s",&ar[i].roll,&ar[i].marks,ar[i].name);

        sort(&ar[0],&ar[n], compare);

        for(i=0;i<n;i++)
            printf("%d %d %s\n",ar[i].roll,ar[i].marks,ar[i].name);

    }

    return 0;
}
