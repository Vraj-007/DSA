#include<bits/stdc++.h>
using namespace std;

// Space --> O(N) + O(N)
// Time --> O(N) + O(N + 2E)

vector<int> BFS(vector<vector<int>> &adjL, int startNode, vector<int> &visited){
    
    vector<int> nums;

    queue<int> Q;

    Q.push(startNode);

    visited[startNode] = 1;

    while(!Q.empty()){

        int node = Q.front();
        nums.push_back(node);

        Q.pop(); // Removing element from Queue

        for(auto neighbour : adjL[node]){

            if(visited[neighbour] == 0){
                Q.push(neighbour); // Inserting unvisited node in Queue
                visited[neighbour] = 1; // Marking node as visited
            }

        }
    }

    return nums;
}

int numProvinces(vector<vector<int>> &adjL){

    vector<vector<int>> provinces;

    vector<int> visited(adjL.size(), 0);
    visited[0] = 1;

    for(int i=1 ; i<visited.size() ; i++){

        if(visited[i] == 0)
            provinces.push_back(BFS(adjL, i, visited));

    }

    return provinces.size();
}

int main(){
    
    vector<vector<int>> adjL {
        {},
        {2},
        {1, 3},
        {2},
        {5},
        {4, 6},
        {5},
        {8},
        {7}
    };

    cout<<numProvinces(adjL);

    return 0;
}