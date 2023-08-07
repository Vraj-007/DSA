#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int> (m, 0));
    vector<vector<int>> distance(n, vector<int> (m, 0));
    queue<pair<pair<int, int>, int>> Q; 

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){

            if(grid[i][j] == 1){
                Q.push({{i, j}, 0});
                visited[i][j] = 1;
            }

        }
    }

    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    while(!Q.empty()){

        int row = Q.front().first.first;
        int column = Q.front().first.second;
        int dist = Q.front().second;

        Q.pop();

        distance[row][column] = dist;

        for(int i=0 ; i<=3 ; i++){

            int nRow = row + delRow[i];
            int nCol = column + delCol[i];

            if(nRow>=0 && nCol>=0 && nRow<n && nCol<m){
                if(visited[nRow][nCol] == 0){
                    visited[nRow][nCol] = 1;
                    Q.push({{nRow, nCol}, dist+1});
                }
            }

        }
    }

    return distance;
}

int main(){

    vector<vector<int>> grid{
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1}
    };

    vector<vector<int>> nearestDist = nearest(grid);

    int n = grid.size();
    int m = grid[0].size();

    for(int row=0 ; row<n ; row++){
        for(int col=0 ; col<m ; col++){
            cout<<nearestDist[row][col]<<" ";
        }
        cout<<endl;
    }

    return 0;
}