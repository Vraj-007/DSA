#include<bits/stdc++.h>
using namespace std;

// Topological Sorting --> Linear ordering of vertices such that if there is an edge between u and v then
//                         u appears before v in the ordering.

bool DFS(int node, vector<vector<int>> &adjL, vector<int> &visited, vector<int> &pathVisited){

    visited[node] = pathVisited[node] = 1;

    for(auto neighbour : adjL[node]){
        if(visited[neighbour] == 0){
            if(DFS(neighbour, adjL, visited, pathVisited) == true){
                return true;
            }
            // If the node has been previously visited
            // but it has to be visited on the same path
            else if(visited[neighbour] == 1 && pathVisited[neighbour] == 1){
                return true;
            }
        }
    }

    pathVisited[node] = 0;
    return false;
}

bool isCycle(vector<vector<int>> &adjL){

    int n = adjL.size();

    vector<int> visited(n, 0);
    vector<int> pathVisited(n, 0);

    for(int i=0 ; i<n ; i++){
        if(visited[i] == 0){
            if(DFS(i, adjL, visited, pathVisited) == true)
                return true;
        }
    }

    return false;
}

int main(){

    vector<vector<int>> adjL{
        {},
        {2},
        {3},
        {4, 7},
        {5},
        {6},
        {},
        {5},
        {9},
        {10},
        {8}
    };

    return 0;
}