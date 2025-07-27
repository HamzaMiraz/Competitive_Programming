#include<bits/stdc++.h>
using namespace std;

int main(){
    multiset<int>st;
    st.insert(10);
    st.insert(7);
    st.insert(8);
    st.insert(10);
    st.insert(8);
    st.insert(6);
    st.insert(2);
    st.insert(10);
    st.insert(9);
    st.insert(8);
    st.emplace(10);
    for(auto it:st){
        cout<<it<<" ";
    }cout<<endl;

    cout<<st.count(10)<<endl;///count number of 10 in the set

    st.erase(st.find(10));///delete first 10;
    for(auto it:st){
        cout<<it<<" ";
    }cout<<endl;

    st.erase(st.find(2),st.find(8));///delete among  2 to 8-1 all elements
    for(auto it:st){
        cout<<it<<" ";
    }cout<<endl;

    st.erase(10);///delete all 10
    for(auto it:st){
        cout<<it<<" ";
    }cout<<endl;

    return 0;
}

