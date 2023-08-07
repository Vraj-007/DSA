#include<bits/stdc++.h>
using namespace std;

int Brute(int index, vector<int> &height, int k){

    if(index == 0)
        return 0;

    int minJump = INT_MAX;

    for(int step=1 ; step<=k ; step++){

        int jump;
        
        if(index-step >= 0)
            jump = abs(height[index] - height[index-step]) + Brute(index-step, height, k);

        minJump = min(minJump, jump);
    }

    return minJump;
}


int Better(int index, vector<int> &height, int k, vector<int> &dp){

    if(dp[index] != -1)
        return dp[index];

    if(index == 0)
        return 0;

    int minJump = INT_MAX;

    for(int step=1 ; step<=k ; step++){

        int jump;
        
        if(index-step >= 0)
            jump = abs(height[index] - height[index-step]) + Better(index-step, height, k, dp);

        minJump = min(minJump, jump);
    }

    return dp[index] = minJump;
}


int Optimal(vector<int> &height, int k){

    int n = height.size();

    vector<int> dp(n, 0);

    dp[0] = 0;

    for(int index=1 ; index<n ; index++){

        int minJump = INT_MAX;

        for(int step=1 ; step<=k ; step++){

            int jump;
            
            if(index-step >= 0)
                jump = abs(height[index] - height[index-step]) + dp[index-step];

            minJump = min(minJump, jump);
        }

        dp[index] = minJump;
    }

    return dp[n-1];
}

int main(){

    vector<int> height = {30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 3;

    // cout<<Brute(n-1, height, k);

    // vector<int> dp(n, -1);
    // cout<<Better(n-1, height, k, dp);

    cout<<Optimal(height, k);

    return 0;
}