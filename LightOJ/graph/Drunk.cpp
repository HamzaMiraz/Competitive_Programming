#include<bits/stdc++.h>
using namespace std;

const int Size=100006;
vector<int>adj[Size];
vector<int>TS;///Topological Sort
int indegree[Size],V,E;
queue<int>Q;
int ks;
void init(){
    for(int i=0;i<V+5;i++){
        indegree[i]=0;
        adj[i].clear();
    }
    TS.clear();
}
void BFS(){
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(auto v : adj[u]){
            --indegree[v];
            if(indegree[v]==0){
                TS.emplace_back(v);
                Q.push(v);
            }
        }
    }
}
int main(){
    int t,n;cin>>t;
    V=10006;
    while(t--){
        cin>>n;E=n;
        init();int u,v;string x,y;
        cin.ignore();
        map<string,int>mp;int mrk=1;
        for(int i=0;i<E;i++){
            cin>>x>>y;
            if(!mp[x])mp[x]=mrk++;
            if(!mp[y])mp[y]=mrk++;
            u=mp[x];
            v=mp[y];
            adj[u].emplace_back(v);
            ++indegree[v];
        }
        for(int i=1;i<mrk;i++){///1 based
            if(indegree[i]==0){
                TS.emplace_back(i);
                Q.push(i);
            }
        }
        BFS();
        if(TS.size()!=mrk-1){
            cout<<"Case "<<++ks<<": No\n";
        }
        else{
            cout<<"Case "<<++ks<<": Yes\n";
        }
    }
    return 0;
}
