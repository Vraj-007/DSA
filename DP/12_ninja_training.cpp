#include<bits/stdc++.h>
using namespace std;

int Brute(int day, int last, vector<vector<int>> &points){

    if(day == 0){
        int max_points = 0;

        for(int task=0 ; task<3 ; task++){
            if(task != last){
                max_points = max(max_points, points[day][task]);
            }
        }
        return max_points;
    }

    int max_points = 0;

    for(int task=0 ; task<3 ; task++){
        if(task != last){
            int point = points[day][task] + Brute(day-1, task, points);
            max_points = max(max_points, point);
        }
    }

    return max_points; 
}


int Better(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){

    if(dp[day][last] != -1){
        return dp[day][last];
    }

    if(day == 0){
        int max_points = 0;
        for(int task=0 ; task<3 ; task++){
            if(task != last){
                max_points = max(max_points, points[day][task]);
            }
        }
        return max_points;
    }

    int max_points = 0;

    for(int task=0 ; task<3 ; task++){
        if(task != last){
            int point = points[day][task] + Better(day-1, task, points, dp);
            max_points = max(max_points, point);
        }
    }

    return dp[day][last] = max_points;
}

int Optimal(vector<vector<int>> &points){

    int n = points.size();

    vector<vector<int>> dp(n, vector<int> (4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], dp[0][0]);

    for(int day=1 ; day<n ; day++){
        for(int last=0 ; last<4 ; last++){

            int max_points = 0;

            for(int task=0 ; task<3 ; task++){
                if(task != last){
                    int point = points[day][task] + dp[day-1][task];
                    max_points = max(max_points, point);
                }
            }

            dp[day][last] = max_points;
        }
    }

    return dp[n-1][3];
}

int Best(vector<vector<int>> &points){

    int n = points.size();

    vector<int> dp(4, 0);

    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][0], dp[0]);

    for(int day=1 ; day<n ; day++){

        vector<int> dummy(4, 0);

        for(int last=0 ; last<4 ; last++){

            int max_points = 0;

            for(int task=0 ; task<3 ; task++){
                if(task != last){
                    int point = points[day][task] + dp[task];
                    max_points = max(max_points, point);
                }
            }

            dummy[last] = max_points;
        }

        dp = dummy;
    }

    return dp[3];
}

int main(){

    vector<vector<int>> points{
        {2, 1, 3},
        {3, 4, 6},
        {10, 1, 6},
        {8, 3, 7}
    };

    int n = points.size();

    // cout<<Brute(n-1, 3, points);

    // vector<vector<int>> dp(n+1, vector<int> (4, -1));
    // cout<<Better(n-1, 3, points, dp);

    // cout<<Optimal(points);

    cout<<Best(points);

    return 0;
}