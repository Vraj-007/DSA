#include<bits/stdc++.h>
using namespace std;

// Also works for connected components

bool detectCycle(int source, vector<vector<int>> &adjL, vector<int> &visited){

    queue<pair<int, int>> Q; // (node, parent)

    Q.push({source, -1});
    visited[source] = 1;

    while(!Q.empty()){

        int node = Q.front().first;
        int parent = Q.front().second;

        Q.pop();

        for(auto neighbour : adjL[node]){

            if(visited[neighbour] == 0){
                Q.push({neighbour, node});
                visited[neighbour] = 1;
            }
            else if(visited[neighbour] == 1 && neighbour != parent){
                return true;
            }

        }
    }

    return false;
}


bool detect(vector<vector<int>> &adjL){

    vector<int> visited(adjL.size(), 0);

    for(int i=1 ; i<visited.size() ; i++){

        if(visited[i] == 0){    

            if(detectCycle(i, adjL, visited) == true)
                return true;

        }
    }

    return false;
}


int main(){

    // vector<vector<int>> adjL{
    //     {},
    //     {2, 3},
    //     {1, 5},
    //     {1, 4, 6},
    //     {3},
    //     {2, 7},
    //     {3, 7},
    //     {5, 6}
    // };


    // vector<vector<int>> adjL{
    //     {},
    //     {2, 3},
    //     {1, 5},
    //     {1, 4, 6},
    //     {3},
    //     {2, 7},
    //     {3},
    //     {5}
    // };


    vector<vector<int>> adjL{
        {},
        {2, 3},
        {4},
        {1},
        {2},
        {6},
        {7},
        {8, 9},
        {7, 9},
        {7, 8}
    };

    cout<<detect(adjL);

    return 0;
}