#include<bits/stdc++.h>
using namespace std;

// Space --> O(N) + O(N) + O(N)
// Time --> O(N) + O(2E)

void help(int node, vector<vector<int>> &adjL, vector<int> &visited, vector<int> &nums){

    visited[node] = 1;      // Marking unvisited node as visited

    nums.push_back(node);

    for(auto neighbour : adjL[node]){

        if(visited[neighbour] == 0)
            help(neighbour, adjL, visited, nums);
        
    }

    return;
}

vector<int> DFS(vector<vector<int>> &adjL, int startNode){
    
    vector<int> nums;

    vector<int> visited(adjL.size(), 0);
    visited[0] = 1;

    help(startNode, adjL, visited, nums);

    return nums;
}

int main(){

    vector<vector<int>> adjL {
        {},
        {2, 3},
        {1, 5, 6},
        {1, 4, 7},
        {3, 8},
        {2},
        {2},
        {3, 8},
        {4, 7}
    };

    int startNode = 1;

    vector<int> nums = DFS(adjL, startNode);

    for(auto node : nums){
        cout<<node<<" ";
    }

    return 0;
}