#include<bits/stdc++.h>

using namespace std;

vector<int>graph[100];
int color[100];
int E,V,m;
bool issafe(int node,int col){
    int v;
    for(int i=0;i<graph[node].size();i++){
        v=graph[node][i];
        if(color[v]==col)return false;
    }
    return true;
}
bool solve(int node){
    if(node==V+1)return true;

    for(int col=1;col<=m;col++){
        if(issafe(node,col)){
            color[node]=col;
            if(solve(node+1)==true)return true;
            color[node]=0;
        }
    }
    return false;

}
int main()
{
//   freopen("in.txt", "r", stdin);  ///To read from a file.
//    freopen("out.txt", "w", stdout);  ///To write  a file.
//    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin>>V>>E>>m)
    {
        for(int i=0;i<V+5;i++){
            color[i]=0;
            graph[i].clear();
        }
        int u,v;
        for(int i=0;i<E;i++){

            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if(solve(1)){
            cout<<"YES\n";
                for(int i=1;i<=V;i++){
                cout<<color[i]<<" ";
            }
            cout<<"\n";
        }
        else{
            cout<<"NO\n";
        }

    }
    return 0;
}

