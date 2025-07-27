#include<bits/stdc++.h>
using namespace std;

///Path With Minimum Effort gfg

///this code not solution this code create for
///learning recurssion

int n,m;
int g[100][100];
vector<int>eff;
vector<int>path;
vector<vector<int>>ds;
vector<vector<int>>routes;
/// efforts means distance of nightbor nodes
void go(int i,int j){

    if(i==n && j==m){
        ds.push_back(eff);
        path.push_back(g[i][j]);

        routes.push_back(path);
        path.pop_back();
    }
    if(i<n){
        eff.push_back(abs(g[i+1][j]-g[i][j]));
        path.push_back(g[i][j]);

        go(i+1,j);

        eff.pop_back();
        path.pop_back();
    }
    if(j<m){
        eff.push_back(abs(g[i][j+1]-g[i][j]));///effort
        path.push_back(g[i][j]);

        go(i,j+1);

        eff.pop_back();
        path.pop_back();
    }
}

int main()
{
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>g[i][j];
            }
        }
        go(1,1);

        cout<<"\nRoute Efforts\n";
        for(int i=0;i<ds.size();i++){
            for(int j=0;j<ds[i].size();j++){
                cout<<ds[i][j]<< " ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        cout<<"\nRoute paths\n";
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                cout<<routes[i][j]<< " ";
            }
            cout<<"\n";
        }
        cout<<"\n";

        ds.clear();
        routes.clear();
        eff.clear();
        path.clear();

    }
    return 0;
}
/**
Path With Minimum Effort gfg

3 3
1 2 2
3 8 2
5 3 5
**/

