#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int node, int parent, vector<vector<int>> &adjL, vector<int> &visited){

    visited[node] = 1;      // Marking unvisited node as visited

    for(auto neighbour : adjL[node]){

        if(visited[neighbour] == 0){
            if(detectCycle(neighbour, node, adjL, visited) == true)
                return true;
        }
        else if(visited[neighbour] == 1 && neighbour != parent){
            return true;
        }
    }

    return false;
}

bool detect(vector<vector<int>> &adjL){

    vector<int> visited(adjL.size(), 0);
    visited[0] = 1;

    for(int i=1 ; i<visited.size() ; i++){

        if(visited[i] == 0){
            if(detectCycle(i, -1, adjL, visited) == true)
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