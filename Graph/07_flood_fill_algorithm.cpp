#include<bits/stdc++.h>
using namespace std;

// Using DFS

// Time --> O(N x M)
// Space --> O(N x M)

void printArray(vector<vector<int>> &nums){

    cout<<endl;

    int n = nums.size();
    int m = nums[0].size();

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    return;
}

void floodFill(vector<vector<int>> &imgArray, int sr, int sc, int newcolour, int oldcolour){

    imgArray[sr][sc] = newcolour;

    int n = imgArray.size();
    int m = imgArray[0].size();

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    for(int i=0 ; i<=3 ; i++){

        int nRow = sr + delRow[i];
        int nCol = sc + delCol[i];

        if(nRow>=0 && nRow<n && nCol>=0 && nCol<m){

            if(imgArray[nRow][nCol] == oldcolour && imgArray[nRow][nCol] != newcolour)
                floodFill(imgArray, nRow, nCol, newcolour, oldcolour);
                
        }
    }

    return;
}


int main(){

    vector<vector<int>> imgArray{
        {1, 1, 1},
        {2, 2, 0},
        {2, 2, 2}
    };

    int sr = 0;
    int sc = 0;

    int oldcolour = imgArray[sr][sc];
    int newcolour = 3;

    floodFill(imgArray, sr, sc, newcolour, oldcolour);

    printArray(imgArray);

    return 0;
}