#include<bits/stdc++.h>
using namespace std;

int Brute(int index, int W, vector<int> &weight, vector<int> &value){

    if(index == 0){
        return (W/weight[0])*value[0];
    }

    int notTake = 0 + Brute(index-1, W, weight, value);

    int take = INT_MIN;

    if(weight[index] <= W)
        take = value[index] + Brute(index, W-weight[index], weight, value);

    return max(take, notTake);
}


int Better(int index, int W, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp){

    if(dp[index][W] != -1)
        return dp[index][W];

    if(index == 0){
        return (W/weight[0])*value[0];
    }

    int notTake = 0 + Better(index-1, W, weight, value, dp);

    int take = INT_MIN;

    if(weight[index] <= W)
        take = value[index] + Better(index, W-weight[index], weight, value, dp);

    return dp[index][W] = max(take, notTake);
}


int Optimal(vector<int> &weight, vector<int> &value, int W){

    int n = weight.size();

    vector<vector<int>> dp(n, vector<int> (W+1, 0));

    for(int w=0 ; w<=W ; w++){
        dp[0][w] = (w/weight[0])*value[0];
    }

    for(int index=1 ; index<n ; index++){
        for(int w=0 ; w<=W ; w++){

            int notTake = 0 + dp[index-1][w];

            int take = INT_MIN;

            if(weight[index] <= w)
                take = value[index] + dp[index][w-weight[index]];

            dp[index][w] = max(take, notTake);
        }
    }

    return dp[n-1][W];
}


int Best(vector<int> &weight, vector<int> &value, int W){

    int n = weight.size();

    vector<int> dp(W+1, 0);

    for(int w=0 ; w<=W ; w++){
        dp[w] = (w/weight[0])*value[0];
    }

    for(int index=1 ; index<n ; index++){

        vector<int> dummy(W+1, 0);

        for(int w=0 ; w<=W ; w++){

            int notTake = 0 + dp[w];

            int take = INT_MIN;

            if(weight[index] <= w)
                take = value[index] + dummy[w-weight[index]];

            dummy[w] = max(take, notTake);
        }

        dp = dummy;
    }

    return dp[W];
}