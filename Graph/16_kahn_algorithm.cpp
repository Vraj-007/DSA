#include<bits/stdc++.h>
using namespace std;

vector<int> kahn_Algo(vector<vector<int>> &adjL){

    int n = adjL.size();

    vector<int> visited(n, 0);
    queue<int> Q;
    vector<int> Indegree(n, 0);
}

int main(){

    vector<vector<int>> adjL{
        {},
        {},
        {3},
        {1},
        {0,1},
        {0,2}
    };

    vector<int> List = kahn_Algo(adjL);

    for(auto node : List){
        cout<<node<<" ";
    }

    return 0;
}