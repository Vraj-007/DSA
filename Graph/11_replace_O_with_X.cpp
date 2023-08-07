#include<bits/stdc++.h>
using namespace std;

void DFS(int row, int column, vector<vector<char>> &mat, vector<vector<int>> &visited){

    visited[row][column] = 1;
    int n = mat.size();
    int m = mat[0].size();

    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    // Check for top, right, bottom, left
    for(int i=0 ; i<=3 ;i++){

        int nRow = row + delRow[i];
        int nCol = column + delCol[i];

        if(nRow>=0 && nRow<n && nCol>=0 && nCol<m){
            if(visited[nRow][nCol] == 0 && mat[nRow][nCol] == 'O'){
                DFS(nRow, nCol, mat, visited);
            }
        }
    }
}

vector<vector<char>> fill(vector<vector<char>> &mat){
    
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> visited(n, vector<int> (m, 0));

    for(int i=0 ; i<m ; i++){
        // First Row
        if(visited[0][i] == 0 && mat[0][i] == 'O'){
            DFS(0, i, mat, visited);
        }

        // Last Row
        if(visited[n-1][i] == 0  && mat[n-1][i] == 'O'){
            DFS(n-1, i, mat, visited);
        }
    }

    for(int i=0 ; i<n ; i++){
        // First Column
        if(visited[i][0] == 0 && mat[i][0] == 'O'){
            DFS(i, 0, mat, visited);
        }

        // Last Column
        if(visited[i][m-1] == 0 && mat[i][m-1] == 'O'){
            DFS(i, m-1, mat, visited);
        }
    }

    for(int row=0 ; row<n ; row++){
        for(int column=0 ; column<m ; column++){
            if(visited[row][column] == 0 && mat[row][column] == 'O'){
                mat[row][column] = 'X';
            }
        }
    }

    return mat;
}

int main(){

    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}
    };

    vector<vector<char>> newMat = fill(mat);

    int n = mat.size();
    int m = mat[0].size();

    for(int row=0 ; row<n ; row++){
        for(int col=0 ; col<m ; col++){
            cout<<newMat[row][col]<<" ";
        }
        cout<<endl;
    }

    return 0;
}