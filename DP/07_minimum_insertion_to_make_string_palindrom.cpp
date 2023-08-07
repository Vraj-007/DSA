#include<bits/stdc++.h>
using namespace std;

int Brute(int index1, int index2, string &s1, string &s2){

    if(index1 == 0 || index2 == 0)
        return 0;

    if(s1[index1-1] == s2[index2-1]){
        return 1 + Brute(index1-1, index2-1, s1, s2);
    }
    else{
        int first = 0 + Brute(index1-1, index2, s1, s2);
        int second = 0 + Brute(index1, index2-1, s1, s2);

        return max(first, second);
    }
}

int Better(int index1, int index2, string &s1, string &s2, vector<vector<int>> &dp){

    if(dp[index1][index2] != -1)
        return dp[index1][index2];

    if(index1 == 0 || index2 == 0)
        return 0;

    if(s1[index1-1] == s2[index2-1]){
        return dp[index1][index2] = 1 + Better(index1-1, index2-1, s1, s2, dp);
    }
    else{
        int first = 0 + Better(index1-1, index2, s1, s2, dp);
        int second = 0 + Better(index1, index2-1, s1, s2, dp);

        return dp[index1][index2] = max(first, second);
    }
}


int Optimal(string s1, string s2){

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

    for(int index1=0 ; index1<=n ; index1++)
        dp[index1][0] = 0;


    for(int index2=0 ; index2<=m ; index2++)
        dp[0][index2] = 0;


    for(int index1=1 ; index1<=n ; index1++){
        for(int index2=1 ; index2<=m ; index2++){

            if(s1[index1-1] == s2[index2-1]){
                dp[index1][index2] = 1 + dp[index1-1][index2-1];
            }
            else{
                int first = 0 + dp[index1-1][index2];
                int second = 0 + dp[index1][index2-1];

                dp[index1][index2] = max(first, second);
            }

        }
    }

    return dp[n][m];
}


int Best(string s1, string s2){

    int n = s1.length();
    int m = s2.length();

    vector<int> dp(m+1, -1);

    for(int index2=0 ; index2<=m ; index2++)
        dp[index2] = 0;


    for(int index1=1 ; index1<=n ; index1++){

        vector<int> dummy(m+1, -1);
        dummy[0] = 0;

        for(int index2=1 ; index2<=m ; index2++){

            if(s1[index1-1] == s2[index2-1]){
                dummy[index2] = 1 + dp[index2-1];
            }
            else{
                int first = 0 + dp[index2];
                int second = 0 + dummy[index2-1];

                dummy[index2] = max(first, second);
            }
        }

        dp = dummy;

    }

    return dp[m];
}

int minInsertion(string str){

    int n = str.length();

    string rev = str;
    reverse(rev.begin(), rev.end());

    int lps = Best(str, rev);

    return n-lps;
}

int main(){

    string str = "coding ninjas";

    cout<<minInsertion(str);

    return 0;
}