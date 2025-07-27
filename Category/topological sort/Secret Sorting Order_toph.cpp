#include<bits/stdc++.h>
using namespace std;

const int Size=105;
vector<int>adj[Size];
vector<int>TS;///Topological Sort
int indegree[Size],V,E;
queue<int>Q;

void init(){
    for(int i=0;i<25+5;i++){
        indegree[i]=0;
        adj[i].clear();
    }
    TS.clear();
}
void topo_BFS(){
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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>E;
        init();int u,v;
        cin.ignore();
        vector<string>vs(E+3);
        map<char,int>mp;
        char ch[50];
        int mrk=0;
        for(int i=0;i<E;i++){
            cin>>vs[i];
            //cout<<vs[i]<<"\n";
            for(int j=0;j<vs[i].size();j++){
                if(!mp[vs[i][j]]){
                    mp[vs[i][j]]=++mrk;
                    ch[mrk]=vs[i][j];
                 }
            }

        }
        for(int i=0;i<E-1;i++){
            for(int j=0;j<min(vs[i].size(),vs[i+1].size());j++){
                if(vs[i][j]!=vs[i+1][j]){
                    u=mp[vs[i][j]];
                    v=mp[vs[i+1][j]];
                    adj[u].emplace_back(v);
                    ++indegree[v];
                    break;
                }
            }
            
        }
        for(int i=1;i<=mrk;i++){///1 based
            if(indegree[i]==0){
                TS.emplace_back(i);
                Q.push(i);
            }
        }
        topo_BFS();
        for(int i=0;i<TS.size();i++){
            cout<<ch[TS[i]];
            if(i<TS.size()-1)cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
