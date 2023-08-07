#include<bits/stdc++.h>
using namespace std;

// LCS

vector<vector<int>> Help(string s1, string s2){

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

    return dp;
}


string LCS(string s1, string s2){

    vector<vector<int>> dp = Help(s1, s2);

    int n = s1.length();
    int m = s2.length();

    int length = dp[n][m]; 
    
    string lcs(length, '$');

    int index = length-1;

    int i = n;
    int j = m;

    while(i>0 && j>0){

        if(s1[i-1] == s2[j-1]){
            lcs[index] = s1[i-1];
            index -= 1;
            i -= 1;
            j -= 1;
        }
        else if(dp[i-1][j] >= dp[i][j-1]){
            i -= 1;
        }
        else{
            j -= 1;
        }

    }

    return lcs;
}


int main(){

    string s1 = "abcde";
    string s2 = "bdgek";

    cout<<LCS(s1, s2);
}