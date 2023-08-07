#include<bits/stdc++.h>
using namespace std;

// color the graph with 2 colors such that no adjacent nodes have same color ---> Bipartite Graph

// Linear Graphs with no cycle are always Bipartite

// Any cyclic graph with even cycle length are always Bipartite

// Any cyclic graph with odd cycle length can never be Bipartite

bool isBipartite(vector<vector<int>> &adjL){

    int n = adjL.size();
    int m = adjL[0].size();

    vector<int> visited(n, 0);
    vector<int> color(n, -1);
    queue<int> Q;

    Q.push(1);
    visited[1] = 1;
    color[1] = 0;

    while(!Q.empty()){

        int node = Q.front();
        Q.pop();

        for(auto neighbour : adjL[node]){

            if(visited[neighbour] == 0 && color[neighbour] == -1){
                if(color[node] == 1)
                    color[neighbour] = 0;
                else
                    color[neighbour] = 1;

                Q.push(neighbour);
                visited[neighbour] = 1;
            }
            else if(visited[neighbour] == 1 && color[neighbour] != -1){
                if(color[node] == color[neighbour])
                    return false;
            }
            
        }

    }

    return true;
}


int main(){

    // vector<vector<int>> adjL{
    //     {},
    //     {2},
    //     {1, 3, 6},
    //     {2, 4},
    //     {3, 5, 7},
    //     {4, 6},
    //     {2, 5},
    //     {4, 8},
    //     {7}
    // };


    vector<vector<int>> adjL{
        {},
        {2},
        {1, 3, 5},
        {2, 4},
        {3, 5, 6},
        {2, 4},
        {4}
    };

    cout<<isBipartite(adjL);

    return 0;
}