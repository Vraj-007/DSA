#include<bits/stdc++.h>
using namespace std;


int Optimal(string s1, string s2){

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int index1=0 ; index1<=n ; index1++)
        dp[index1][0] = 0;

    for(int index2=0 ; index2<=n ; index2++)
        dp[0][index2] = 0;

    int length = 0;

    for(int index1=1 ; index1<=n ; index1++){
        for(int index2=1 ; index2<=m ; index2++){

            if(s1[index1-1] == s2[index2-1]){

                dp[index1][index2] = 1 + dp[index1-1][index2-1];
                length = max(length, dp[index1][index2]);

            }
            else{
                dp[index1][index2] = 0;
            }
        }
    }

    return length;
}


int Best(string s1, string s2){

    int n = s1.length();
    int m = s2.length();

    vector<int> dp(m+1, -1);

    for(int index2=0 ; index2<=n ; index2++)
        dp[index2] = 0;

    int length = 0;

    for(int index1=1 ; index1<=n ; index1++){

        vector<int> dummy(m+1, -1);
        dummy[0] = 0;

        for(int index2=1 ; index2<=m ; index2++){

            if(s1[index1-1] == s2[index2-1]){

                dummy[index2] = 1 + dp[index2-1];
                length = max(length, dummy[index2]);

            }
            else{
                dummy[index2] = 0;
            }
        }

        dp = dummy;

    }

    return length;
}


int main(){

    string s1 = "abcd";
    string s2 = "abzd";

    cout<<Optimal(s1, s2);

    return 0;
}