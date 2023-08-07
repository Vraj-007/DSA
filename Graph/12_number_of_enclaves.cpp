#include<bits/stdc++.h>
using namespace std;

int numberOfEnclaves(vector<vector<int>> &grid){
    
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int> (m, 0));
    queue<pair<int, int>> Q;

    for(int i=0 ; i<m ; i++){
        // First Row
        if(visited[0][i] == 0 && grid[0][i] == 1){
            Q.push({0, i});
            visited[0][i] = 1;
        }

        // Last Row
        if(visited[n-1][i] == 0  && grid[n-1][i] == 1){
            Q.push({n-1, i});
            visited[n-1][i] = 1;
        }
    }

    for(int i=0 ; i<n ; i++){
        // First Column
        if(visited[i][0] == 0 && grid[i][0] == 1){
            Q.push({i, 0});
            visited[i][0] = 1;
        }

        // Last Column
        if(visited[i][m-1] == 0 && grid[i][m-1] == 1){
            Q.push({i, m-1});
            visited[i][m-1] = 1;
        }
    }

    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    while(!Q.empty()){

        int row = Q.front().first;
        int column = Q.front().second;
        Q.pop();

        // Check for top, right, bottom, left
        for(int i=0 ; i<=3 ;i++){

            int nRow = row + delRow[i];
            int nCol = column + delCol[i];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m){
                if(visited[nRow][nCol] == 0 && grid[nRow][nCol] == 1){
                    Q.push({nRow, nCol});
                    visited[nRow][nCol] = 1;
                }
            }

        }
    }

    int count = 0;

    for(int row=0 ; row<n ; row++){
        for(int column=0 ; column<m ; column++){
            if(visited[row][column] == 0 && grid[row][column] == 1){
                count += 1;
            }
        }
    }

    return count;
}

int main(){

    // vector<vector<int>> grid{
    //     {0, 0, 0, 1},
    //     {0, 1, 1, 0},
    //     {0, 1, 1, 0},
    //     {0, 0, 0, 1},
    //     {0, 1, 1, 0}
    // };

    vector<vector<int>> grid{
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1}
    };

    cout<<numberOfEnclaves(grid);

    return 0;
}