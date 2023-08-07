#include<bits/stdc++.h>
using namespace std;

int Brute(int index, int L, vector<int> &price){

    if(index == 0){
        return L*price[0];
    }

    int notTake = 0 + Brute(index, L, price);

    int take = INT_MIN;
    int rodlength = index+1;

    if(rodlength <= L)
        take = price[index] + Brute(index, L-rodlength, price);
    
    return max(take, notTake);
}


int Better(int index, int L, vector<int> &price, vector<vector<int>> &dp){

    if(dp[index][L] != -1)
        return dp[index][L];

    if(index == 0){
        return L*price[0];
    }

    int notTake = 0 + Better(index-1, L, price, dp);

    int take = INT_MIN;
    int rodlength = index+1;

    if(rodlength <= L)
        take = price[index] + Better(index, L-rodlength, price, dp);
    
    return dp[index][L] = max(take, notTake);
}


int Optimal(int L, vector<int> &price){

    int n = price.size();

    vector<vector<int>> dp(n, vector<int> (L+1, 0));

    for(int l=0 ; l<=L ; l++){
        dp[0][l] = l*price[0];
    }

    for(int index=1 ; index<n ; index++){
        for(int l=0 ; l<=L ; l++){

            int notTake = 0 + dp[index-1][l];

            int take = INT_MIN;
            int rodlength = index+1;

            if(rodlength <= l)
                take = price[index] + dp[index][l-rodlength];
            
            dp[index][l] = max(take, notTake);
        }
    }

    return dp[n-1][L];
}


int Best(int L, vector<int> &price){

    int n = price.size();

    vector<int> dp(L+1, 0);

    for(int l=0 ; l<=L ; l++){
        dp[l] = l*price[0];
    }

    for(int index=1 ; index<n ; index++){

        vector<int> dummy(L+1, 0);

        for(int l=0 ; l<=L ; l++){

            int notTake = 0 + dp[l];

            int take = INT_MIN;
            int rodlength = index+1;

            if(rodlength <= l)
                take = price[index] + dummy[l-rodlength];
            
            dummy[l] = max(take, notTake);
        }

        dp = dummy;

    }

    return dp[L];
}