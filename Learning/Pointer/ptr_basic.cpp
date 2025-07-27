#include<bits/stdc++.h>
using namespace std;
int main(){
    int x=20,y=30;
    int* a;
    int* b;
    cout<<a<<" "<<b<<endl;
    a=&x;
    b=&y;
    cout<<a<<" "<<b<<endl;
    cout<<*a<<" "<<*b<<endl;
    a=b;
    cout<<*a<<" "<<*b<<endl;
    return 0;
}
