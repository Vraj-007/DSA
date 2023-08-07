#include<bits/stdc++.h>
using namespace std;

int Brute(int index, vector<int> &height){

    if(index == 0)
        return 0;

    int oneStep;
    int twoStep;

    if(index-1 >= 0)
        oneStep = abs(height[index] - height[index-1]) + Brute(index-1, height);

    if(index-2 >= 0)
        twoStep = abs(height[index] - height[index-2]) + Brute(index-2, height);

    return min(oneStep, twoStep);
}

int Better(int index, vector<int> &height, vector<int> &dp){

    if(dp[index] != -1)
        return dp[index];

    if(index == 0)
        return 0;

    int oneStep;
    int twoStep;

    if(index-1 >= 0)
        oneStep = abs(height[index] - height[index-1]) + Better(index-1, height, dp);

    if(index-2 >= 0)
        twoStep = abs(height[index] - height[index-2]) + Better(index-2, height, dp);

    return dp[index] = min(oneStep, twoStep);
}

int Optimal(int n, vector<int> &height){

    vector<int> dp(n, 0);

    dp[0] = 0;

    for(int index=1 ; index<n ; index++){

        int oneStep;
        int twoStep;

        if(index-1 >= 0)
            oneStep = abs(height[index] - height[index-1]) + dp[index-1];

        if(index-2 >= 0)
            twoStep = abs(height[index] - height[index-2]) + dp[index-2];

        dp[index] = min(oneStep, twoStep);
    }

    return dp[n-1];
}

int Best(int n, vector<int> &height){

    int prev2, prev1, curr;

    prev2 = 0;
    prev1 = 0;

    for(int index=1 ; index<n ; index++){

        int oneStep;
        int twoStep;

        if(index-1 >= 0)
            oneStep = abs(height[index] - height[index-1]) + prev1;

        if(index-2 >= 0)
            twoStep = abs(height[index] - height[index-2]) + prev2;

        curr = min(oneStep, twoStep);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){

    vector<int> height = {30, 10, 60, 10, 60, 50};
    int n = height.size();


    // cout<<Brute(n-1, height);

    // vector<int> dp(n+1, -1);
    // cout<<Better(n-1, height, dp);

    // cout<<Optimal(n, height);

    cout<<Best(n, height);

    return 0;
}