#include<bits/stdc++.h>
using namespace std;

int Brute(int n){

    if(n<=1)
        return n;

    return Brute(n-1) + Brute(n-2);
}

int Better(int n, vector<int> &dp){

    if(dp[n] != -1)
        return dp[n];

    if(n<=1)
        return n;

    return dp[n] = Better(n-1, dp) + Better(n-2, dp);
}

int Optimal(int n){

    vector<int> dp(n+1, 0);

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2 ; i<=n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int Best(int n){

    int prev2 = 0;
    int prev1 = 1;

    for(int i=2 ; i<=n ; i++){
        int curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){

    int n = 5;

    // cout<<Brute(n);

    // vector<int> dp(n+1, -1);
    // cout<<Better(n, dp);

    // cout<<Optimal(n);

    cout<<Best(n);
    
    return 0;
}