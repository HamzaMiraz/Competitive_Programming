#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > input(){
    vector< vector<int> > arr;

    for(int i=0; i<6; i++){
        vector<int> row;

        for(int i=0; i<6; i++){
            int d;
            cin >> d;
            row.push_back(d);
        }
        arr.push_back(row);
    }
    cout<< arr[1][2] << "\n";
    return arr;
}


int solve(vector< vector<int> > arr){
    int mx = -1000000;

    return mx;
}

int main()
{
    vector< vector<int> > arr = input();

    cout << solve(arr) << "\n";

    return 0;
}
/*
1 2 3 5 3 1
3 4 65 4 2 4
8 7 6 5 6 7
9 0 43 2 1 4
4 5 6 1 2 6
56 3 1 6 90 4
*/
