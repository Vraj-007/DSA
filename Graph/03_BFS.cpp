#include<bits/stdc++.h>
using namespace std;

// Level Order Traversal

// Space --> O(3N)
// Time --> O(N) + O(2E)

vector<int> BFS(vector<vector<int>> &adjL, int startNode){
    
    vector<int> nums;

    vector<int> visited(adjL.size(), 0);
    visited[0] = 1;

    queue<int> Q;

    // Inserting starting node in queue
    Q.push(startNode);

    // starting node marked as visited
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

int main(){

    vector<vector<int>> adjL {
        {},
        {2, 6},
        {1, 3, 4},
        {2},
        {2, 5},
        {4, 8},
        {1, 7, 9},
        {6, 8},
        {5, 7},
        {6}
    };

    int startNode = 1;

    vector<int> nums = BFS(adjL, startNode);

    for(auto node : nums){
        cout<<node<<" ";
    }

    return 0;
}