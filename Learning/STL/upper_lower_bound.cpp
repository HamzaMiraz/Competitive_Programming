#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=7;
    int ar[10]={10,5,7,99,36,11,6};

   /// vector<int>v(ar,ar+n);
   /// sort(v.begin(),v.end());

    sort(ar,ar+n);/// allaways sort for using lower bound or upper bound function

    for(int i=0;i<n;i++)cout<<ar[i]<<" ";cout<<"\n\n";

    ///lower bound function using for certain element exist in arry or not
    /// if element exist then it returns this elements address
    /// it it not exist then this function return next elements address
    /// which will will gretar then our desired element


    /// if substruct arrays begining address from lower bound address
    ///then we will get index of this address, thats why we substruct &ar[0]

    /// auto it = lower_bound(v.begin(),v.end(),5)-v.begin();///in c++/// vectore must be diclare execly size n
    auto it = lower_bound(ar,ar+n,5)-&ar[0];///ar+0
    cout<<"lower bound of 5 is "<<ar[it]<<endl;
    it = lower_bound(ar,ar+n,6)-ar+0;
    cout<<"lower bound of 6 is "<<ar[it]<<endl;
    it = lower_bound(ar,ar+n,8)-&ar[0];
    cout<<"lower bound of 8 is "<<ar[it]<<endl;
    it = lower_bound(ar,ar+n,12)-&ar[0];
    cout<<"lower bound of 12 is "<<ar[it]<<endl;
    it = lower_bound(ar,ar+n,37)-&ar[0];
    cout<<"lower bound of 37 is "<<ar[it]<<endl;

    it = lower_bound(ar,ar+n,100)-&ar[0];///ar+0
    cout<<"lower bound of 100 is ";if(it==n)cout<<"out of the boundary\n";else cout<< ar[it]<<endl;

    /// upper bound function always returns next elements address
    /// which is immedate greater then our desired element

    it = upper_bound(ar,ar+n,5)-&ar[0];///ar+0
    cout<<"\n\nupper bound of 5 is "<<ar[it]<<endl;
    it = upper_bound(ar,ar+n,8)-&ar[0];///ar+0
    cout<<"upper bound of 8 is "<<ar[it]<<endl;
    it = upper_bound(ar,ar+n,12)-&ar[0];///ar+0
    cout<<"upper bound of 12 is "<<ar[it]<<endl;

    it = upper_bound(ar,ar+n,11)-&ar[0];///ar+0
    cout<<"upper bound of 11 is ";if(it==n)cout<<"out of the boundary\n";else cout<< ar[it]<<endl;

    it = upper_bound(ar,ar+n,99)-&ar[0];///ar+0
    cout<<"upper bound of 99 is ";it==n ? cout<<"out of the boundary\n":cout<< ar[it]<<endl;
    it = upper_bound(ar,ar+n,100)-&ar[0];///ar+0
    cout<<"upper bound of 100 is ";it==n ? cout<<"out of the boundary\n":cout<< ar[it]<<endl;
    
    /// for map,set
    ///mp.lower_bound(x);///for set,map
    ///st.upper_bound(x);///return pointer address

    return 0;
}
