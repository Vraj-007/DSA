#include<bits/stdc++.h>
using namespace std;

// Space --> O(N x M) + O(N x M)
// Time --> O(N x M)

void BFS(int row, int column, vector<vector<int>> &grid, vector<vector<int>> &visited){

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> Q;

    Q.push({row, column});

    visited[row][column] = 1;

    while(!Q.empty()){

        int i = Q.front().first;
        int j = Q.front().second;

        Q.pop(); // Removing element from Queue

        for(int delrow=-1 ; delrow<=1 ; delrow++){
            for(int delcol=-1 ; delcol<=1 ; delcol++){

                int nrow = i + delrow;
                int ncol = j + delcol;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){

                    if(visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                        visited[nrow][ncol] = 1; // Marking node as visited
                        Q.push({nrow, ncol}); // Inserting unvisited node in Queue
                    }

                }

            }
        }
    }

    return;
}

int numIslands(vector<vector<int>> &grid){

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int> (m, 0));

    int count = 0;

    for(int row=0 ; row<n ; row++){
        for(int column=0 ; column<m ; column++){

            if(visited[row][column] == 0 && grid[row][column] == 1){
                count += 1;
                BFS(row, column, grid, visited); 
            }
        }
    }

    return count;
}

int main(){

    vector<vector<int>> grid{
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 1}
    };

    cout<<numIslands(grid);

    return 0;
}