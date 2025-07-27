#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(1)
    {
        cout<<"how sizes array yo wanna creat by malloc function :"<<endl;
        scanf("%d",&n);
        int *arr;
        //arr=(int*)malloc(n*sizeof(int));///in c
        arr=new int[n];///in c++
        cout<<"incert "<<n<<" element in this array"<<endl;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
