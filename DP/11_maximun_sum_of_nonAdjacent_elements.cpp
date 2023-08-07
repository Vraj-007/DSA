#include<bits/stdc++.h>
using namespace std;


int Brute(int index, vector<int> &nums){

    if(index < 0)
        return 0;

    if(index == 0)
        return nums[0];

    int pick = nums[index] + Brute(index-2, nums);

    int notPick = 0 + Brute(index-1, nums);

    return max(pick, notPick); 
}


int Better(int index, vector<int> &nums, vector<int> &dp){

    if(dp[index] != -1)
        return dp[index];

    if(index < 0)
        return 0;
    
    if(index == 0)
        return dp[index] = nums[0];

    int pick = nums[index] + Better(index-2, nums, dp);

    int notPick = 0 + Better(index-1, nums, dp);

    return dp[index] = max(pick, notPick);
}


int Optimal(vector<int> &nums){

    int n = nums.size();

    vector<int> dp(n, 0);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int index=2 ; index<=n ; index++){

        int pick = nums[index] + dp[index-2];

        int notPick = 0 + dp[index-1];

        dp[index] = max(pick, notPick);
    }

    return dp[n-1];
}


int Best(vector<int> &nums){

    int n = nums.size();

    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);

    for(int index=2 ; index<=n ; index++){

        int pick = nums[index] + prev2;

        int notPick = 0 + prev1;

        int curr = max(pick, notPick);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;    
}

int main(){

    vector<int> nums = {2, 1, 4, 9};
    int n = nums.size();

    // cout<<Brute(n-1, nums);

    // vector<int> dp(n, -1);
    // cout<<Better(n-1, nums, dp);

    cout<<Optimal(nums);

    return 0;
}