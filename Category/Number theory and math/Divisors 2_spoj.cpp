#include<bits/stdc++.h>
using namespace std;

/// divisor pre calculate
///nlog(log(n))
int divisors[1000010];
void Divisor_cnt()
{
    for(int div=1;div<=1000000;div++)
        for(int num=div;num<=1000000;num+=div)///num is a number
            divisors[num]++;     //which is contain divisor div
}
vector<int>ans;
bool flg[1000006];
void chack(){
    fill(flg,flg+1000005,true);
    for(int m=1;m<=1000000;m++)
        for(int n=m;n<=1000000;n+=m){
            if(divisors[n]%divisors[m]!=0){
                flg[n]=false;
            }
        }
    for(int i=1;i<=1000000;i++){
        if(flg[i] && divisors[i]>3){
            ans.push_back(i);
        }
    }

}
int main()
{
    Divisor_cnt();
    chack();
    for(int i=107;i<ans.size();i+=108){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
