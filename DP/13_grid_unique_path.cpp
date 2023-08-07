#include<bits/stdc++.h>
using namespace std;

int Brute(int row, int column, int n, int m){

    if(row == 0 && column == 0){
        return 1;
    }

    if(row < 0 || column < 0){
        return 0;
    }

    int up = Brute(row-1, column, n, m);
    int left = Brute(row, column-1, n, m);

    return up + left;
}


int Better(int row, int column, int n, int m, vector<vector<int>> &dp){

    if(dp[row][column] != -1)
        return dp[row][column];

    if(row == 0 && column == 0)
        return 1;

    if(row < 0 || column < 0)
        return 0;

    int up = Better(row-1, column, n, m, dp);
    int left = Better(row, column-1, n, m, dp);

    return dp[row][column] = up + left;
}


int Optimal(int n, int m){

    vector<vector<int>> dp(n, vector<int> (m, 0));

    dp[0][0] = 1;

    for(int row=0 ; row<n ; row++){
        for(int column=0 ; column<m ; column++){

            if(row == 0 && column == 0){
                dp[row][column] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if(row-1 >= 0)
                up = dp[row-1][column];

            if(column-1 >= 0)
                left = dp[row][column-1];

            dp[row][column] = up + left;
        }
    }

    return dp[n-1][m-1];
}


int Best(int n, int m){

    vector<int> dp(m, 0);

    dp[0] = 1;

    for(int row=0 ; row<n ; row++){

        vector<int> dummy(m, 0);

        for(int column=0 ; column<m ; column++){

            if(row == 0 && column == 0){
                dummy[column] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if(row-1 >= 0)
                up = dp[column];

            if(column-1 >= 0)
                left = dummy[column-1];

            dummy[column] = up + left;
        }

        dp = dummy;
    }

    return dp[m-1];
}


int main(){

    int n = 5;
    int m = 5;

    // cout<<Brute(n-1, m-1, n, m);

    // vector<vector<int>> dp(n, vector<int> (m, -1));
    // cout<<Better(n-1, m-1, n, m, dp);

    // cout<<Optimal(n, m);

    cout<<Best(n, m);

    return 0;
}