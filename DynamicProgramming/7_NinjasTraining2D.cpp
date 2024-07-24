#include<bits/stdc++.h>
using namespace std;
#define ll long long


int SolveUsingRec(int day,int lastTask,vector<vector<int>>&points){
    // base case:
    if(day == 0){
        int maxi = 0;
        for(int i = 0;i<3;i++){
            if(i != lastTask){
                maxi = max(maxi,points[day][i]);
            }
        }
        return maxi;
    }
    
    int maxi = 0;
    for(int i = 0;i<3;i++){
        if(i != lastTask){
            int point = points[day][i] + SolveUsingRec(day-1,i,points);
            maxi = max(maxi,point);
        }
    }
    return maxi;
}

int solveUsingMem(int day,int lastTask,vector<vector<int>>&points,vector<vector<int>>&dp){
    // base case:
    if(day == 0){
        int maxi = 0;
        for(int i = 0;i<3;i++){
            if(i != lastTask){
                maxi = max(maxi,points[day][i]);
            }
        }
        return maxi;
    }
    if(dp[day][lastTask] != -1){
        return dp[day][lastTask];
    }
    int maxi = 0;
    for(int task = 0;task<3;task++){
        if(task != lastTask){
            int point = points[day][task] + solveUsingMem(day-1,task,points,dp);
            maxi = max(maxi,point);
        }
    }
    dp[day][lastTask] = maxi;
    return maxi;
}

int solveUsingTab(int n,vector<vector<int>>&points){
    // create a dp array:
    vector<vector<int>>dp(n,vector<int>(4,0));
    
    //
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] =  max(points[0][0],points[0][2]);
    dp[0][2] =  max(points[0][1],points[0][0]);
    dp[0][3] =  max(points[0][0], max(points[0][1],points[0][2]));

    for(int day = 1;day < n;day++){
        for(int last = 0;last < 4;last++){
            // int maxi = 0;/
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
               if(task != last ){
                    // int point = points[day][task] + dp[day-1][task]; 
                    // dp[day][last] = max(dp[day][last],point);
                    dp[day][last] = max(dp[day][last],(points[day][task] + dp[day-1][task]));


               } 
            }
            // dp[day][last] = maxi;

        }
    }
    return dp[n-1][3];

}

int spaceOpt(int n, vector<vector<int>> &points){
    vector<int>prev(4,0);
    //
    prev[0] = max(points[0][1],points[0][2]);
    prev[1] =  max(points[0][0],points[0][2]);
    prev[2] =  max(points[0][1],points[0][0]);
    prev[3] =  max(points[0][0], max(points[0][1],points[0][2]));

    for(int day = 1;day < n;day++){
        vector<int>curr(4,0);
        for(int last = 0;last < 4;last++){
            curr[last] = 0;
            for (int task = 0; task < 3; task++)
            {
               if(task != last ){
                    curr[last] = max(curr[last],points[day][task] + prev[task]);
               } 
            }
        }
        prev = curr;
    }
    return prev[3];

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    // // return SolveUsingRec(n-1,3,points);
    // vector<vector<int>>dp(n,vector<int>(4,-1));
    // return solveUsingMem(n-1,3,points,dp);

    // return solveUsingTab(n,points);
    return spaceOpt(n,points);
}

int main()
{

 return 0;
}